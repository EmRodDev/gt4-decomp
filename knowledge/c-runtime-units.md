# Public C runtime units

The newlib and GNU libio sources recover substantial consecutive units when
their original compiler settings and preceding function definitions are retained.
All source additions must pass the unchanged instruction judge, and their code
must be linked in a complete build whose `.text` and `.data` equal the original.

## Reproduction

The public source trees described in `config/libs/newlib.toml` and `libio.toml`
remain outside the repository. Use the original EE compiler under Linux/WSL:

```sh
python3 tools/stage_libmatch.py newlib-preprocessed
python3 tools/stage_libmatch.py newlib-strict
python3 tools/libmatch.py scan newlib-preprocessed
python3 tools/libmatch.py emit newlib-preprocessed -j 2
python3 tools/libmatch.py scan newlib-mprec
python3 tools/libmatch.py emit newlib-mprec -j 2
python3 tools/libmatch.py scan newlib-strict
python3 tools/libmatch.py emit newlib-strict -j 2
python3 tools/libmatch.py scan libio
python3 tools/libmatch.py emit libio -j 2
python3 tools/libmatch.py scan libio-fileops
python3 tools/libmatch.py emit libio-fileops -j 2
python3 tools/libmatch.py scan libio-floatconv
python3 tools/libmatch.py emit libio-floatconv -j 2
python3 tools/organize.py
python3 -m unittest discover -s tests -v
python3 tools/build.py --jobs 2
```

Preprocessing expands ANSI/K&R declaration macros with the target's real headers
and preserves copyright comments. The staging tool copies inputs into a temporary
directory, writes separate output and records its compiler command and file list.
It rejects an output path inside the input tree.

## Matched units

| Configuration | Unit or group | Instructions |
|---|---|---:|
| `newlib-preprocessed` | `qsort` | 635 |
| `newlib-mprec` | `_Balloc` through `__mdiff`, 12 consecutive helpers | 698 |
| `libio` | eight get/backup/underflow helpers beginning at `0x00594598` | 316 |
| `libio-fileops` | all 17 `fileops.c` functions | 934 |
| `libio-floatconv` | `Binit` through `d2b`, 18 consecutive helpers | 918 |

Counts describe the complete matched group, including previously recovered
functions. They are not counts of newly recovered code. Complete-build reports
provide the incremental linked-byte measurements.

The strict-aliasing setting matters within these libraries. For example,
newlib's `_Bfree` reloads the freelist under `-fno-strict-aliasing`, whereas the
original does not. All 17 libio file-operation functions match with strict
aliasing enabled. Using one library-wide profile hides these matches.

Real preceding definitions preserve GCC's nothrow and call-clobber analysis.
Synthetic empty stubs can reveal that a context is missing but are not accepted
as source. Two standalone C++ adaptations retain public function bodies:

- `istream::operator>>(bool&)` declares the real earlier `read_int` helper
  externally with `throw()` and its original old-ABI mangled symbol.
- Libio's `quorem` uses the original `Bigint` layout and arithmetic, with the
  earlier `cmp` helper declared `throw()`.

These two adaptations are manual source contexts; the generic emitter does not
currently recreate them automatically.

## Extraction details covered by regression tests

Preprocessor line markers cannot split argument lists or K&R parameter heads.
Blank lines within those heads must survive. Comments are whitespace-masked for
parsing, preserving every column and line; copyright text containing parentheses
or braces must never be treated as code. Function-macro scope also ignores braces
inside comments. Possessive K&R regex groups prevent exponential backtracking on
long ANSI or variadic signatures.

An indexed access `p05[k-1]` has a `-4` section relocation even when the array
starts at offset zero. Its zero-offset symbol still determines the original
section base. This recovers libio's six-entry table at `0x00657EE0` without
copying it into a new definition.

Extracted initialized arrays always become `extern` declarations, even when the
public definition was not `static`. Otherwise old C accepts `const T table[N];`
as a COMMON definition that can shadow the real shared table at link time.
The full link detected this issue in the newlib big-number group; the extractor
and a regression test now prevent it.

