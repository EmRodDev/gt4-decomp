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

extern "C" s32 func_002F41F8(void *arg0, s32 arg1);
extern "C" void *hFunctionValue__structor_0(void *arg0);
extern char hScriptFunction__vtable[];

extern "C" s32 hScriptFunction__structor_0(void *arg0, s32 arg1, s32 arg2) {
    hScriptFunctionLayout *self = (hScriptFunctionLayout *)arg0;
    hFunctionValue__structor_0(self);
    self->vtable = hScriptFunction__vtable;
    return func_002F41F8(&self->unkC, arg2);
}
