/* Deleting destructor of mImageFace (object size 0xF0, freed with the allocator name "RefCounter" when bit 0 of flags is set).
 * After resetting the vtable pointer at +4 it destroys a two-element array of 4-byte members at 0xC0..0xC8 from the last element down (func_00210710, 2),
 * releases the std::string at +0xB8, and runs the mColorFace destructor on the base part. */
#include "gt4/mImageFace.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mImageFace__vtable;
extern "C" void func_00210710(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void mColorFace__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}


extern "C" void mImageFace__structor_1(void *self, s32 flags) {
    ((struct mImageFace *)self)->unk4 = &mImageFace__vtable;
    if ((char *)self + 0xc0 != 0) {
        char *element = (char *)self + 0xc8;
        while ((char *)self + 0xc0 != element) {
            element -= 0x4;
            func_00210710(element, 0x2);
        }
    }
    str_release((Str *)((char *)self + 0xb8));
    mColorFace__structor_1(self, 0x0);
    if ((flags & 0x1) != 0) {
        return func_00326798(self, 0xf0, 0x4, "RefCounter");
    }
}
