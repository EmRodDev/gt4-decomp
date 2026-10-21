/* Returns the field at +4 of element arg1 in the array of 0x70-byte elements pointed to by the field at +0x44. No bounds check. */
#include "types.h"

struct Elem {
    char pad0[4];
    s32 unk4;
    char pad8[0x68];
};

struct Obj {
    char pad[0x44];
    Elem *unk44;
};

extern "C" s32 func_004EE678(struct Obj *self, s32 index) {
    return self->unk44[index].unk4;
}
