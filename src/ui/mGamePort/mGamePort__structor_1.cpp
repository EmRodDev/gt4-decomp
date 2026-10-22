/* Deleting destructor of mGamePort (object size 0xC8, freed with the allocator name "RefCounter" when bit 0 of flags is set).
 * It resets the vtable at +4, releases the only owned member, the std::string at +0xC4, and runs the hObject base destructor (hObject__structor_2) with flag 0. */
#include "gt4/mGamePort.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mGamePort__vtable;
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void hObject__structor_2(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}


extern "C" void mGamePort__structor_1(void *self, s32 flags) {
    ((struct mGamePort *)self)->unk4 = &mGamePort__vtable;
    str_release((Str *)((char *)self + 0xc4));
    hObject__structor_2(self, 0x0);
    if ((flags & 0x1) != 0) {
        return func_00326798(self, 0xc8, 0x4, "RefCounter");
    }
}
