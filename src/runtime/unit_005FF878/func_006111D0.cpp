/* Reset helper: clears +8, copies +0 to +0x1C and +0x20, and copies +4 to +0xC. Field purposes unknown. */
#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char pad0x10[0x1C - 0x10];
    s32 unk1C;
    s32 unk20;
};

extern "C" void func_006111D0(Obj *self) {
    s32 start;

    start = self->unk0;
    self->unk8 = 0;
    self->unk1C = start;
    self->unkC = self->unk4;
    self->unk20 = start;
}
