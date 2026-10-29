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
    data_lift.py write [--kinds strings,tables,rest] [--limit N]
                                       write the files (existing ones are left alone); `rest` types
                                       what is left of .data: float arrays, word arrays, byte arrays
    data_lift.py fixfloats             rewrite, with exact (17-digit) literals, the float elements the
                                       last build reproduced wrongly: the compiler's decimal-to-float
                                       conversion is off by one bit for some 9-digit literals
    data_lift.py prune BUILD.log       delete the sources the last build reported as `left out`
                                       (overlapping constants a function already places)

Typed on purpose: strings as char arrays, tables of pointers with the names of the functions they
point to (a vtable is recognised by tools/rtti.py and says which class it belongs to). Then, from
what is left (`rest`, run after strings and tables are in the build report): runs of plausible
floats as float arrays, other words as unsigned int arrays, odd edge bytes as unsigned char arrays.
Blocks of zeros stay untouched in the original's bytes (the compiler would put them in .bss).
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


FLOAT_EXP = range(100, 161)  # about 1e-9 .. 1e12: a word in this range is read as a float


def is_float_word(w):
    return w != 0 and ((w >> 23) & 255) in FLOAT_EXP


def unit_ranges():
    """[(start, end)] of the data sources the last build placed (build/full/report.json data_units)."""
    path = os.path.join(ROOT, "build", "full", "report.json")
    if not os.path.exists(path):
        return []
    rep = json.load(open(path))
    return sorted((int(a, 16), int(a, 16) + int(n)) for a, n in rep.get("data_units", {}).items())


def free_gaps(da, size, taken):
    """[(lo, hi)] of .data not covered by `taken` (sorted, may touch)."""
    gaps, cur, end = [], da, da + size
    for a, b in sorted(taken):
        if a > cur:
            gaps.append((cur, min(a, end)))
        cur = max(cur, b)
        if cur >= end:
            break
    if cur < end:
        gaps.append((cur, end))
    return [(a, b) for a, b in gaps if b > a]


def split_zero_runs(db, da, lo, hi, min_zero=32, max_len=4096):
    """Pieces of [lo, hi) without long runs of zero bytes, trimmed of zeros at both ends."""
    pieces, i = [], lo
    while i < hi:
        while i < hi and db[i - da] == 0:
            i += 1
        if i >= hi:
            break
        j, last = i, i
        while j < hi:
            if db[j - da] != 0:
                last = j
            elif j - last >= min_zero:
                break
            j += 1
        pieces.append((i, last + 1))
        i = last + 1
    out = []
    for a, b in pieces:
        while b - a > max_len:
            out.append((a, a + max_len))
            a += max_len
        out.append((a, b))
    return out


def float_literal(w, digits=9, bias=0.0):
    """The literal for a float word. The compiler (gcc 2.96) converts decimal to float imprecisely
    and can land one bit below the nearest value; `bias` moves the literal that fraction of an ulp
    away from zero so the conversion lands on the intended bit pattern."""
    f = struct.unpack("<f", struct.pack("<I", w))[0]
    if bias:
        step = abs(struct.unpack("<f", struct.pack("<I", w + 1))[0] - f)
        f = f + (step * bias if f > 0 else -step * bias)
    text = "%.*g" % (digits, f)
    if not any(c in text for c in ".en"):
        text += ".0"
    return text + "f"


