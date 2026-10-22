/* Deleting destructor of mInputNumberFace (object size 0x124, freed with the allocator name "RefCounter" when bit 0 of flags is set).
 * Resets the vtable at +4, releases the std::string at +0x104, destroys the member at 0xE0 (func_00203118) and the one at 0xA0 (member_0 = string at +0x10 then func_00203118 on it),
 * and finishes with the mWidget base destructor. A shorter relative of the mInputTextFace destructor: it has only three members. */
#include "gt4/mInputNumberFace.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mInputNumberFace__vtable;
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_00203118(void *, s32);
extern "C" void mWidget__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline void member_0(char *m) {
    str_release((Str *)(m + 0x10));
    func_00203118(m, 0x2);
}

extern "C" void mInputNumberFace__structor_1(void *self, s32 flags) {
    ((struct mInputNumberFace *)self)->unk4 = &mInputNumberFace__vtable;
    str_release((Str *)((char *)self + 0x104));
    func_00203118((char *)self + 0xe0, 0x2);
    member_0((char *)self + 0xa0);
    mWidget__structor_1(self, 0x0);
    if ((flags & 0x1) != 0) {
        return func_00326798(self, 0x124, 0x4, "RefCounter");
    }
}
