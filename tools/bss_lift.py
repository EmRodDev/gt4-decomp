#!/usr/bin/env python3
"""Declare the game's .bss variables as C sources under data/bss/.

The executable has no .bss section (the start-up code zeroes it), so no byte comparison can prove
these. What the sources already know is which addresses are variables (the `D_XXXXXXXX` names the
matched functions use) and, for some, a type. This tool writes one definition per named address:

    data/bss/006D/D_006D5E00.c     /* data-at: 0x006D5E00 */
                                   int D_006D5E00;

Size: the distance to the next named address (the last one to the end of .bss). Type: the scalar
or array type the sources declare for it when it fits that size, otherwise bytes. The build links
each file at its address (NOLOAD) and the link fails if two overlap or a symbol lands elsewhere; the
code bytes stay identical, which is the only proof .bss has. Reported apart from the byte-proven data.

    bss_lift.py plan | write
"""
import collections
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import report  # noqa: E402

DECL = re.compile(r"extern\s+((?:const\s+|volatile\s+|unsigned\s+)*[A-Za-z_]\w*(?:\s*\*+)?)\s*(D_([0-9A-Fa-f]{8}))((?:\[[^\]]*\])*)\s*;")
SCALARS = {"int": ("int", 4), "s32": ("int", 4), "u32": ("unsigned int", 4), "unsigned int": ("unsigned int", 4),
           "float": ("float", 4), "f32": ("float", 4), "short": ("short", 2), "s16": ("short", 2),
           "u16": ("unsigned short", 2), "unsigned short": ("unsigned short", 2), "char": ("char", 1),
           "s8": ("char", 1), "u8": ("unsigned char", 1), "unsigned char": ("unsigned char", 1),
           "void *": ("void *", 4)}


def named_addresses():
    lo, hi = report.bss_range()
    seen, types = set(), collections.defaultdict(collections.Counter)
    for f in glob.glob(os.path.join(ROOT, "src", "**", "*.c*"), recursive=True):
        text = open(f, encoding="utf-8", errors="replace").read()
        for m in re.finditer(r"\bD_([0-9A-F]{8})\b", text):
            a = int(m.group(1), 16)
            if lo <= a < hi:
                seen.add(a)
        for m in DECL.finditer(text):
            a = int(m.group(3), 16)
            if lo <= a < hi:
                types[a][(re.sub(r"\s+", " ", m.group(1).strip()).replace(" *", " *"), m.group(4))] += 1
    return lo, hi, sorted(seen), types


ATTR = ' __attribute__((section(".bss")))'  # ee-gcc 2.96 puts a variable without it in .data or COMMON


def definition(addr, size, counter):
    return _definition(addr, size, counter).replace(";", ATTR + ";")


def _definition(addr, size, counter):
    for (ty, dims), _ in counter.most_common():
        if ty in SCALARS:
            c, n = SCALARS[ty]
            if dims == "" and n == size:
                return f"{c} D_{addr:08X};"
            if dims == "[]" and size % n == 0:
                return f"{c} D_{addr:08X}[{size // n}];"
    return f"unsigned char D_{addr:08X}[{size}];"


def main(argv):
    cmd = argv[0] if argv else "plan"
    lo, hi, addrs, types = named_addresses()
    out = []
    for i, a in enumerate(addrs):
        size = (addrs[i + 1] if i + 1 < len(addrs) else hi) - a
        out.append((a, size))
    typed = sum(1 for a, s in out if not definition(a, s, types[a]).startswith("unsigned char"))
    print(f"bss {lo:08X}..{hi:08X}: {len(out)} named variables, {sum(s for _, s in out)} bytes, {typed} typed")
    if cmd == "write":
        n = 0
        for a, s in out:
            path = os.path.join(ROOT, "data", "bss", f"{a >> 16:04X}", f"D_{a:08X}.c")
            if os.path.exists(path):
                continue
            os.makedirs(os.path.dirname(path), exist_ok=True)
            open(path, "w", newline=chr(10)).write(f"/* data-at: 0x{a:08X} */\n{definition(a, s, types[a])}\n")
            n += 1
        print("written", n)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
