#include "gt4/mNetConfPS2.h"
typedef int s32;

extern void *mNetConfPS2__vtable;
extern "C" void mNetConf__structor_2(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
struct Table {
    char pad[0x38];
    VEntry_vcall_0 *vtbl;
};

static inline void vcall_0(Table *o, s32 a0) {
    VEntry_vcall_0 *e = &o->vtbl[1];
    e->fn((char *)o + e->delta, a0);
}

struct mNetConfPS2Layout {
    void *vptr0;
    void *unk4;
    char pad8[0x260];
    Table *table;
};

extern "C" void mNetConfPS2__structor_2(mNetConfPS2Layout *arg0, s32 arg1) {
    arg0->unk4 = &mNetConfPS2__vtable;
    if (arg0->table != 0) {
        vcall_0(arg0->table, 0x3);
    }
    mNetConf__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x470, 0x4, "RefCounter");
    }
}
