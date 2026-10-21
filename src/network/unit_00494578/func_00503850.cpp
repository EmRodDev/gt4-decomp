/* Clears four consecutive integer fields at +0xC..+0x18 of the record (a reset helper, inferred from the shape; the fields are unnamed in the library). */
#include "types.h"

struct Obj {
    char pad[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

extern "C" void func_00503850(Obj *self) {
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
}
