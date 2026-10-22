/* Deleting destructor of mWindowContext (object size 0x34, freed with the allocator name "RefCounter" when bit 0 of flags is set).
 * The only member is an STL-style tree at +0x20: header node pointer at +4, node count at +8. member_0 clears it when the count is non-zero
 * (func_005DECE0 erases from the root held in the header at +4, then the header's leftmost/rightmost links at +8/+0xC point back to the header and the count becomes 0),
 * then frees the 0x18-byte header node with the allocator name from func_005DF780. hObject__structor_2 destroys the base. */
#include "gt4/mWindowContext.h"
typedef int s32;

extern void *mWindowContext__vtable;
extern "C" void func_005DECE0(void *, void *);
extern "C" void *func_005DF780(void);
extern "C" void func_00326798(void *, s32, s32, const void *);
extern "C" void hObject__structor_2(void *, s32);
static inline void member_0(char *tree) {
    if (*(void **)(tree + 0x8) != 0) {
        func_005DECE0(tree, *(void **)((char *)*(void **)(tree + 0x4) + 0x4));
        *(void **)((char *)*(void **)(tree + 0x4) + 0x8) = *(void **)(tree + 0x4);
        *(void **)((char *)*(void **)(tree + 0x4) + 0x4) = 0x0;
        *(void **)((char *)*(void **)(tree + 0x4) + 0xc) = *(void **)(tree + 0x4);
        *(void **)(tree + 0x8) = 0x0;
    }
    void *headerNode = *(void **)(tree + 0x4);
    void *allocName = func_005DF780();
    func_00326798(headerNode, 0x18, 0x4, *(void **)(allocName));
}

extern "C" void mWindowContext__structor_1(void *self, s32 flags) {
    ((struct mWindowContext *)self)->unk4 = &mWindowContext__vtable;
    member_0((char *)self + 0x20);
    hObject__structor_2(self, 0x0);
    if ((flags & 0x1) != 0) {
        return func_00326798(self, 0x34, 0x4, "RefCounter");
    }
}
