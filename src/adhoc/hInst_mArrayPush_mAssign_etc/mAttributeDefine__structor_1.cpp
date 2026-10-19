#include "gt4/mAttributeDefine.h"
typedef int s32;

/* Layout backed by include/gt4/mAttributeDefine.h and config/class_layout.json (size 0x10):
 *   0x00..0x07: base (ref_count, vtable)
 *   0x08: sym_id
 *   0x0C: target handle (size 4)
 */
struct mAttributeDefineLayout {
    void *ref_count;
    void *vtable;
    s32 sym_id;
    void *target;
};

extern "C" void func_00323B60(void *arg0, s32 arg1);
extern "C" void hInst__structor_0(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mAttributeDefine__vtable;

extern "C" void mAttributeDefine__structor_1(void *arg0, s32 arg1) {
    mAttributeDefineLayout *self = (mAttributeDefineLayout *)arg0;
    self->vtable = &mAttributeDefine__vtable;
    func_00323B60(&self->target, 2);
    hInst__structor_0(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
