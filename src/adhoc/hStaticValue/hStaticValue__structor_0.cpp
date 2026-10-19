#include "gt4/hStaticValue.h"
typedef int s32;

extern "C" s32 func_00309360(void *arg0, s32 arg1);
extern "C" void *hValue__structor_0(void *arg0);
/* Layout backed by include/gt4/hStaticValue.h and config/class_layout.json (size 0x10):
 *   0x00..0x0B: hValue base fields (0x04 vtable)
 *   0x0C: unkC (embedded object / static value)
 */
extern char hStaticValue__vtable[];

extern "C" s32 hStaticValue__structor_0(void *arg0, s32 arg1, s32 arg2) {
    struct hStaticValue *self = (struct hStaticValue *)arg0;
    hValue__structor_0(self);
    self->unk4 = hStaticValue__vtable;
    return func_00309360(&self->unkC, arg2);
}

