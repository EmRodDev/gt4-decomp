# Coverage map (2026-10-23)

What is matched and what is missing, by logic rather than by address. Numbers from
`python tools/coverage.py` (progress/report.json built from commit `0d69f6ab`: **30,106 of 30,876
functions, 88.6% of the code bytes**) and `python tools/families.py`; unit names come from
config/units.txt (RTTI class clusters), unnamed clusters are `unit_<first address>`.
Functions written in assembly in the original (config/asm_functions.txt, 289 entries) are not counted.
The earlier version of this page (2026-10-08, 15,851 functions, 20% of the bytes) is in the git history.

## By subsystem

```
subsystem                                  units  funcs   done    bytes  matched     %  missing
unnamed clusters (unit_*)                    344  18144  17466  3816372  3295908  86.4   520464
STL / C++ runtime / libc (library)            49   6191   6149   514712   481816  93.6    32896
UI faces (m*)                                180   3416   3396   494800   474416  95.9    20384
race simulation (Race*/Car*/Dynamics*)       123   1592   1571   232308   212916  91.7    19392
other named classes                           44    475    471    77328    73536  95.1     3792
engine handles (h*)                           34    982    977   120156   116900  97.3     3256
script-bound model classes (M*)                8     76     76     7440     7440 100.0        0
all                                          782  30876  30106  5263116  4662932  88.6   600184
```

## Units with the most unmatched bytes

```
unit                                            start funcs  done   bytes matched     %  subsystem
unit_00494578                                00494578  3646  3364  742376  581572  78.3  unnamed clusters (unit_*)
unit_0046A050                                0046a050  1020  1001  170336  145456  85.4  unnamed clusters (unit_*)
unit_003F7150                                003f7150   238   221   66120   43768  66.2  unnamed clusters (unit_*)
unit_00415E90                                00415e90   255   237   67480   45552  67.5  unnamed clusters (unit_*)
unit_005547E8                                005547e8   575   520   75992   55316  72.8  unnamed clusters (unit_*)
unit_00408DB8                                00408db8   181   171   50432   30280  60.0  unnamed clusters (unit_*)
unit_0057A128                                0057a128   552   495  101416   81540  80.4  unnamed clusters (unit_*)
unit_00378778                                00378778   521   510   57412   38580  67.2  unnamed clusters (unit_*)
unit_0059BE80                                0059be80   528   501  140280  125264  89.3  STL / C++ runtime / libc (library)
unit_0034E9A0                                0034e9a0   361   350   88920   73952  83.2  unnamed clusters (unit_*)
unit_003CCAE0                                003ccae0   127   116   35940   21628  60.2  unnamed clusters (unit_*)
unit_00364818                                00364818   266   259   53964   39780  73.7  unnamed clusters (unit_*)
```

## What is left (open functions with no source: 769, 601 KB)

| class | functions | bytes | note |
|---|---|---|---|
| ordinary C/C++ | 652 | 511 KB | the hard residue: large functions (many over 1 KB), register-allocation and scheduling differences; see knowledge/deferred-to-last.md |
| MMI (128-bit) | 47 | 39 KB | `plzcw`, `pcpy*`, `pextl*`: C cannot express most of them; single-instruction intrinsics only (tools/asm_policy.py) |
| fragment | 16 | 25 KB | borrows its caller's registers or jumps into its neighbours; usually one function cut in pieces by the inventory |
| VU0 macro | 44 | 24 KB | COP2/VU0 sequences; the pure-vector ones were moved to config/asm_functions.txt |
| trapping `daddi`/`dsub` | 10 | 2 KB | soft-float library, hand-written in the original |

## How the numbers are verified

CI (`.github/workflows/check.yml`, `tools/ci_local.sh`) checks that every source compiles, the asm policy
and the source layout; it does not prove a match. The proof is `python tools/build.py`: it compiles
every source, links the result over the executable you supply and compares both loaded segments with
SHA-1. The figures above are written by `tools/publish_progress.py`, which refuses to run unless the last
full build describes the current commit and its working tree was clean (the `progress` branch records the
commit). If you cannot run the build (it needs your own copy of the game), treat a figure as the last
one the maintainers verified, not as something CI re-checks.

## Where the next effort goes

1. The ordinary residue is matched with compiler profiles (`tools/profile_sweep.py`), the permuter
   (`tools/finish_near.py`) and public sources where they exist (zlib/gzip, newlib, libio, Expat:
   `tools/libmatch.py`). New contributors have found most of the recent gains in the SDK and library ranges
   (0x4A7000-0x5B7000) with the ee-gcc 2.9 profiles.
2. Readability is tracked separately (`python tools/readability.py`): about 90% of the sources still have no
   explaining comment; `tools/readable_gate.py` is the gate for edits that only change names and comments.
3. The pieces the native port needs from the decompilation are listed in the private lab's
   R1/A1 dependency table; the large model-render and sound-update functions are the open ones.
