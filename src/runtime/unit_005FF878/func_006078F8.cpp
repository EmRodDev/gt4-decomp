/* compiler: ee-gcc2.96-stl */
/* SGI STL public sorting templates instantiated by tools/stl_algo.py.
   Value: 12 bytes; comparator: external; key: int at 0; member: adjust_heap. */
#include <stl_algobase.h>
#include <stl_iterator.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <limits.h>
#include <stdlib.h>
#include <stl_tempbuf.h>
#include <stl_algo.h>
struct SortValue_006078F8 { int words[3]; };
extern "C" bool func_006083D0(const SortValue_006078F8 *, const SortValue_006078F8 *);
struct SortCompare_006078F8 { char state; bool operator()(const SortValue_006078F8 &a, const SortValue_006078F8 &b) const { return func_006083D0(&a, &b); } };
template void __adjust_heap(SortValue_006078F8 *, int, int, SortValue_006078F8, SortCompare_006078F8);
