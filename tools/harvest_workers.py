#!/usr/bin/env python3
"""Bring the matches that worker worktrees left behind into this checkout, and say who has gone quiet.

Free-model workers (and any agent with its own git worktree) save a MATCH as an untracked
src/func_XXXXXXXX.c* in their worktree. This tool does by machine what the lead used to do by hand:
copy each new source here, judge it again here, check the asm policy, put it in its unit directory
(tools/organize.py) and commit the lot. A source that fails any step is left out and reported.

    harvest_workers.py status WORKTREE...          age of each worker's last OUTBOX line and its new sources
    harvest_workers.py harvest [--commit] WORKTREE...
                                                   judge and place the new sources; --commit commits them

The full build is still the proof: run tools/build.py before publishing what this brings in.
"""
import argparse
import os
import re
import shutil
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
sys.path.insert(0, os.path.join(ROOT, "tools"))

NAME = re.compile(r"func_([0-9A-Fa-f]{8})\.(?:c|cpp)$")


def git(*args, cwd=None):
    return subprocess.run(["git"] + list(args), cwd=cwd, capture_output=True, text=True,
                          encoding="utf-8", errors="replace").stdout


def new_sources(worktree):
    """(address, path) of the untracked func_ADDR sources in a worktree's src/."""
    found = []
    for rel in git("ls-files", "--others", "--exclude-standard", "src", cwd=worktree).split():
        m = NAME.search(rel)
        if m:
            found.append((int(m.group(1), 16), os.path.join(worktree, rel)))
    return found


def last_outbox(worktree):
    path = os.path.join(worktree, "build", "near", "OUTBOX.md")
    if not os.path.exists(path):
        return None, ""
    lines = [l for l in open(path, encoding="utf-8", errors="replace").read().splitlines() if l.strip()]
    return os.path.getmtime(path), (lines[-1][:160] if lines else "")


def status(worktrees):
    import project
    have = set(project.sources(refresh=True))
    for w in worktrees:
        mtime, line = last_outbox(w)
        age = "no OUTBOX" if mtime is None else f"{(time.time() - mtime) / 3600:.1f} h since the last OUTBOX write"
        fresh = [f"{a:08x}" for a, _ in new_sources(w) if a not in have]
        print(f"{os.path.basename(w)}: {age}; new sources here: {', '.join(fresh) or 'none'}")
        if line:
            print(f"    last line: {line}")


def harvest(worktrees, commit):
    import asm_policy
    import match
    import project
    have = set(project.sources(refresh=True))
    todo, seen = [], set()
    for w in worktrees:
        for addr, path in new_sources(w):
            if addr in have or addr in seen:
                continue
            seen.add(addr)
            dst = os.path.join(ROOT, "src", os.path.basename(path))
            if os.path.exists(dst):
                continue
            shutil.copyfile(path, dst)
            todo.append((addr, dst, os.path.basename(w)))
    if not todo:
        print("nothing new to harvest")
        return 0
    kept, dropped = [], []
    for addr, src, ok, rep in match.judge_many([(a, s) for a, s, _ in todo], jobs=2, chunk=20):
        who = next(w for a, s, w in todo if s == src)
        text = open(src, encoding="utf-8", errors="replace").read()
        bad = None if ok else rep.splitlines()[0][:100]
        if ok:
            v = asm_policy.violations(text, addr)
            bad = "; ".join(v)[:100] if v else None
        if bad:
            dropped.append((addr, bad))
            os.remove(src)
        else:
            kept.append((addr, who, bool(re.match(r"\s*(?:/\*\s*compiler:[^\n]*\*/\s*)?/\*", text))))
    for addr, why in dropped:
        print(f"dropped {addr:08x}: {why}")
    if not kept:
        return 1
    subprocess.run([sys.executable, os.path.join("tools", "organize.py")], capture_output=True)
    chk = subprocess.run([sys.executable, os.path.join("tools", "organize.py"), "--check"], capture_output=True, text=True).stdout
    for addr, who, header in kept:
        print(f"kept {addr:08x} from {who}" + ("" if header else "  (no header comment: add one before publishing)"))
    if commit:
        files = [p for p in git("ls-files", "--others", "--exclude-standard", "src").split()]
        subprocess.run(["git", "add", "--"] + files, check=True)
        names = ", ".join(f"{a:08x}" for a, _, _ in kept)
        msg = (f"Match {len(kept)} functions from worker worktrees ({names})\n\n"
               "Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>")
        subprocess.run(["git", "commit", "-q", "-m", msg], check=True)
        print("committed", git("log", "--oneline", "-1").strip())
    if chk.strip():
        print("organize --check still reports:", chk.strip().splitlines()[0])
    return 0


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["status", "harvest"])
    ap.add_argument("--commit", action="store_true")
    ap.add_argument("worktrees", nargs="+")
    a = ap.parse_args(argv)
    if a.cmd == "status":
        status(a.worktrees)
        return 0
    return harvest(a.worktrees, a.commit)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
