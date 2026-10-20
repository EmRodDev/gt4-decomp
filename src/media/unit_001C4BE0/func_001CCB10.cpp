#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *);
};

struct Obj {
    char pad0[0x4C];
    VEntry *vtbl;
};

extern "C" void func_004AE6B0(void *arg0, s32 arg1);

extern "C" s32 func_001CCB10(Obj *self) {
    s32 sum = 0;
    s32 buf[8];
    VEntry *e = &self->vtbl[17];
    void *cur = e->fn((char *)self + e->delta);
    s32 *p = (s32 *)cur;
    while (*p != 0) {
        func_004AE6B0(buf, *p);
        p++;
        u32 v_buf = buf[2];
        sum += (v_buf + 0x3FF) >> 10;
    }
    return sum;
}
