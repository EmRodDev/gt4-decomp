/* compiler: ee-gcc2.96-stl */
// func_006012C0: std::random_shuffle<int *, RandGen>
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_tempbuf.h>
#include <stl_heap.h>
#include <stl_algo.h>

extern "C" float func_00579548(void *);

struct RandGen {
    void *state;
    int operator()(int n) {
        return (int)(func_00579548(state) * n);
    }
};

template void random_shuffle(int *, int *, RandGen &);
