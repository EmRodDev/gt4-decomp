#include "gt4/mOptionMenu.h"
typedef int s32;

extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_002F9B38(void *, s32);
extern "C" void mFBox__structor_1(void *, s32);

extern void *mOptionMenu__vtable;

struct mOptionMenuInternal {
    void *vptr0;
    void *unk4;
    char pad8[0xC4];
    void *pCC[3];
};

extern "C" void mOptionMenu__structor_1(mOptionMenuInternal *arg0, s32 arg1) {
    arg0->unk4 = &mOptionMenu__vtable;
    func_002F9B38(&arg0->pCC[2], 2);
    func_002F9B38(&arg0->pCC[1], 2);
    func_002F9B38(&arg0->pCC[0], 2);
    mFBox__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x120, 4, "RefCounter");
    }
}
