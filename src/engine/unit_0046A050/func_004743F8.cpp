/* Builds a four-word record {0, 0, source.a, source.b} on the stack and passes it with target to func_0047E880. */
#include "types.h"

extern "C" void func_0047E880(s32 source, void *target);

struct func_004743F8_pair {
    s32 a;
    s32 b;
};

struct func_004743F8_src {
    char pad0[0x10];
    struct func_004743F8_pair p;
};

struct func_004743F8_loc {
    s32 z0;
    s32 z1;
    struct func_004743F8_pair p;
};

extern "C" void func_004743F8(void *source, s32 target) {
    struct func_004743F8_loc loc;
    struct func_004743F8_src *src = (struct func_004743F8_src *)source;

    loc.z0 = 0;
    loc.z1 = 0;
    loc.p = src->p;
    func_0047E880(target, &loc);
}
