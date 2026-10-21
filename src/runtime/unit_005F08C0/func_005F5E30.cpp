/* Sets the word at +0x2C4 to -1 and clears bits 8..15 of the 64-bit word at +0x268. Meaning unknown. */
#include "types.h"

struct S005F5E30 {
    char pad0[0x268];
    u64 unk268;
    char pad1[0x2C4 - 0x270];
    s32 unk2C4;
};

extern "C" void func_005F5E30(struct S005F5E30 *self) {
    self->unk2C4 = -1;
    self->unk268 = self->unk268 & 0xFFFFFFFFFFFF00FFULL;
}
