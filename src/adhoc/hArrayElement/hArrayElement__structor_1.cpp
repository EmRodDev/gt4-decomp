#include "gt4/hArrayElement.h"
typedef int s32;

extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

/* Layout backed by include/gt4/hArrayElement.h and config/class_layout.json (size 0x18):
 *   0x00..0x0F: hObject base fields (0x04 vtable)
 *   0x10: unk10 (target array/object reference)
 *   0x14: unk14 (index)
 */
struct hArrayElementLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    void *unk10;
    s32 unk14;
};

extern void *hArrayElement__vtable;

extern "C" void hArrayElement__structor_1(void *arg0, s32 arg1) {
    hArrayElementLayout *self = (hArrayElementLayout *)arg0;
    self->vtable = &hArrayElement__vtable;
    func_00309378(&self->unk10, 2);
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x18, 4, "RefCounter");
    }
}

