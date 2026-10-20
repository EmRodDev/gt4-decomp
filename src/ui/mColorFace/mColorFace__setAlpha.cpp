#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, int);
};

/* Layout backed by include/gt4/mColorFace.h: slot 59 (0x1D8 / 8) */
struct Obj {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void mColorFace__setAlpha(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[59];

    e->fn((char *)arg0 + e->delta, -1);
}
