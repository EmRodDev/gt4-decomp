#include "types.h"

extern "C" void func_003286B8(s32 arg0);
extern "C" void func_0030F808(void *arg0, s32 arg1);
extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hInst__vtable;
extern void *mModuleDefine__vtable;

/* Layout backed by config/class_layout.json (size 0x1C) and config/class_fields.json:
 *   0x04: vptr
 *   0x08: module name / handle object (dtor func_0030F808)
 *   0x18: unk18 (released via func_003286B8)
 */
struct mModuleDefineLayout {
    void *ref_count;
    void *vtable;
    char module_handle[0x10];  /* 0x08..0x17 */
    s32 unk18;                 /* 0x18 */
};

extern "C" void hInst__structor_18(mModuleDefineLayout *self, s32 arg1) {
    self->vtable = &mModuleDefine__vtable;
    s32 p = self->unk18;
    if (p != 0) {
        func_003286B8(p);
    }
    func_0030F808(self->module_handle, 2);
    self->vtable = &hInst__vtable;
    RefCounter__structor_2(self, 0);
    if (arg1 & 1) {
        return func_00326798(self, 0x1C, 4, "RefCounter");
    }
}
