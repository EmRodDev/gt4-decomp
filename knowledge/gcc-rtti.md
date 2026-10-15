# GCC 2.96 RTTI block

The old C++ ABI RTTI implementations in the public GCC 2000-10-03 snapshot,
`gcc/cp/tinfo.cc` and `tinfo2.cc`, reproduce all **45 functions / 6,344 code bytes**
in their GT4 block at `0x005BFAC8..0x005C1498` (padding is not counted).
Eight previously missing functions account for **4,136 bytes**:

| Address | GCC function |
|---|---|
| 005BFC20 | `__user_type_info::dyncast` |
| 005BFE78 | `__si_type_info::do_upcast` |
| 005BFF28 | `__si_type_info::do_dyncast` |
| 005C00E0 | `__class_type_info::do_upcast` |
| 005C0320 | `__class_type_info::do_dyncast` |
| 005C0760 | `__class_type_info::do_find_public_subobj` |
| 005C08F0 | `__throw_type_match_rtti_2` |
| 005C0E00 | `__throw_type_match_rtti` |

This closes the two RTTI source units. Allocation and exception-unwinding code
outside this range are separate work.

## Reproduce

Use the public GCC snapshot already documented in THIRD_PARTY.md, with no game
files in the staging directory:

```sh
python3 tools/stage_gcc_rtti.py --gcc-tree ../gcc-20001003
python3 tools/libmatch.py scan gcc-rtti
python3 tools/libmatch.py emit gcc-rtti -j 2
python3 -m unittest discover -s tests -p test_libmatch.py -v
python3 tools/build.py --keep-going --jobs 2
```

The scan finds 45/45 matches. Emission skips functions that already have sources.
The full build remains the final check of relocated calls, constants and data.

## Validation

The 45 existing/emitted function sources, plus the additional RaceDisplay
long-format initializer at `0x0039C318`, pass `match.py check-many`: **46/46**.
The extraction regression suite has six passing checks and runs in GitHub Actions.

## Compiler context

Use the project's default compiler flags, including strict aliasing. Disabling
strict aliasing changes instruction scheduling in `__user_type_info::dyncast` and
`__class_type_info::do_dyncast`, despite preserving their logic.

The ABI has 32-bit pointers and size_t, 8-bit bytes, and the compiler's original
bool and class layout. The staging tool supplies only the minimal stddef.h and
tconfig.h definitions needed by these public headers.

In tinfo.cc, type_info::operator== is defined before the traversal methods, and
GCC infers that it cannot throw. Extracting a traversal method alone loses that
fact. The library configuration adds throw() to that declaration **only for
tinfo.cc**. Applying it to tinfo2.cc changes a branch in the type matcher because
that unit does not contain the earlier definition.

The seventeen builtin type descriptors are shared objects in the original
tinfo2.cc unit. Extracted functions declare those objects extern; defining copies
would prevent the full build from placing the functions at their original
addresses.

## Provenance

The new RTTI sources are extracted from the published GCC implementation, with
its copyright and runtime exception retained. They are marked
`licence: gcc-runtime`, so the existing `build.py --without gcc-runtime` policy
continues to apply. No game binaries, data or assembly dumps are committed.
