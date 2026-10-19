#include "gt4/hMethodObject.h"
typedef int s32;

/* Layout backed by include/gt4/hMethodObject.h (size 0x18):
 *   0x00..0x0F: base fields (0x04 vtable)
 *   0x10: target object (size 4)
 *   0x14: method pointer (size 4)
 */
struct hMethodObjectLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    void *target;
    void *method;
};

extern "C" void func_003038E0(void *arg0, s32 arg1);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hMethodObject__vtable;

extern "C" void hMethodObject__structor_1(void *arg0, s32 arg1) {
    hMethodObjectLayout *self = (hMethodObjectLayout *)arg0;
    self->vtable = &hMethodObject__vtable;
    func_003038E0(&self->method, 2);
    func_00309378(&self->target, 2);
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x18, 4, "RefCounter");
    }
}
