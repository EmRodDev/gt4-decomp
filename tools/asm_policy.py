#!/usr/bin/env python3
"""What inline assembly a decompiled source may contain.

Allowed: at most MAX_ASM single-instruction intrinsics the C compiler cannot express (e.g.
`sqrt.s`, `max.s`, `pcpyld`) in one source. Asm labels (`asm("_vt$3ios")`, symbol aliases) are not
instructions and are not counted.
Rejected: file-scope assembly, raw instruction words (`.word`), inline blocks of more than one
instruction, more than MAX_ASM instruction statements in one source (a body made of them is
assembly written in C, not decompiled code), and register-pinned variables
(`register T x asm("$3")`, a fakematch). Functions that were hand-written in assembly in the
original belong in config/asm_functions.txt and are counted separately, not as decompiled functions.

Sources that predate the limit are listed in config/asm_grandfathered.txt (one address per line);
they are skipped by the count check until they are rewritten or moved to asm_functions.txt, and
the list only ever shrinks.

    asm_policy.py FILE...    print the violations; exit 1 if any
"""
import os
import re
import sys

MAX_ASM = 2
STRING = r'"(?:[^"\\]|\\.)*"'
ASM_BLOCK = re.compile(r'\b(?:__asm__|asm)\s*(?:volatile|__volatile__)?\s*\(\s*((?:' + STRING + r'\s*)+)')
FILE_SCOPE = re.compile(r'^(?:__asm__|asm)\s*\(', re.M)
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
_grandfathered = None


def grandfathered():
    global _grandfathered
    if _grandfathered is None:
        _grandfathered = set()
        path = os.path.join(ROOT, "config", "asm_grandfathered.txt")
        if os.path.exists(path):
            for line in open(path, encoding="utf-8"):
                w = line.split("#")[0].split()
                if w:
                    _grandfathered.add(int(w[0], 16))
    return _grandfathered


def is_label(text):
    """asm("_vt$3ios") and friends name a symbol; they are not instructions."""
    t = text.strip()
    if not t:
        return True
    if re.search(r"\s", t):                       # an instruction has operands: `mtc1 %1, %0`
        return False
    return t.startswith("_") or "$" in t or re.match(r"(?:func|D)_[0-9A-Fa-f]{6,8}$", t) is not None


def statements(src):
    """The instruction texts of every inline asm statement in src."""
    out = []
    for m in ASM_BLOCK.finditer(src):
        text = "".join(s[1:-1] for s in re.findall(STRING, m.group(1)))
        if not is_label(text):
            out.append(text)
    return out


def violations(src, addr=None):
    out = []
    if re.search(r'(?<![\w)\]])\.word\b', src):  # not a member access such as state.word
        out.append("raw instruction words (.word)")
    if FILE_SCOPE.search(src) or re.search(r'\.globl|glabel', src):
        out.append("file-scope assembly")
    if fakematch(src):
        out.append("register variable pinned to a machine register (register ... asm(\"$n\")); "
                   "the original code did not choose its registers by hand")
    count = 0
    for text in statements(src):
        insns = [s for s in re.split(r'\\n|;', text) if s.strip() and not s.strip().startswith(".")]
        if len(insns) > 1:
            out.append(f"inline block of {len(insns)} instructions")
        count += 1
    if count > MAX_ASM and (addr is None or addr not in grandfathered()):
        out.append(f"{count} inline asm statements (at most {MAX_ASM}): a body made of them is assembly, "
                   "not decompiled code; if the original is hand-written assembly the function belongs in "
                   "config/asm_functions.txt")
    return out


def fakematch(src):
    return bool(re.search(r'register\s+[^;=]*(?:\basm|__asm__)\s*\(', src))


def address_of(path):
    m = re.search(r"func_([0-9A-Fa-f]{8})", os.path.basename(path))
    if m:
        return int(m.group(1), 16)
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import project
    for a, p in project.sources().items():
        if os.path.abspath(str(p)) == os.path.abspath(path):
            return a
    return None


if __name__ == "__main__":
    bad = 0
    for path in sys.argv[1:]:
        text = open(path, encoding="utf-8").read()
        v = violations(text, addr=-1)
        if v and any("inline asm statements" in x for x in v):
            v = violations(text, addr=address_of(path))
        if v:
            bad += 1
            print(f"{path}: {'; '.join(v)}")
    sys.exit(1 if bad else 0)