Unused symbol aliases guessed from identical wrappers are left unrenamed when
the target does not reference them. This prevents unrelated header prototypes
from collapsing to the same generic function name. Every emitted source still
undergoes exact call-target judging and complete-build verification.

## Remaining large routines

The public versions of `_dtoa_r`, `_IO_dtoa`, `_IO_strtod` and `strtod` still differ
substantially. Matching their helpers does not establish a match for the complete
conversion functions. The newlib `_ulp` and `_ratio` helpers retain delay-slot
differences under the default, later-assembler and no-sibling-call profiles.
Those results are recorded in the attempt diary and session logs.

## Expat tokenizer context

`config/libs/expat-token.toml` extracts the public Expat 1.95.7 `xmltok.c`
unit using the original no-strict-aliasing profile. The tokenizer groups keep
consecutive real bodies rather than synthetic helper implementations:

| First function | Group | Instructions |
|---|---|---:|
| `little2_sameName` | name comparison and ASCII name matching | 120 |
| `big2_sameName` | name comparison and ASCII name matching | 120 |
| `normal_scanComment` | 12 scanners through `normal_scanLt` | 1,716 |
| `unicode_byte_type` | nine helpers through `little2_scanPi` | 834 |
| `toAscii` | `toAscii`, `isSpace`, `parsePseudoAttribute` | 190 |

`isSpace` is a real intervening out-of-line function, not an omitted inline
helper. Keeping it is required for a valid contiguous group. Two standalone
UTF-16 end-tag readers and the big-endian processing-instruction scanner also
match. The isolated processing-instruction callers need a const declaration of
the immutable `unicode_byte_type` classifier. The configuration scopes that
context to those callers; applying it throughout the unit changes other code.

The six-byte private `CDATA_LSQB` constant lies between jump tables in the
normal scanner group's constant pool. It must retain its actual public
initializer. Externalizing it leaves the instructions matching in isolation but
changes the pool layout, so the full builder correctly rejects the object.
`preserve_statics` keeps this named constant; the complete relocated section
must still pass the original-byte placement checks. It is not arbitrary padding.

Reproduce with `libmatch.py scan expat-token` and `libmatch.py emit expat-token`.
The little-endian `scanLt` still has a switch dispatch difference; its name in a
configuration does not establish a match. Only the verified groups above are
retained.

## Complete-build source selection

All constant and exception sections are verified before a covering source group
is selected. A parent rejected for unplaceable data leaves its standalone child
sources eligible. This prevents a late data rejection from silently replacing
already recovered child code with raw original bytes. Sources excluded by
licence cannot re-enter through the compilation cache. Coverage counts include
only whole inventory functions supplied by a verified linked group; partially
covered following functions do not count as complete.

## Mechanical searches with real neighboring bodies

`permute.py --preserve-context --judge-start GROUP_ADDRESS` varies one target
function while each compiler invocation retains the real surrounding function
bodies. The upstream permuter otherwise reduces non-inline neighbors to
prototypes, losing the call-clobber context required by several library units.
`permute_context.py` restores the complete unit before compilation. Scoring
selects only the varied function and displays target/candidate at the same
positive address, so different positions in their objects do not create spurious
branch-target differences. Acceptance still uses the unchanged whole-group judge
at `GROUP_ADDRESS` and the complete original-byte build. No surrounding body is
replaced by a synthetic implementation.

Preprocessing and AST rewriting discard comments, so accepted mechanical results
restore the original public copyright/permission notices and licence markers.
Tests cover both context restoration and notice retention.

## Object metadata collection

`object_info.py` reads ELF32 section sizes and undefined symbols directly. This
replaces one `readelf` and one `nm` subprocess per source on every complete proof.
Its output was compared with both original binutils commands for all 28,510
objects in the pre-sorting checkpoint: zero differences. Truncated files, wrong
endianness and invalid tables fail explicitly. Only current expected source
objects participate; a stale cache entry cannot bypass licence exclusion.
Relocation validation and the final original-byte comparisons remain unchanged.
