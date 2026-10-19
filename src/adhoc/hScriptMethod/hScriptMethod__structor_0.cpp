#include "gt4/hScriptMethod.h"
typedef int s32;

/* Layout backed by include/gt4/hScriptMethod.h and config/class_layout.json (size 0x10):
 *   0x00..0x0B: hMethodValue base fields (0x04 vtable)
 *   0x0C: unkC (method code reference)
 */
struct hScriptMethodLayout {
    void *ref_count;
    void *vtable;
    s32 base_field;
    void *unkC;
};

extern "C" s32 func_002F41F8(void *arg0, s32 arg1);
extern "C" void *hMethodValue__structor_0(void *arg0);
extern char hScriptMethod__vtable[];

extern "C" s32 hScriptMethod__structor_0(void *arg0, s32 arg1, s32 arg2) {
    hScriptMethodLayout *self = (hScriptMethodLayout *)arg0;
    hMethodValue__structor_0(self);
    self->vtable = hScriptMethod__vtable;
    return func_002F41F8(&self->unkC, arg2);
}
