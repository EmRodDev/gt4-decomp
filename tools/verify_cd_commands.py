#!/usr/bin/env python3
"""Verify recovered functions with decomp.wtf's actual linking backend.

Run with ../decomp.wtf/.venv/bin/python after GT4 setup. This compiles each
candidate using GT4's configured compiler, then asks decomp.wtf to resolve
relocations and compare every instruction against the user's CORE.GT4.
Defaults to the first recovered CD commands. ADDR:SIZE specifies a reviewed
function boundary when the call-based inventory includes padding or a neighbour;
both values are hexadecimal. The complete GT4 build remains the final proof.
"""

import argparse
import hashlib
import json
import os
from pathlib import Path
import sys

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import match as gt4_match
import project as gt4_project
from io import BytesIO


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--backend", type=Path, default=REPO.parent / "decomp.wtf",
                        help="decomp.wtf checkout (default: sibling directory)")
    parser.add_argument("functions", nargs="*", metavar="ADDR[:SIZE]",
                        help="function addresses, optionally with reviewed byte lengths (hex)")
    args = parser.parse_args()
    sys.path.insert(0, str(args.backend.resolve() / "src"))
    from decompnet.rom import match as backend
    from decompnet.rom.symbols import SymbolTable
    from elftools.elf.elffile import ELFFile

    os.chdir(REPO)
    _, segments = gt4_project.load_image()

    def read(address, size):
        for start, blob in segments:
            if start <= address and address + size <= start + len(blob):
                return blob[address - start:address - start + size]
        return None

    core = Path(gt4_match.CORE).read_bytes()
    core_hash = hashlib.sha1(core).hexdigest()
    if core_hash != "30031137ce494323816bb707b90d3ec0d07937d2":
        raise SystemExit("CORE.GT4 does not match the supported USA v1.01 executable")

    results = []
    for spec in args.functions or ("005835b0", "00580928"):
        parts = spec.split(":")
        address = int(parts[0], 16)
        span = gt4_match.function_span(address)
        size = int(parts[1], 16) if len(parts) == 2 else span
        if len(parts) > 2 or not 0 < size <= span or size % 4:
            raise SystemExit(f"invalid function boundary: {spec}")
        name = f"func_{address:08X}"
        source = gt4_project.source_for(address)
        if source is None:
            raise SystemExit(f"{name}: no recovered source")
        obj_path = Path(gt4_match.compile_c(source))
        try:
            obj = obj_path.read_bytes()
            target = backend.RomTarget(name, address,
                read(address, size), [], big_endian=False)
            result = backend.link(obj, name, target, SymbolTable(), read)
            if not result.exact:
                raise SystemExit(f"{name}: backend rejected the candidate: {result.problems}; "
                                 f"expected {size} bytes, candidate "
                                 f"{len(result.candidate.code) if result.candidate else 0}")

            # Check that a real instruction change fails through the same API.
            elf = ELFFile(BytesIO(obj))
            symbol = elf.get_section_by_name(".symtab").get_symbol_by_name(name)[0]
            section = elf.get_section(symbol["st_shndx"])
            offset = section["sh_offset"] + symbol["st_value"]
            corrupted = bytearray(obj)
            corrupted[offset] ^= 0x10
            negative = backend.link(bytes(corrupted), name, target, SymbolTable(), read)
            if negative.exact:
                raise SystemExit(f"{name}: negative control unexpectedly matched")
            row = {"function": name, "bytes": len(target.code),
                   "source": os.path.relpath(source, REPO),
                   "source_sha256": hashlib.sha256(Path(source).read_bytes()).hexdigest(),
                   "exact": True, "changed_instruction_rejected": True}
            results.append(row)
            print(f"{name}: decomp.wtf BYTE-EXACT ({row['bytes']} bytes); negative control rejected")
        finally:
            obj_path.unlink(missing_ok=True)

    output = REPO / "build" / "backend-verification.json"
    output.write_text(json.dumps({"core_sha1": core_hash, "results": results}, indent=2) + "\n")


if __name__ == "__main__":
    main()
