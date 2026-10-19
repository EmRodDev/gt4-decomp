#include "gt4/mMethodDefine.h"
typedef int s32;

/* Layout backed by include/gt4/mMethodDefine.h and config/class_layout.json (size 0x10):
 *   0x00..0x07: base (ref_count, vtable)
 *   0x08: sym_id
 *   0x0C: target code pointer (size 4)
 */
struct mMethodDefineLayout {
    void *ref_count;
    void *vtable;
    s32 sym_id;
    void *target;
};

extern "C" s32 func_002F41F8(void *arg0, s32 arg1);
extern "C" void *mDefine__structor_0(void *arg0);
extern char mMethodDefine__vtable[];

extern "C" s32 mMethodDefine__structor_0(void *arg0, s32 arg1, s32 arg2) {
    mMethodDefineLayout *self = (mMethodDefineLayout *)arg0;
    mDefine__structor_0(self);
    self->vtable = mMethodDefine__vtable;
    return func_002F41F8(&self->target, arg2);
}
