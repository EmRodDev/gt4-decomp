# SGI STL sorting families

The library region contains sorting-template instantiations in addition to the
red-black trees handled by `tools/stl.py`. `tools/stl_algo.py` instantiates the
public GCC 2000-10-03 SGI headers already retained in `include/stl/`, using the
same no-strict-aliasing/no-implicit-templates compiler profile.

## First closed families

A 44-byte trivially copied value has a signed integer ordering key at offset
40. The actual public `__adjust_heap` body reproduces 122 instructions at
`0x005D45B8`; its `__push_heap` callee reproduces 124 at `0x005D48E8`.
The family also supplies exact `__make_heap`, `sort_heap`, `__insertion_sort`,
`__final_insertion_sort`, `__introsort_loop`, `__partial_sort` and
`__unguarded_partition` instantiations. All nine objects enter the complete
byte-identical executable.

A second layout copies 12-byte values and passes a one-byte comparator object.
The comparator's inline call operator forwards to the actual external boolean
comparison function; its state byte remains part of the original ABI. This
recovers two `__push_heap` and two `__adjust_heap` copies in separate units.
The four objects also enter the complete byte-identical executable.

Reproduce the family search with:

```sh
python3 tools/stl_algo.py --size 44 --key-offset 40
python3 tools/stl_algo.py --size 12 --comparator external
python3 tools/organize.py
python3 tools/build.py --jobs 2
```

Already present sources are left in place. A scan's exact code candidates are
not accepted on a loose relocation comparison: each receives address-specific
type names, real call-target aliases, and the unchanged judge. The full link
resolves those aliases and compares all code/data bytes again. Address-specific
type names avoid collisions between separately placed copies of the same
layout. They do not assert the game's original C++ type names.

The 44-byte value's actual semantic class remains unidentified. A recovered
algorithm and field layout do not establish what gameplay data it sorts.

## Handle/key sorting family (2026-10-16)

`knowledge/recipes/scored_sort.py` reconstructs 24 additional template
instantiations in the `005C1CE0` unit. The algorithm bodies come directly from
`include/stl/stl_algo.h` and `stl_heap.h`; their existing licence notices and
`THIRD_PARTY.md` entry apply. The recipe writes drafts only, leaving `src/`
and existing matches untouched:

```sh
python knowledge/recipes/scored_sort.py
python tools/match.py check 005C5908 build/swarm/scored-sort/reproduced/func_005C5908.cpp
```

All three element layouts start with a four-byte reference-counted handle.
Copy construction calls `0013BD50`; destruction calls `0013BD68(this, 2)`.
Assignment checks self-assignment, retains the incoming object through
`003285A8`, releases the previous object through `003285F8`, and stores the
incoming pointer. The implicit aggregate operations then copy the key.

- Float: eight-byte record, floating-point score at offset four.
- String: eight-byte record, string pointer at offset four, ordered by the
  signed result of `0057F238` (strcmp).
- Sequence: twenty-byte record, a wrapped sixteen-byte
  `vector<unsigned short, tagged allocator>` at offset four. The allocator
  uses type getter `005C1368` with `00326750`/`00326798`; vector assignment
  calls the existing `005C5790`. Comparison forwards the two iterator ranges
  to the existing lexicographical comparison `005C97E0`.

The comparator contains one byte. An empty comparator changes the copies
passed between helpers and does not match. The compiler's by-value object ABI
makes each callee destroy its incoming value: a partition destroys its pivot,
and heap/insertion helpers destroy their copied argument. The public templates
and ordinary C++ lifetime rules reproduce those calls without explicit stack
stores or forced registers.

