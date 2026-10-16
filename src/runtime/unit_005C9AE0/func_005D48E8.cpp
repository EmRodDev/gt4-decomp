/* compiler: ee-gcc2.96-stl */
/* SGI STL heap adjustment for a 44-byte value, signed key at offset 40. */
#include <stl_algobase.h>
#include <stl_heap.h>
struct Heap44 { int words[11]; bool operator<(const Heap44 &o) const { return words[10] < o.words[10]; } };
template void __push_heap(Heap44 *, int, int, Heap44);
