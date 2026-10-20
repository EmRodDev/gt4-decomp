#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Obj {
    char pad[0x20];
    VEntry *vtbl;
};

extern "C" s32 func_0041B5F0(s32 arg0, Obj *arg1) {
    VEntry *e = arg1->vtbl + 1;
    ((void (*)(s32, char *))e->fn)(arg0, (char *)arg1 + e->delta);
    return arg0;
}
