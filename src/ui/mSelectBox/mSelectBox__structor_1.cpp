/* Deleting destructor of mSelectBox (object size 0xFC, freed with the allocator name "RefCounter" when bit 0 of flags is set).
 * The vtable at +4 is reset, the heap buffer pointed to by +0xF0 is cleared and handed back to the heap free routine when it is non-null, the member at +0xF4 is destroyed (func_002F9B38, 2)
 * and the mScrollable base destructor runs with flag 0. Buffer contents and the owning array's meaning are not known. */
#include "gt4/mSelectBox.h"
typedef int s32;

extern "C" void free(void *self);
extern "C" void func_00326798(void *self, s32 flags, s32 arg2, const char *arg3);
extern "C" void func_002F9B38(void *, s32);
extern "C" void mScrollable__structor_1(void *, s32);

extern void *mSelectBox__vtable;

extern "C" void mSelectBox__structor_1(void *self, s32 flags) {
    ((struct mSelectBox *)self)->unk4 = &mSelectBox__vtable;
    void *buffer = ((struct mSelectBox *)self)->unkF0;
    if (buffer != 0) {
        ((struct mSelectBox *)self)->unkF0 = 0;
        free(buffer);
    }
    func_002F9B38((char *)self + 0xF4, 2);
    mScrollable__structor_1(self, 0);
    if (flags & 1) {
        return func_00326798(self, 0xFC, 4, "RefCounter");
    }
}
