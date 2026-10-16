/* compiler: ee-gcc2.96-stl */
/* SGI STL public sorting templates instantiated by tools/stl_algo.py.
   Value: 44 bytes; comparator: member; key: int at 40; member: make_heap. */
#include <stl_algobase.h>
#include <stl_iterator.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <limits.h>
#include <stdlib.h>
#include <stl_tempbuf.h>
#include <stl_algo.h>
struct SortValue_005D44C0 { char prefix[40]; int key; bool operator<(const SortValue_005D44C0 &o) const { return key < o.key; } };
template void __make_heap(SortValue_005D44C0 *, SortValue_005D44C0 *, SortValue_005D44C0 *, int *);
