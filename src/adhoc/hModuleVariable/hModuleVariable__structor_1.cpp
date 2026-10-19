#include "gt4/hModuleVariable.h"
typedef int s32;

/* Layout backed by include/gt4/hModuleVariable.h (size 0x1C):
 *   0x00..0x13: base fields (0x04 vtable)
 *   0x14: target (size 4)
 *   0x18: module handle (size 4)
 */
struct hModuleVariableLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[3];
    void *target;
    void *module;
};

extern "C" void func_00323B60(void *arg0, s32 arg1);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void hVariable__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hModuleVariable__vtable;

extern "C" void hModuleVariable__structor_1(void *arg0, s32 arg1) {
    hModuleVariableLayout *self = (hModuleVariableLayout *)arg0;
    self->vtable = &hModuleVariable__vtable;
    func_00323B60(&self->module, 2);
    func_00309378(&self->target, 2);
    hVariable__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x1C, 4, "RefCounter");
    }
}
