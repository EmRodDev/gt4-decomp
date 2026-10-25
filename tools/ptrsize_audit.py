#!/usr/bin/env python3
"""Which matched sources depend on the PS2's 4-byte pointers? The inventory a 64-bit native port starts from.

The decompiled code was written for a 32-bit target: a pointer is 4 bytes, an object's first word is
its vtable pointer, and many sources read fields at fixed offsets. Compiled for a 64-bit host those
break. This tool reads every source in src/ (text only, CPU only) and tags the patterns that care:

    ptr-load     a pointer read or written at a byte offset: *(T **)(base + 0x5C), *(T **)((char *)p + 8)
    ptr-cast     a pointer-to-int or int-to-pointer cast: (int)p, (u32)p, (T *)0x1234, (T *)n
    ptr-field    a struct or class member that is a pointer (the layout changes size)
    virtual      a class with virtual functions (the vptr is 8 bytes on a 64-bit host)
    wide-int     long / unsigned long used as a 32-bit value (64-bit on LP64 hosts)
    funcptr      a function pointer type or a call through a table of them

    ptrsize_audit.py [--json OUT] [--top N]      counts per tag, per subsystem and the sources with most tags

Heuristics, not a parser: a count says where to look, not what to change. A source with no tag is
unlikely to care about the host's pointer size.
"""
import argparse
import collections
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)
STRING = re.compile(r'"(?:[^"\\\n]|\\.)*"')
TAGS = {
    "ptr-load": re.compile(r"\*\s*\(\s*(?:const\s+|volatile\s+)*[A-Za-z_][\w:<> ]*\s*\*+\s*\)\s*\(?[^;]*?(?:\+|\[)\s*(?:0x[0-9A-Fa-f]+|\d+)"),
    "ptr-cast": re.compile(r"\(\s*(?:int|unsigned int|unsigned|u32|s32|uint32_t|long|unsigned long)\s*\)\s*[A-Za-z_&*(]"
                           r"|\(\s*[A-Za-z_][\w:<> ]*\s*\*+\s*\)\s*(?:0x[0-9A-Fa-f]+|\d+|[a-z_]\w*\s*[+)])"),
    "ptr-field": re.compile(r"^\s*(?:struct\s+|class\s+|const\s+)?[A-Za-z_][\w:<> ]*\s*\*+\s*[A-Za-z_]\w*\s*;", re.M),
    "virtual": re.compile(r"\bvirtual\b"),
    "wide-int": re.compile(r"\b(?:unsigned\s+long|long)\b(?!\s+long)"),
    "funcptr": re.compile(r"\(\s*\*\s*[A-Za-z_]\w*\s*\)\s*\("),
}


def subsystem(path):
    rel = os.path.relpath(path, os.path.join(ROOT, "src")).replace(os.sep, "/")
    return rel.split("/")[0]


def audit_file(path):
    text = open(path, encoding="utf-8", errors="replace").read()
    code = STRING.sub('""', COMMENT.sub(" ", text))
    found = {}
    for tag, rx in TAGS.items():
        n = len(rx.findall(code))
        if n:
            found[tag] = n
    return found


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--json", help="write the per-source tags here")
    ap.add_argument("--top", type=int, default=15)
    a = ap.parse_args(argv)
    per_file, totals, per_sub = {}, collections.Counter(), collections.defaultdict(collections.Counter)
    files = 0
    for dp, _, fns in os.walk(os.path.join(ROOT, "src")):
        for fn in fns:
            if not fn.endswith((".c", ".cpp")):
                continue
            p = os.path.join(dp, fn)
            files += 1
            found = audit_file(p)
            sub = subsystem(p)
            per_sub[sub]["sources"] += 1
            if found:
                per_file[os.path.relpath(p, ROOT).replace(os.sep, "/")] = found
                per_sub[sub]["tagged"] += 1
                for t in found:
                    totals[t] += 1
                    per_sub[sub][t] += 1
    tagged = len(per_file)
    print(f"{files} sources; {tagged} carry at least one tag ({100 * tagged / max(files, 1):.1f}%)")
    print("\nsources per tag:")
    for t, n in totals.most_common():
        print(f"  {t:10} {n:6}")
    print("\nper subsystem (sources / tagged / ptr-load / virtual):")
    for s, c in sorted(per_sub.items(), key=lambda kv: -kv[1]["tagged"]):
        print(f"  {s:12} {c['sources']:6} {c['tagged']:6} {c['ptr-load']:6} {c['virtual']:6}")
    heavy = sorted(per_file.items(), key=lambda kv: -sum(kv[1].values()))[:a.top]
    print(f"\n{a.top} sources with the most tags:")
    for p, f in heavy:
        print(f"  {sum(f.values()):4}  {p}  {dict(f)}")
    if a.json:
        json.dump(per_file, open(a.json, "w"), indent=1)
        print("\nwrote", a.json)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
