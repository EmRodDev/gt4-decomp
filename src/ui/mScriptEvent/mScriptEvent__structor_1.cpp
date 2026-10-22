/* Deleting destructor of mScriptEvent (object size 0x28, freed with the allocator name "RefCounter" when bit 0 of flags is set).
 * It resets the vtable at +4, destroys the member at +0x24 (func_002ED5C0, 2), releases the std::string at +0x20, then runs the mEvent base destructor with flag 0. */
#include "gt4/mScriptEvent.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mScriptEvent__vtable;
extern "C" void func_002ED5C0(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void mEvent__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}


extern "C" void mScriptEvent__structor_1(void *self, s32 flags) {
    ((struct mScriptEvent *)self)->unk4 = &mScriptEvent__vtable;
    func_002ED5C0((char *)self + 0x24, 0x2);
    str_release((Str *)((char *)self + 0x20));
    mEvent__structor_1(self, 0x0);
    if ((flags & 0x1) != 0) {
        return func_00326798(self, 0x28, 0x4, "RefCounter");
    }
}
