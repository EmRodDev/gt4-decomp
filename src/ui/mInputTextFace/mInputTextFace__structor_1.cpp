/* Deleting destructor of mInputTextFace (object size 0xDF0, large because of the member block at 0x578; freed with the allocator name "RefCounter" when bit 0 of flags is set).
 * Members go in reverse order: the object at 0x578 (func_004B4400), six 0x10-byte objects at 0x154, 0x144, 0x134, 0x124, 0x114 and 0x104 and one at 0xE0 (all func_00203118, 2),
 * then the member at 0xA0, whose destructor (member_dtor_0) releases the std::string at +0x10 and then runs func_00203118 on +0. The mWidget base destructor finishes it.
 * The repeated func_00203118 calls are individual members, not a loop, because the offsets are not evenly spaced as a whole. */
#include "gt4/mInputTextFace.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mInputTextFace__vtable;
extern "C" void func_004B4400(void *, s32);
extern "C" void func_00203118(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void mWidget__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}


static inline void member_dtor_0(char *m) {
    str_release((Str *)(m + 0x10));
    func_00203118(m, 2);
}
extern "C" void mInputTextFace__structor_1(void *self, s32 flags) {
    ((struct mInputTextFace *)self)->unk4 = &mInputTextFace__vtable;
    func_004B4400((char *)self + 0x578, 0x2);
    func_00203118((char *)self + 0x154, 0x2);
    func_00203118((char *)self + 0x144, 0x2);
    func_00203118((char *)self + 0x134, 0x2);
    func_00203118((char *)self + 0x124, 0x2);
    func_00203118((char *)self + 0x114, 0x2);
    func_00203118((char *)self + 0x104, 0x2);
    func_00203118((char *)self + 0xe0, 0x2);
    member_dtor_0((char *)self + 0xa0);
    mWidget__structor_1(self, 0x0);
    if ((flags & 0x1) != 0) {
        return func_00326798(self, 0xdf0, 0x4, "RefCounter");
    }
}
