/* Constructor shape: clears +0, +4 and +8 and stores the address of the static table D_00689668 at +0x24C
 * (the 0x240 bytes between are not touched here). */
#include "types.h"

struct S_0060EA50 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0xC[0x240];
    void *unk24C;
};

extern "C" char D_00689668[];

extern "C" void func_0060EA50(struct S_0060EA50 *self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk24C = D_00689668;
    self->unk8 = 0;
}