| Public template | Float | String | Sequence |
|---|---|---|---|
| `__introsort_loop` | 005C65E0 | 005C6DA8 | 005C5908 |
| `__unguarded_partition` | 005C7988 | 005C7E68 | 005C7098 |
| `__partial_sort` | 005C7AD8 | 005C7F98 | 005C7300 |
| `__insertion_sort` | 005C7C48 | 005C80F0 | 005C75A0 |
| `sort_heap` | 005C8AA8 | 005C8F18 | 005C8300 |
| `__make_heap` | existing 005C8BE0 | existing 005C9050 | 005C8588 |
| `__adjust_heap` | 005C8C88 | 005C90F8 | 005C86C0 |
| `__push_heap` | 005C9550 | 005C9698 | 005C9378 |
| `__unguarded_linear_insert` | existing 005C8E20 | existing 005C9288 | 005C8950 |
| `__unguarded_insertion_sort_aux` | existing 005C7DF0 | existing 005C8288 | 005C7888 |

Macros map the public template names to address-bearing symbols before the
headers are included. In particular, map `__make_heap`, whose last two
arguments are type-deduction pointers, rather than the inline `make_heap`
wrapper. Address-specific types keep independently placed instantiations
separate. Seven callers require a return-bearing copy-helper declaration;
`005C75A0` also requires the vector assignment helper to be declared
`throw()`. Both affect scheduling, and the recipe retains the individually
verified declarations instead of changing compiler flags.

The descriptive type names do not establish the original gameplay classes.
`FloatSortEntry`, `StringSortEntry`, and `SequenceSortEntry` describe the
observed layouts; `RefCountedHandle` makes their ownership rules explicit.
Their address suffixes keep separate original instantiations from merging.
The recipe contains the shared reconstruction model, while each emitted C++
translation unit remains self-contained and readable. Changes to that model
must be regenerated, rejudged, and checked in the full link. The repository's
clean-source metric is useful for finding raw decompiler output, but does not
replace a review of behavior, names, ownership, or maintainability.

The higher-level sort wrappers at `005C5D18`, `005C60A0`, and `005C6868`
remain targets for a later batch. Start from the proven element models and
read their attempts diaries before trying those wrappers again.

### Complete-link evidence

Source commit `3da8aeeba98ede1bfa7d6d1db3e03802977f9ca7`, based on
upstream `f5f0cdc5b945ac640656bc0142b9f21badfe9f85`, passed the complete,
non-partial build on 2026-10-16. All 24 additions are individually `linked`,
with zero orphan or duplicate sources. Linked code increases from 4,151,644
to 4,162,064 bytes: **10,420 additional bytes**, excluding inventory padding.

| Key family | New functions | Linked bytes |
|---|---:|---:|
| Float | 7 | 2,580 |
| String | 7 | 2,496 |
| Unsigned-short sequence | 10 | 5,344 |
| Total | 24 | 10,420 |

The build reproduced both original loaded segments:

- `.text` SHA-1: `28422e7e20a6298224294255355487b9a22cef31`
- `.data` SHA-1: `c28c833f9716467545bf362f321e9acc876c3603`

All 85 existing regression tests passed. Each reviewed source passed the
unchanged judge after the naming/ownership cleanup and reproduces byte-for-byte
from the recipe; source organization and assembly policy checks passed.
The clean-source scanner finds no raw-decompiler marks in these 24 sources;
the semantic review additionally checked handle lifetimes, retain-before-release
assignment, key comparisons, nested vector allocation/destruction, and real
callee targets in the complete link.

The generated report records 29,064 / 30,962 matched functions (93.87%),
4,208,792 matched code bytes (79.68%), and 78.80% linked code. The subsequent
README/documentation commit describes this source commit and changes no code.

### Upstream refresh after PR #22

The conflict-resolution merge `9f97908ca01a871fa588da3b235aef9d13aab82a`
includes upstream `ab5ca09f43e1380ead55cccb825d2a759aff3e08` and preserves
all 24 sorting sources byte-for-byte. Both attempt histories are retained.
All 24 sources reproduce from the recipe and pass the unchanged judge; all
85 regression tests, source organization, and assembly policy checks pass.
The complete non-partial build reproduces the same original segment hashes
above, with no orphan or duplicate sources. Linked code is 4,162,536 bytes,
a gain of 10,420 bytes over the refreshed upstream's 4,152,116 bytes.
The combined report records 29,068 matched functions and 4,209,264 matched
code bytes (79.69%); all 24 additions are linked. The README was regenerated
from this clean source proof.
