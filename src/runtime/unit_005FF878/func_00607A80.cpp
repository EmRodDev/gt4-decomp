/* compiler: ee-gcc2.96-stl */
/* SGI STL public sorting templates instantiated by tools/stl_algo.py.
   Value: 12 bytes; comparator: external; key: int at 0; member: push_heap. */
#include <stl_algobase.h>
#include <stl_iterator.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <limits.h>
#include <stdlib.h>
#include <stl_tempbuf.h>
#include <stl_algo.h>
struct SortValue_00607A80 { int words[3]; };
extern "C" bool func_006083D0(const SortValue_00607A80 *, const SortValue_00607A80 *);
struct SortCompare_00607A80 { char state; bool operator()(const SortValue_00607A80 &a, const SortValue_00607A80 &b) const { return func_006083D0(&a, &b); } };
template void __push_heap(SortValue_00607A80 *, int, int, SortValue_00607A80, SortCompare_00607A80);
