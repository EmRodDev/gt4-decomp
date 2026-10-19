#include "gt4/mFunctionDefine.h"
typedef int s32;

/* Layout backed by include/gt4/mFunctionDefine.h and config/class_layout.json (size 0x10):
 *   0x00..0x07: base (ref_count, vtable)
 *   0x08: sym_id
 *   0x0C: target code pointer (size 4)
 */
struct mFunctionDefineLayout {
    void *ref_count;
    void *vtable;
    s32 sym_id;
    void *target;
};

extern "C" void func_002F4210(void *arg0, s32 arg1);
extern "C" void hInst__structor_0(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mFunctionDefine__vtable;

extern "C" void mFunctionDefine__structor_1(void *arg0, s32 arg1) {
    mFunctionDefineLayout *self = (mFunctionDefineLayout *)arg0;
    self->vtable = &mFunctionDefine__vtable;
    func_002F4210(&self->target, 2);
    hInst__structor_0(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
