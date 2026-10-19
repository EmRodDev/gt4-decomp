#include "types.h"

struct VEntry001BE7E0 {
    s16 delta;
    s16 index;
    void (*fn)(void *, int);
};

struct Sub001BE7E0 {
    char pad0[4];
    VEntry001BE7E0 *vtbl;
};

struct Obj001BE7E0 {
    char pad0[0xA0];
    Sub001BE7E0 *unkA0;
};

extern "C" void mEyetoyFacePS2__virtual_95(struct Obj001BE7E0 *arg0, int arg1) {
    struct Sub001BE7E0 *a2 = arg0->unkA0;
    if (a2 != 0) {
        VEntry001BE7E0 *e = &a2->vtbl[54];
        e->fn((char *)a2 + e->delta, arg1);
    }
}
