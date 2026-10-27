#!/usr/bin/env python3
"""Lift the game's own data into typed C sources under data/ (strings, tables of pointers).

The executable's .data segment holds, besides the constants of the matched functions (placed by
tools/build.py from their objects), the game's strings, vtables, callback tables and other data that
no function source defines. This tool writes them as C files, one object each:

    data/strings/AAAA/D_00620FA0.c      char D_00620FA0[] = "Medius Game Communication Library (MGCL)";
    data/tables/AAAA/D_0067E120.c       void *D_0067E120[] = { 0, 0x0067E0F0, func_00123456, ... };

The first line of each file is `/* data-at: 0xADDRESS */`; tools/build.py compiles it with the
project compiler, places it at that address and the image comparison (SHA-1 of .data) proves it.
Nothing here is trusted: a wrong file makes the build report `.data DIFFERS`, never a false OK.

    data_lift.py plan                  what would be written (counts, bytes) without writing
    data_lift.py write [--kinds strings,tables] [--limit N]
                                       write the files (existing ones are left alone)
    data_lift.py prune BUILD.log       delete the sources the last build reported as `left out`
                                       (overlapping constants a function already places)

Typed on purpose: strings as char arrays, tables of pointers with the names of the functions they
point to (a vtable is recognised by tools/rtti.py and says which class it belongs to). What is not
confidently one of these stays untouched in the original's bytes.
"""
import argparse
import csv
import json
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import match  # noqa: E402
import project  # noqa: E402

DATA = os.path.join(ROOT, "data")
TEXTLIKE = re.compile(rb"[A-Za-z0-9 .,:;_/%\-()'\[\]!?+*=<>#&@\\\"\t\r\n]+")


def image():
    (ta, tb), (da, db) = project.load_image()[1][:2]
    return ta, tb, da, db


def function_starts():
    starts = set()
    with open(match.FUNCTIONS) as f:
        for row in csv.DictReader(f):
            starts.add(int(row["address"], 16))
    return starts


def placed_ranges():
    """[(start, end)] the last full build placed from function objects (build/full/report.json)."""
    path = os.path.join(ROOT, "build", "full", "report.json")
    if not os.path.exists(path):
        return []
    rep = json.load(open(path))
    out = [(int(s["address"], 16), int(s["address"], 16) + int(s["size"])) for s in rep.get("data_sections", [])]
    return sorted(out)


def overlaps(ranges, lo, hi):
    return any(a < hi and lo < b for a, b in ranges)


def c_string(raw):
    out = []
    for b in raw:
        c = chr(b)
        if c == "\\":
            out.append("\\\\")
        elif c == '"':
            out.append('\\"')
        elif c == "\n":
            out.append("\\n")
        elif c == "\t":
            out.append("\\t")
        elif c == "\r":
            out.append("\\r")
        elif 32 <= b < 127:
            out.append(c)
        else:
            out.append(f"\\{b:03o}")
    return "".join(out)


def find_strings(db, da, min_len=4):
    """[(address, bytes)] of NUL-terminated text-like strings (no terminator in the bytes)."""
    out, n, j = [], len(db), 0
    while j < n:
        if db[j] == 0:
            j += 1
            continue
        k = j
        while k < n and db[k] != 0:
            k += 1
        run = db[j:k]
        if k < n and len(run) >= min_len and TEXTLIKE.fullmatch(run) and len(set(run)) >= 3:
            out.append((da + j, run))
        j = k + 1
    return out


def rtti_vtables():
    """{vtable address: class name} from the recovered classes, when tools/rtti.py data exists."""
    path = os.path.join(ROOT, "config", "classes.json")
    out = {}
    if os.path.exists(path):
        try:
            for name, c in json.load(open(path)).items():
                for v in c.get("vtables", []):
                    # gcc 2.96: (delta, pointer) pairs, the first pair is the type-info function
                    out[int(v["address"])] = (name, 8 * (1 + len(v.get("methods", []))))
        except (ValueError, OSError, AttributeError):
            pass
    return out


