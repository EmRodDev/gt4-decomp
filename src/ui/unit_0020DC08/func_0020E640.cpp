#include "types.h"

struct VEntry_0020E640 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Inner_0020E640 {
    char pad0[4];
    VEntry_0020E640 *vtbl;
};

struct Obj_0020E640 {
    char pad[8];
    Inner_0020E640 *unk8;
};

extern "C" void func_0020E640(struct Obj_0020E640 *arg0) {
    Inner_0020E640 *a1 = arg0->unk8;
    VEntry_0020E640 *e = &a1->vtbl[54];

    e->fn((char *)a1 + e->delta);
}
