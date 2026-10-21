/* Returns the product of the integer fields at +0x40 and +0x4C (two dimensions multiplied; meaning unknown). */
#include "types.h"

struct Obj {
    char pad0[0x40];
    s32 unk40;
    char pad1[0x8];
    s32 unk4C;
};

extern "C" s32 func_00328A60(Obj *self) {
    return self->unk40 * self->unk4C;
}
