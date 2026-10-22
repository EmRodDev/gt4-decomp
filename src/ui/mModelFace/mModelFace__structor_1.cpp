/* Deleting destructor of mModelFace (object size 0x30c, freed when bit 0 of flags is set, using the allocator name "RefCounter").
 * Resets the vtable pointer at +4, then tears members down from the highest offset: handle at 0x2DC, std::string at 0x2D8, a two-entry array at 0x2D0..0x2D8 (func_00210710),
 * std::string 0x2C8, a two-entry array 0x2C0..0x2C8 (func_0021B5D0), std::string 0x2B8, then the member at 0x154 (four 0x54-byte entries, each with four
 * sub-objects at +0x14/+0x24/+0x34/+0x44 plus one at +4), MModel at 0xA0 and finally the mWidget base. The loops count down by element size, as the compiler emitted them. */
#include "gt4/mModelFace.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mModelFace__vtable;
extern "C" void func_0021B340(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_00210710(void *, s32);
extern "C" void func_0021B5D0(void *, s32);
extern "C" void func_00203118(void *, s32);
extern "C" void MModel__structor_1(void *, s32);
extern "C" void mWidget__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *rep = (Rep *)(s->p - 0x10);
    if (--rep->ref == 0) {
        s32 size = rep->cap + 0x10;
        func_00326798(rep, size, 4, func_005C11A8()->name);
    }
}

static inline void member_0(char *arrayBase) {
    if ((char *)arrayBase + 0x14 != 0) {
        char *element = arrayBase + 0x164;
        while (arrayBase + 0x14 != element) {
            element -= 0x54;
            func_00203118((char *)element + 0x44, 0x2);
            func_00203118((char *)element + 0x34, 0x2);
            func_00203118((char *)element + 0x24, 0x2);
            func_00203118((char *)element + 0x14, 0x2);
        }
    }
    func_00203118(arrayBase + 0x4, 0x2);
}

extern "C" void mModelFace__structor_1(void *self, s32 flags) {
    ((struct mModelFace *)self)->unk4 = &mModelFace__vtable;
    func_0021B340((char *)self + 0x2dc, 0x2);
    str_release((Str *)((char *)self + 0x2d8));
    if ((char *)self + 0x2d0 != 0) {
        char *elem0 = (char *)self + 0x2d8;
        while ((char *)self + 0x2d0 != elem0) {
            elem0 -= 0x4;
            func_00210710(elem0, 0x2);
        }
    }
    str_release((Str *)((char *)self + 0x2c8));
    if ((char *)self + 0x2c0 != 0) {
        char *elem1 = (char *)self + 0x2c8;
        while ((char *)self + 0x2c0 != elem1) {
            elem1 -= 0x4;
            func_0021B5D0(elem1, 0x2);
        }
    }
    str_release((Str *)((char *)self + 0x2b8));
    member_0((char *)self + 0x154);
    MModel__structor_1((char *)self + 0xa0, 0x2);
    mWidget__structor_1(self, 0x0);
    if ((flags & 0x1) != 0) {
        return func_00326798(self, 0x30c, 0x4, "RefCounter");
    }
}