def typed_pieces(db, da, a, b):
    """[(kind, address, values)] covering [a, b): bytes up to the 4-byte boundary, then words
    (runs of floats and runs of other words), then the tail bytes."""
    out = []
    head = min(b, (a + 3) & ~3)
    if head > a:
        out.append(("bytes", a, list(db[a - da:head - da])))
    wend = head + ((b - head) // 4) * 4
    n = (wend - head) // 4
    words = list(struct.unpack_from(f"<{n}I", db, head - da)) if n else []
    i = 0
    while i < n:
        j = i
        if is_float_word(words[i]):
            while j < n and (is_float_word(words[j]) or words[j] == 0):
                j += 1
            while j > i and words[j - 1] == 0:
                j -= 1
            if sum(1 for w in words[i:j] if w) >= 2:
                out.append(("floats", head + 4 * i, words[i:j]))
                i = j
                continue
        j = i + 1
        while j < n and not (is_float_word(words[j]) and j + 1 < n and is_float_word(words[j + 1])):
            j += 1
        out.append(("words", head + 4 * i, words[i:j]))
        i = j
    if b > wend:
        out.append(("bytes", wend, list(db[wend - da:b - da])))
    return [(k, ad, v) for k, ad, v in out if any(v)]


def piece_text(kind, ad, vals, exact=()):
    name = f"D_{ad:08X}"
    if kind == "floats":
        ctype, body = "float", [float_literal(w, *((17, 0.3) if ad + 4 * i in exact else (9, 0.0))) for i, w in enumerate(vals)]
    elif kind == "words":
        ctype, body = "unsigned int", [f"0x{w:08X}" for w in vals]
    else:
        ctype, body = "unsigned char", [f"0x{w:02X}" for w in vals]
    per = 8 if kind == "bytes" else 4
    lines = [f"/* data-at: 0x{ad:08X} */", f"{ctype} {name}[{len(vals)}] = {{"]
    lines += ["    " + ", ".join(body[r:r + per]) + "," for r in range(0, len(body), per)]
    lines.append("};")
    return "\n".join(lines) + "\n"


def write_file(path, text):
    if os.path.exists(path):
        return False
    os.makedirs(os.path.dirname(path), exist_ok=True)
    open(path, "w", newline="\n", encoding="utf-8").write(text)
    return True


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["plan", "write", "prune", "fixfloats"])
    ap.add_argument("log", nargs="?")
    ap.add_argument("--kinds", default="strings,tables")  # add `rest` once strings/tables are in a build
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args(argv)

    if a.cmd == "fixfloats":
        built = open(os.path.join(ROOT, "build", "full", "built_data.bin"), "rb").read()
        _, _, da, db = image()
        wrong = {da + i - i % 4 for i in range(min(len(built), len(db))) if built[i] != db[i]}
        fixed = 0
        for dp, _, fs in os.walk(os.path.join(DATA, "floats")):
            for fn in fs:
                ad = int(fn[2:10], 16)
                path = os.path.join(dp, fn)
                cnt = int(re.search(r"[[](" + "[0-9]+" + r")[]]", open(path).read()).group(1))
                if not any(ad + 4 * i in wrong for i in range(cnt)):
                    continue
                # the compiler cannot be steered to these bit patterns: keep the exact words
                vals = list(struct.unpack_from("<%dI" % cnt, db, ad - da))
                os.remove(path)
                write_file(os.path.join(DATA, "words", f"{ad >> 16:04X}", fn), piece_text("words", ad, vals))
                fixed += 1
        print("moved", fixed, "float sources to exact word arrays")
        return 0
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
    strings = [(ad, s) for ad, s in find_strings(db, da) if not overlaps(taken, ad, ad + len(s) + 1)] if kinds & {"strings", "tables"} else []
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
    if "rest" in kinds:
        pieces = []
        for lo, hi in free_gaps(da, len(db), taken + unit_ranges()):
            for a2, b2 in split_zero_runs(db, da, lo, hi):
                pieces += typed_pieces(db, da, a2, b2)
        by = {}
        for k, ad, v in pieces:
            by.setdefault(k, [0, 0])
            by[k][0] += 1
            by[k][1] += len(v) * (1 if k == "bytes" else 4)
        print("rest:", ", ".join(f"{k} {n} ({b} bytes)" for k, (n, b) in sorted(by.items())))
        for k, ad, v in (pieces[:a.limit] if a.limit else pieces):
            path = os.path.join(DATA, k, f"{ad >> 16:04X}", f"D_{ad:08X}.c")
            written += write_file(path, piece_text(k, ad, v))
    print("written", written, "files under data/")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
