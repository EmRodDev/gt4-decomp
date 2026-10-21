/* Returns the integer at +8 of the object that the field at +0x1C points to. Getter twin of func_003065B0. */
#include "types.h"

struct UnkStruct {
    char pad[0x8];
    s32 unk8;
};

struct Obj {
    char pad[0x1C];
    UnkStruct *unk1C;
};

extern "C" s32 func_003065D8(Obj *self) {
    return self->unk1C->unk8;
}
