#!/usr/bin/env python3
"""Mechanical readability rewrites for matched sources, on the CPU only. A rewrite is kept only
where the judge (tools/match.py judge_many, the same as `match.py check`) still says MATCH.

    tidy.py run [FILES...] [--rules types,vtable] [--max N] [--jobs 2] [--apply] [--out DIR]
        without --apply the rewritten text goes to --out (default build/lead/tidy) and src/ is not
        touched; with --apply a rewrite that matches replaces the source.
    tidy.py show FILE [--rules ...]    print the diff a file would get

Rules (each is a pure text rewrite; none renames anything or needs knowledge of the game):
    types   the sized-type typedefs pasted at the top of a file -> #include "types.h"
    vtable  (VEntry *)((char *)obj->vtbl + 0xN)  ->  &obj->vtbl[N / 8]   (a vtable entry is 8 bytes)
"""
import difflib
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

STD = {"s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64"}
TYPEDEF = re.compile(r"^typedef\s+[A-Za-z_ ]+?\s+(\w+);[ \t]*\n", re.M)
OBJ = r"(?:\(\([\w ]+\*\)\w+\)|[\w]+(?:(?:->|\.)\w+)*)"
VCAST = re.compile(r"\((?P<t>\w*VEntry\w*)\s*\*\)\(\(char\s*\*\)(?P<o>" + OBJ + r")->vtbl\s*\+\s*(?P<n>0x[0-9A-Fa-f]+|\d+)\)")


def rule_types(src):
    """Drop the pasted sized-type typedefs and include types.h, when every name a source pastes is
    one of types.h's (the judge decides whether the widths agree)."""
    head = []
    pos = 0
    for m in TYPEDEF.finditer(src):
        if m.start() != pos:
            break
        head.append(m)
        pos = m.end()
    if not head or not all(m.group(1) in STD for m in head):
        return src
    return '#include "types.h"\n' + src[pos:]


def rule_vtable(src):
    def sub(m):
        n = int(m.group("n"), 0)
        if n % 8:
            return m.group(0)
        return "&%s->vtbl[%d]" % (m.group("o"), n // 8)
    return VCAST.sub(sub, src)


RULES = {"types": rule_types, "vtable": rule_vtable}


def rewrite(src, rules):
    for r in rules:
        src = RULES[r](src)
    return src


def parse(argv):
    opts = {"rules": list(RULES), "max": 0, "jobs": 2, "apply": False, "out": os.path.join(ROOT, "build", "lead", "tidy")}
    files = []
    i = 0
    while i < len(argv):
        a = argv[i]
        if a == "--rules":
            opts["rules"] = argv[i + 1].split(","); i += 1
        elif a == "--max":
            opts["max"] = int(argv[i + 1]); i += 1
        elif a == "--jobs":
            opts["jobs"] = int(argv[i + 1]); i += 1
        elif a == "--out":
            opts["out"] = argv[i + 1]; i += 1
        elif a == "--apply":
            opts["apply"] = True
        else:
            files.append(a)
        i += 1
    return opts, files


def main(argv):
    if not argv:
        print(__doc__)
        return 1
    cmd, opts, files = argv[0], *parse(argv[1:])
    os.chdir(ROOT)
    import match
    import project
    srcs = project.sources(refresh=True)                 # {address: path}
    byrel = {os.path.relpath(str(p), ROOT).replace(os.sep, "/"): a for a, p in srcs.items()}
    rels = [os.path.relpath(f, ROOT).replace(os.sep, "/") for f in files] or sorted(byrel)
    if cmd == "show":
        text = open(rels[0], encoding="utf-8").read()
        new = rewrite(text, opts["rules"])
        sys.stdout.writelines(difflib.unified_diff(text.splitlines(True), new.splitlines(True), rels[0], rels[0]))
        return 0
    todo = []
    for rel in rels:
        if rel not in byrel:
            continue
        text = open(rel, encoding="utf-8", newline="").read()
        new = rewrite(text, opts["rules"])
        if new != text:
            todo.append((rel, byrel[rel], new))
        if opts["max"] and len(todo) >= opts["max"]:
            break
    os.makedirs(opts["out"], exist_ok=True)
    pairs, newtext = [], {}
    for rel, addr, new in todo:
        tmp = os.path.join(opts["out"], os.path.basename(rel))
        open(tmp, "w", encoding="utf-8", newline="").write(new)
        pairs.append((addr, tmp))
        newtext[tmp] = rel, new
    kept = bad = 0
    for addr, tmp, ok, report in match.judge_many(pairs, jobs=opts["jobs"], chunk=25):
        rel, new = newtext[tmp]
        if ok:
            kept += 1
            if opts["apply"]:
                open(rel, "w", encoding="utf-8", newline="").write(new)
        else:
            bad += 1
            print("no longer matches:", rel, report.splitlines()[0][:100])
    print(f"{len(todo)} rewritten, {kept} still MATCH, {bad} rejected" + (" (applied)" if opts["apply"] else " (not applied)"))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
