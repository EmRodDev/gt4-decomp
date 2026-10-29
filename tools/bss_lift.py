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
import struct
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


LOADSTORE = {0x20: (1, "s"), 0x24: (1, "u"), 0x28: (1, "w"), 0x21: (2, "s"), 0x25: (2, "u"), 0x29: (2, "w"),
             0x23: (4, "i"), 0x2B: (4, "w"), 0x31: (4, "f"), 0x39: (4, "f"), 0x37: (8, "l"), 0x3F: (8, "l"),
             0x35: (8, "d"), 0x3D: (8, "d"), 0x1E: (16, "q"), 0x1F: (16, "q"), 0x22: (4, "p"), 0x26: (4, "p"),
             0x2A: (4, "p"), 0x2E: (4, "p")}


def scan_accesses(lo, hi):
    """{address: set((width, kind))} of loads and stores whose base register came from a lui/addiu or
    lui pair into [lo, hi): width in bytes and kind (i int, f float, s/u/w byte or short, l/d 8, q 16)."""
    import match
    text_addr, text = match.load_text()
    n = len(text) // 4
    words = struct.unpack("<%dI" % n, text[:4 * n])
    regs, hits = {}, collections.defaultdict(set)
    for w in words:
        op, rs, rt, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if op == 0x0F:
            regs[rt] = imm << 16
            continue
        if op in LOADSTORE and rs in regs:
            a = (regs[rs] + simm) & 0xFFFFFFFF
            if lo <= a < hi:
                hits[a].add(LOADSTORE[op])
            if op in (0x23, 0x22, 0x26, 0x20, 0x24, 0x21, 0x25, 0x37, 0x1E) and rt != rs:
                regs.pop(rt, None)
            continue
        if op == 0x09 and rs in regs:  # addiu rt, rs, imm: a pointer into the variable
            a = (regs[rs] + simm) & 0xFFFFFFFF
            if rt != rs or True:
                regs[rt] = a
            continue
        if op == 0 and (w & 0x3F) in (0x21, 0x25, 0x20, 0x2D, 0x2B, 0x2A):  # addu/or/add/daddu/...: result unknown
            regs.pop((w >> 11) & 31, None)
        elif op in (0x23, 0x0D, 0x0C, 0x08, 0x0A, 0x0B) and rt in regs:
            regs.pop(rt, None)
    return hits


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


C_OF = {(4, "i"): "int", (4, "f"): "float", (4, "p"): "int", (4, "w"): "int", (2, "s"): "short", (2, "u"): "unsigned short",
        (2, "w"): "short", (1, "s"): "char", (1, "u"): "unsigned char", (1, "w"): "char", (8, "l"): "long long",
        (8, "d"): "double"}


def from_accesses(addr, size, hits):
    """Type from how the code reads and writes [addr, addr+size): one width and kind at aligned offsets."""
    seen = {}
    for a in range(addr, addr + size):
        for k in hits.get(a, ()):
            seen.setdefault(a - addr, set()).add(k)
    if not seen:
        return None
    kinds = set().union(*seen.values())
    widths = {w for w, _ in kinds}
    if len(widths) != 1:
        return None
    w = widths.pop()
    kind_chars = {k for _, k in kinds}
    # float reads and int moves of the same word are common; any f read decides float
    k = "f" if "f" in kind_chars and w == 4 else sorted(kind_chars)[0]
    if "f" in kind_chars and w == 4 and len(kind_chars) > 1:
        k = "f"
    c = C_OF.get((w, k))
    if c is None or any(off % w for off in seen) or size % w:
        return None
    if size == w:
        return "%s D_%08X;" % (c, addr)
    if size >= 2 * w:
        return "%s D_%08X[%d];" % (c, addr, size // w)
    return None


HITS = {}


def _definition(addr, size, counter):
    t = from_accesses(addr, size, HITS)
    if t:
        return t
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
    HITS.update(scan_accesses(lo, hi))
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
            os.makedirs(os.path.dirname(path), exist_ok=True)
            open(path, "w", newline=chr(10)).write(f"/* data-at: 0x{a:08X} */\n{definition(a, s, types[a])}\n")
            n += 1
        print("written", n)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
