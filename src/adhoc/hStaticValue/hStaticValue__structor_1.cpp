#include "gt4/hStaticValue.h"
typedef int s32;

extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void hValue__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

/* Layout backed by include/gt4/hStaticValue.h and config/class_layout.json (size 0x10):
 *   0x00..0x0B: hValue base fields (0x04 vtable)
 *   0x0C: unkC (embedded object / static value)
 */
extern void *hStaticValue__vtable;

extern "C" void hStaticValue__structor_1(void *arg0, s32 arg1) {
    struct hStaticValue *self = (struct hStaticValue *)arg0;
    self->unk4 = &hStaticValue__vtable;
    func_00309378(&self->unkC, 2);
    hValue__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}

