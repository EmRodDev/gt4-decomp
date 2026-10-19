#include "gt4/hFunctionObject.h"
typedef int s32;

/* Layout backed by include/gt4/hFunctionObject.h (size 0x14):
 *   0x00..0x0F: base fields (0x04 vtable)
 *   0x10: unk10 (function pointer reference)
 */
struct hFunctionObjectLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    void *unk10;
};

extern "C" void func_002FA8D0(void *arg0, s32 arg1);
extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hFunctionObject__vtable;

extern "C" void hFunctionObject__structor_1(void *arg0, s32 arg1) {
    hFunctionObjectLayout *self = (hFunctionObjectLayout *)arg0;
    self->vtable = &hFunctionObject__vtable;
    func_002FA8D0(&self->unk10, 2);
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x14, 4, "RefCounter");
    }
}
