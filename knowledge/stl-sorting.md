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