def split_at_vtables(runs, vt):
    """Cut the runs at the recovered vtables: each vtable becomes a table of its own size."""
    out = []
    for ad, w in runs:
        cur = ad
        end = ad + 4 * len(w)
        cuts = sorted(v for v in vt if ad <= v < end)
        if not cuts:
            out.append((ad, w))
            continue
        if cuts[0] > ad:
            out.append((ad, w[:(cuts[0] - ad) // 4]))
        for i, v in enumerate(cuts):
            size = min(vt[v][1], (cuts[i + 1] if i + 1 < len(cuts) else end) - v)
            out.append((v, w[(v - ad) // 4:(v - ad + size) // 4]))
            rest_from = v + size
            nxt = cuts[i + 1] if i + 1 < len(cuts) else end
            if rest_from < nxt:
                out.append((rest_from, w[(rest_from - ad) // 4:(nxt - ad) // 4]))
    return [(a, [x for x in w]) for a, w in out if w]


def find_tables(db, da, ta, tb, starts, string_addrs, min_ptrs=3):
    """[(address, [words])] runs of aligned words made of pointers to function starts, to lifted
    strings or to other data, and zeros between them. A run needs `min_ptrs` function/string pointers."""
    t0, t1 = ta, ta + len(tb)
    d0, d1 = da, da + len(db) + 0x400000
    n = len(db) // 4
    words = struct.unpack_from(f"<{n}I", db, 0)

    def kind(v):
        if v == 0:
            return "zero"
        if t0 <= v < t1 and v in starts:
            return "func"
        if v in string_addrs:
            return "str"
        if d0 <= v < d1 and v % 4 == 0:
            return "data"
        return None

    runs, i = [], 0
    while i < n:
        k = kind(words[i])
        if k in (None, "zero"):
            i += 1
            continue
        j = i
        while j < n and kind(words[j]) is not None:
            j += 1
        # trim zeros at both ends of [i, j)
        a, b = i, j
        while a < b and words[a] == 0:
            a += 1
        while b > a and words[b - 1] == 0:
            b -= 1
        ptrs = sum(1 for w in words[a:b] if kind(w) in ("func", "str"))
        if ptrs >= min_ptrs:
            runs.append((da + 4 * a, list(words[a:b])))
        i = j
    return runs


def write_file(path, text):
    if os.path.exists(path):
        return False
    os.makedirs(os.path.dirname(path), exist_ok=True)
    open(path, "w", newline="\n", encoding="utf-8").write(text)
    return True


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["plan", "write", "prune"])
    ap.add_argument("log", nargs="?")
    ap.add_argument("--kinds", default="strings,tables")
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args(argv)

    if a.cmd == "prune":
        gone = 0
        for line in open(a.log, encoding="utf-8", errors="replace"):
            m = re.match(r"\s*data source ([0-9A-F]{8}) left out", line)
            if m:
                for dp, _, fs in os.walk(DATA):
                    for fn in fs:
                        if fn == f"D_{m.group(1)}.c":
                            os.remove(os.path.join(dp, fn))
                            gone += 1
        print("removed", gone, "sources the build left out")
        return 0

    ta, tb, da, db = image()
    taken = placed_ranges()
    starts = function_starts()
    kinds = set(a.kinds.split(","))
    strings = [(ad, s) for ad, s in find_strings(db, da) if not overlaps(taken, ad, ad + len(s) + 1)] if "strings" in kinds or "tables" in kinds else []
    string_addrs = {ad for ad, _ in strings}
    tables = []
    if "tables" in kinds:
        vt0 = rtti_vtables()
        tables = [(ad, w) for ad, w in split_at_vtables(find_tables(db, da, ta, tb, starts, string_addrs), vt0)
                  if not overlaps(taken, ad, ad + 4 * len(w))]
    vt = rtti_vtables()
    print(f"strings: {len(strings)} ({sum(len(s) + 1 for _, s in strings)} bytes)")
    print(f"tables of pointers: {len(tables)} ({sum(4 * len(w) for _, w in tables)} bytes; "
          f"{sum(1 for ad, _ in tables if ad in vt)} are vtables of known classes)")
    if a.cmd == "plan":
        return 0
    written = 0
    if "strings" in kinds:
        for ad, s in (strings[:a.limit] if a.limit else strings):
            path = os.path.join(DATA, "strings", f"{ad >> 16:04X}", f"D_{ad:08X}.c")
            text = f"/* data-at: 0x{ad:08X} */\nchar D_{ad:08X}[] = \"{c_string(s)}\";\n"
            written += write_file(path, text)
    if "tables" in kinds:
        for ad, w in (tables[:a.limit] if a.limit else tables):
            fnames = sorted({x for x in w if x in starts})
            lines = ["/* data-at: 0x%08X */" % ad]
            if ad in vt:
                lines.append(f"/* vtable of {vt[ad][0]} */")
            lines += [f"extern void func_{x:08X}();" for x in fnames]
            entries = []
            for x in w:
                if x == 0:
                    entries.append("0")
                elif x in starts:
                    entries.append(f"func_{x:08X}")
                elif x in string_addrs:
                    entries.append(f"D_{x:08X}")
                else:
                    entries.append(f"(void *)0x{x:08X}")
            for x in sorted({x for x in w if x in string_addrs}):
                lines.append(f"extern char D_{x:08X}[];")
            lines.append(f"void *D_{ad:08X}[{len(w)}] = {{")
            for r in range(0, len(entries), 4):
                lines.append("    " + ", ".join(entries[r:r + 4]) + ",")
            lines.append("};")
            path = os.path.join(DATA, "tables", f"{ad >> 16:04X}", f"D_{ad:08X}.c")
            written += write_file(path, "\n".join(lines) + "\n")
    print("written", written, "files under data/")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
