/* Deleting destructor of an object that holds an array of 32 sub-objects of 0x48 bytes at +0x54 (destroyed back to front with func_005037F0; the odd 'arg0 != -0x54' test is the compiler's null check on the array address), three list heads at +0x30, +0x3C and +0x48 reset like in func_004AD240 and a base part destroyed by func_00574DA8; when bit 0 of the flags is set the object is freed (func_005C1628). Shape inferred from the compiler idiom; the element type is not determined. */
#include "types.h"

struct func_005039A8_obj {
    char pad0[8];
    s32 unk8;
};

extern char D_006897A0[];

extern "C" void func_005037F0(void *, s32);
extern "C" void func_0057CA38(void *, s32);
extern "C" void func_00574DA8(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void func_005039A8(void *self, s32 deleteFlags) {
    char *elementEnd;
    char *arrayStart;
    struct func_005039A8_obj *list48;
    struct func_005039A8_obj *list3C;
    struct func_005039A8_obj *list30;

    if ((char *)self != (char *)-0x54) {
        elementEnd = (char *)self + 0x954;
        arrayStart = (char *)self + 0x54;
        if (arrayStart != elementEnd) {
            do {
                func_005037F0(elementEnd - 0x48, 2);
                elementEnd -= 0x48;
            } while (arrayStart != elementEnd);
        }
    }
    list48 = (struct func_005039A8_obj *)((char *)self + 0x48);
    list48->unk8 = (s32)D_006897A0;
    func_0057CA38(list48, 0);
    list3C = (struct func_005039A8_obj *)((char *)self + 0x3C);
    list3C->unk8 = (s32)D_006897A0;
    func_0057CA38(list3C, 0);
    list30 = (struct func_005039A8_obj *)((char *)self + 0x30);
    list30->unk8 = (s32)D_006897A0;
    func_0057CA38(list30, 0);
    func_00574DA8(self, 2);
    if ((deleteFlags & 0x1) != 0) {
        return func_005C1628(self);
    }
}
