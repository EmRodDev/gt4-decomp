#include "gt4/hScriptFunction.h"
typedef int s32;

/* Layout backed by include/gt4/hScriptFunction.h and config/class_layout.json (size 0x10):
 *   0x00..0x0B: hFunctionValue base fields (0x04 vtable)
 *   0x0C: unkC (code object reference)
 */
struct hScriptFunctionLayout {
    void *ref_count;
    void *vtable;
    s32 base_field;
    void *unkC;
};

extern "C" void func_002F4210(void *arg0, s32 arg1);
extern "C" void hFunctionValue__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hScriptFunction__vtable;

extern "C" void hScriptFunction__structor_1(void *arg0, s32 arg1) {
    hScriptFunctionLayout *self = (hScriptFunctionLayout *)arg0;
    self->vtable = &hScriptFunction__vtable;
    func_002F4210(&self->unkC, 2);
    hFunctionValue__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
