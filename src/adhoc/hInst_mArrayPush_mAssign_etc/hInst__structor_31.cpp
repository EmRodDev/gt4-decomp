#include "types.h"

/* Layout backed by config/class_layout.json (mUndef size 0x18):
 *   0x00: ref_count
 *   0x04: vtable (mUndef)
 *   0x08: sym_id / path at 0x08
 */
struct mUndefLayout {
    void *ref_count;
    void *vtable;
    char path[0x10];
};

extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_0030F808(void *arg0, s32 arg1);

extern void *hInst__vtable;
extern void *mUndef__vtable;

extern "C" void hInst__structor_31(void *arg0, s32 arg1) {
    mUndefLayout *self = (mUndefLayout *)arg0;
    self->vtable = &mUndef__vtable;
    func_0030F808(self->path, 2);
    self->vtable = &hInst__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x18, 4, "RefCounter");
    }
}
