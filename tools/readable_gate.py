#!/usr/bin/env python3
"""The gate every readability edit must pass before it is committed.

A readability edit changes names and comments only. This script compares each edited source in the
working tree with its committed version and refuses anything that could change what the file
compiles to or how well the judge can check it.

    readable_gate.py check            report PASS / FAIL for every edited source
    readable_gate.py revert           check, then `git checkout` the files that FAIL (their edit is lost)
    readable_gate.py commit "MESSAGE" check, revert the FAILs, commit the PASSes (nothing else is staged)

Per file, all of these must hold (the first FAIL is reported):
  newfile     the file is tracked: a new source is not a readability edit
  endings     LF line endings only
  marker      a first line `/* compiler: ... */` is still the first line
  literals    the strings and numbers of the code (comments removed) are the same list as before
  protected   every func_XXXXXXXX / D_XXXXXXXX name, every extern-declared name and every name used
              by the file's own definition is unchanged (renaming a callee or global weakens the judge's
              address check; renaming the function breaks the layout tools)
  object      the file compiles to an object identical to the committed version's (every section,
              relocation and symbol: tools/tidy.py same_object)
  judge       tools/match.py still says MATCH, including the check of the file's own constants
  policy      tools/asm_policy.py is clean
and for the whole tree: tools/organize.py --check reports nothing to rename or move.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
sys.path.insert(0, os.path.join(ROOT, "tools"))

COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)
STRING = re.compile(r'"(?:[^"\\\n]|\\.)*"|\'(?:[^\'\\\n]|\\.)*\'')
NUMBER = re.compile(r"\b(?:0[xX][0-9A-Fa-f]+|\d+\.?\d*(?:[eE][-+]?\d+)?[fFuUlL]*)\b")
PROTECTED = re.compile(r"\b(?:func|D)_[0-9A-Fa-f]{6,8}\b")
EXTERN_DECL = re.compile(r"^\s*extern\b[^;{]*?([A-Za-z_]\w*)\s*(?:\(|\[|;)", re.M)


def git(*args):
    return subprocess.run(["git"] + list(args), capture_output=True, text=True, encoding="utf-8", errors="replace").stdout


def strip_comments(text):
    """Comments out, strings kept (a comment marker inside a string is not a comment)."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if c == '"' or c == "'":
            m = STRING.match(text, i)
            if m:
                out.append(m.group(0)); i = m.end(); continue
        if text.startswith("/*", i):
            j = text.find("*/", i + 2)
            i = n if j < 0 else j + 2
            out.append(" "); continue
        if text.startswith("//", i):
            j = text.find("\n", i)
            i = n if j < 0 else j
            continue
        out.append(c); i += 1
    return "".join(out)


def literals(code):
    strings = STRING.findall(code)
    rest = STRING.sub(" ", code)
    return sorted(strings), sorted(NUMBER.findall(rest))


def protected_names(code):
    names = set(PROTECTED.findall(code))
    names |= {m.group(1) for m in EXTERN_DECL.finditer(code)}
    return names


def static_checks(path, old, new):
    if b"\r" in new.encode("utf-8", "replace"):
        return "endings", "CR characters found: LF only"
    om = re.match(r"/\* compiler:[^\n]*\*/", old)
    if om and not new.startswith(om.group(0)):
        return "marker", "the `/* compiler: ... */` first line was changed or moved"
    oc, nc = strip_comments(old), strip_comments(new)
    ol, nl = literals(oc), literals(nc)
    if ol != nl:
        for kind, a, b in (("string", ol[0], nl[0]), ("number", ol[1], nl[1])):
            if a != b:
                gone = sorted(set(a) - set(b))[:3]
                new_ = sorted(set(b) - set(a))[:3]
                return "literals", f"{kind} literals differ: gone {gone}, new {new_}"
    op, np_ = protected_names(oc), protected_names(nc)
    if op != np_:
        return "protected", f"protected names differ: gone {sorted(op - np_)[:4]}, new {sorted(np_ - op)[:4]}"
    return None


def main(argv):
    if not argv or argv[0] not in ("check", "revert", "commit"):
        print(__doc__)
        return 2
    cmd = argv[0]
    import asm_policy
    import match
    import project
    import tidy
    changed = [p for p in git("diff", "--name-only", "HEAD", "--", "src").split() if p.endswith((".c", ".cpp"))]
    untracked = [p for p in git("ls-files", "--others", "--exclude-standard", "src").split()]
    results = {}
    for p in untracked:
        results[p] = ("newfile", "new source files are not readability edits: move it out of src/")
    srcs = project.sources(refresh=True)
    byrel = {os.path.relpath(str(v), ROOT).replace(os.sep, "/"): a for a, v in srcs.items()}
    pending = []
    for p in changed:
        old = git("show", "HEAD:" + p)
        new = open(p, encoding="utf-8", errors="replace", newline="").read()
        bad = static_checks(p, old, new)
        if bad:
            results[p] = bad
        elif p not in byrel:
            results[p] = ("judge", "no function address maps to this file")
        else:
            pending.append(p)
    if pending:
        D = os.path.join(ROOT, "build", "gate")
        os.makedirs(D, exist_ok=True)
        olds = []
        for i, p in enumerate(pending):
            o = os.path.join(D, f"old{i}_" + os.path.basename(p))
            open(o, "w", encoding="utf-8", newline="").write(git("show", "HEAD:" + p))
            olds.append(o)
        objs = match.compile_many(pending + olds, 3)
        for p, o in zip(pending, olds):
            a, b = objs.get(p), objs.get(o)
            why = "compile failed" if not (a and b) else tidy.same_object(a, b)
            if why:
                results[p] = ("object", why)
        good = [p for p in pending if p not in results]
        for addr, s, ok, rep in match.judge_many([(byrel[p], p) for p in good], jobs=3, chunk=40):
            if not ok:
                results[s] = ("judge", rep.splitlines()[0][:160])
        for p in good:
            if p not in results:
                v = asm_policy.violations(open(p, encoding="utf-8").read(), byrel[p])
                if v:
                    results[p] = ("policy", "; ".join(v)[:160])
    # tree-wide: organize must have nothing to rename or move
    org = subprocess.run([sys.executable, os.path.join("tools", "organize.py"), "--check"], capture_output=True, text=True, encoding="utf-8", errors="replace")
    for line in org.stdout.splitlines():
        m = re.match(r"(?:rename symbols in|move|rename)\s+(\S+)", line)
        if m:
            f = m.group(1).replace("\\", "/")
            if f in changed and f not in results:
                results[f] = ("organize", "organize.py --check wants to rename symbols here: a comment or name collides with a known symbol; reword it")
    failed = {p: r for p, r in results.items()}
    passed = [p for p in changed if p not in failed]
    for p in sorted(failed):
        print(f"FAIL  {p}  [{failed[p][0]}] {failed[p][1]}")
    print(f"{len(passed)} PASS, {len(failed)} FAIL of {len(changed)} edited sources" + (f" and {len(untracked)} untracked" if untracked else ""))
    if cmd == "check":
        return 0 if not failed else 1
    for p in sorted(failed):
        if p in changed:
            subprocess.run(["git", "checkout", "--", p])
            print("reverted", p)
    if cmd == "commit":
        if not passed:
            print("nothing to commit")
            return 1
        msg = argv[1] if len(argv) > 1 else "Make sources readable"
        subprocess.run(["git", "add", "--"] + passed, check=True)
        subprocess.run(["git", "commit", "-q", "-m", msg], check=True)
        print("committed", len(passed), "files:", git("log", "--oneline", "-1").strip())
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
