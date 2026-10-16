# GCC exception and frame runtime

The public GCC 2000-10-03 sources provide the allocation and exception runtime
after the completed RTTI block, and the frame-unwinding machinery before it.
`config/libs/gcc-exception.toml` and `gcc-unwind.toml` describe those units.
Only sources passing the unmodified matching judge are retained.

## Reproduction

Run under Linux/WSL with the project's EE compiler and public GCC snapshot:

```sh
python3 tools/stage_gcc_runtime.py --gcc-tree /path/to/gcc-20001003
python3 tools/libmatch.py scan gcc-exception
python3 tools/libmatch.py emit gcc-exception -j 2
python3 tools/libmatch.py scan gcc-unwind
python3 tools/libmatch.py emit gcc-unwind -j 2
python3 -m unittest discover -s tests -v
python3 tools/build.py --keep-going --jobs 2
```

The staging directory is outside the repository. It contains public source,
target header definitions, preprocessed public units, and a record of the
configuration. No original game files are staged or committed.

The two manually typed parts of the frame work are the semaphore adapters
supplied by the staging script and the C++ declaration context for `find_fde`.
The latter retains the public function body, expresses byte arithmetic with
an explicit cast, and declares the earlier `frame_init` function `throw()`.

## Original compiler behavior

Allocation and exception routines contain real exception landing pads.
`ee-gcc2.96-exceptions` enables `-fexceptions`; using the ordinary project
profile would remove required instructions. The later assembler is needed
for the original order of unaligned loads in two frame decoders. The
`ee-gcc2.96-exceptions-as2004` profile combines those existing toolchains.
Neither profile disables instruction scheduling.

The EE frame layout is reconstructed from matching field accesses:

| Field | Offset |
|---|---:|
| `cfa` | `0x000` |
| `eh_ptr` | `0x004` |
| `cfa_offset` | `0x008` |
| `base_offset` | `0x010` |
| `args_size` | `0x018` |
| `reg_or_offset` | `0x020` |
| `cfa_reg` | `0x3F8` |
| `retaddr_column` | `0x3FA` |
| `saved` | `0x3FC` |
| `indirect` | `0x477` |

There are 122 frame registers, 32-bit pointers, and 64-bit `long` fields.
`sizeof(frame_state)` is `0x478`; the internal structure with its saved-state
pointer occupies `0x480`. The public header needs `base_offset` moved ahead
of `args_size` to reproduce the target layout.

## Source-unit context

Some routines must remain together:

- The seven consecutive handler-search and frame-copy helpers preserve GCC's
  analysis of earlier callees and their register clobbers.
- `fde_merge` precedes `end_fde_sort`; keeping both actual definitions avoids
  synthetic nothrow stubs.
- The five consecutive routines starting at `__check_eh_spec` share one
  exception descriptor and table. Extracting their tables independently loses
  the common header and cannot reproduce the original data.

These groups are recorded in the library configurations. The emitter refuses
groups spanning source units or omitting an intervening function.

GCC's C++ frontend recognizes runtime hook names. For example,
`gcc/cp/except.c::call_eh_info` looks up `__start_cp_handler` to obtain the
type of the implicit `__exception_info` catch variable. The confirmed runtime
ABI names are therefore kept in `config/resolved_symbols.txt`; organizing
the sources must preserve their spelling.

## Shared data and complete-build proof

The isolated sources declare shared runtime state and tables `extern`.
Unused inline helpers can still emit local static storage with this old
compiler, so uniquely identified helper statics must also be externalized.
Old gas marks some of these objects `STT_NOTYPE`, including the frame-sort
marker; the extractor accepts that symbol kind only in data sections.

The compiler's implicit `bad_alloc` destructor creates an unwanted out-of-line
copy. Declaring the same empty destructor explicitly inline under the public
header's interface pragma preserves the cleanup instructions and leaves its
canonical out-of-line implementation external. Extracted exception units also
omit the implementation pragma that would otherwise emit their shared vtables.

The full builder places `.gcc_except_table` with the same checks used for
constant and switch tables: all original text references must imply one base,
only understood relocations are accepted, the relocated bytes must match the
original loaded data, and the entire section must remain within that segment.
An individual instruction match is insufficient proof of these tables.

## Provenance

GCC copyright and runtime/linking exceptions are retained in emitted sources.
The sources carry `licence: gcc-runtime`, and remain covered by the existing
`build.py --without gcc-runtime` exclusion. See `THIRD_PARTY.md`.

## PS2 software floating point

The same staging tool writes public `fp-bit.c` variants for the target, plus
patches documenting the changes before preprocessing. The retained double
packer flushes underflow, truncates guard bits and overflows above `EXPBIAS`.
This reproduces `__pack_d` at `0x005BE250`. Reproduction checks also recover the
two already matched unpackers; these are not new decompiled functions.

The single decoder treats exponent 255 as a normal value. The double decoder
retains the raw NaN fraction, gives infinity `IMPLICIT_1`, and sets the normal
exponent field to `EXPBIAS` in that exceptional branch. Moving the fraction
shift out of the normal branch changes NaN handling and does not match.

The single packer still differs in one branch-likely decision. Its staged
extended-exponent and signed-fraction checks describe a near candidate, not an
accepted implementation. No source is retained until the unchanged judge
accepts every instruction.
