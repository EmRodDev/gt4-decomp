# Original files

Nothing from the game is ever committed. Dump your own disc and put the image here:

```
orig/SCUS-97328/Gran Turismo 4 (USA) (v1.01).iso
```

Then extract and convert the executable:

```sh
python tools/iso_extract.py "orig/SCUS-97328/Gran Turismo 4 (USA) (v1.01).iso" CORE.GT4 SYSTEM.CNF SCUS_973.28 -o orig/SCUS-97328/files
python tools/core2elf.py orig/SCUS-97328/files/CORE.GT4 orig/SCUS-97328/CORE.GT4.elf
```

## Expected hashes (SCUS-97328, version 1.01)

| File | SHA-1 |
|---|---|
| disc image (Redump, CRC32 `d1d25931`) | see redump.org/disc/955 |
| `SCUS_973.28` (bootstrap) | `1df6f08c348e55f66c3a38e1774a9a989ce7d6ba` |
| `CORE.GT4` (as on disc) | `30031137ce494323816bb707b90d3ec0d07937d2` |
| `CORE.GT4.elf` (from `core2elf.py`) | `ca47e116503e12b2db95aa7ee7debaaa99870c8b` |

`core2elf.py` writes section headers since commit `71312d2dd192` (2026-10-07), which changed the
ELF's hash but not what it loads: segment addresses, sizes, flags and every loaded byte are the
same. An ELF written by an older `core2elf.py` has SHA-1 `eb6e17112038bbeab63b09d445112adcd957c900`;
convert again with the current script.
