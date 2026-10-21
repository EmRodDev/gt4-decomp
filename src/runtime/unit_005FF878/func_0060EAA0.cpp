/* Constructor shape: clears +0, +4 and +8 and stores the address of the static table D_00689650 at +0x28C
 * (the 0x280 bytes between are not touched here). */
#include "types.h"

struct S_0060EAA0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0xC[0x280];
    void *unk28C;
};

extern "C" char D_00689650[];

extern "C" void func_0060EAA0(struct S_0060EAA0 *self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk28C = D_00689650;
    self->unk8 = 0;
}
