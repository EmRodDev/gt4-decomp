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

extern "C" void func_002F4210(void *arg0, s32 arg1);
extern "C" void hMethodValue__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hScriptMethod__vtable;

extern "C" void hScriptMethod__structor_1(void *arg0, s32 arg1) {
    hScriptMethodLayout *self = (hScriptMethodLayout *)arg0;
    self->vtable = &hScriptMethod__vtable;
    func_002F4210(&self->unkC, 2);
    hMethodValue__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x10, 4, "RefCounter");
    }
}
