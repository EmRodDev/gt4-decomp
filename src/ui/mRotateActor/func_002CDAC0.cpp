/* Copies one of two float fields into +0x20 according to the flag at +0x2C: +0x1C when the flag is nonzero, +0x18 otherwise (a pick between two alternatives; their meaning is unknown). */
#include "types.h"

struct Obj {
    char pad0[0x18];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    char pad1[0x2C - 0x20 - 4];
    s32 unk2C;
};

extern "C" void func_002CDAC0(struct Obj *actor) {
    if (actor->unk2C != 0) {
        actor->unk20 = actor->unk1C;
        return;
    }
    actor->unk20 = actor->unk18;
}
