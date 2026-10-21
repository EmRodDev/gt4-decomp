/* Restarts a two-word walker: copies the words at +8 and +0xC into +0x18 and +0x1C (current = start) and zeroes +0x10 and +0x14.
 * Reads like 'rewind to the beginning' (inferred from the copy-start-to-current pattern); purpose of the words unknown.
 * Called from func_0033E520 (race BGM code). */
#include "types.h"

struct Obj {
    char pad0[0x8];
    s32 startA;
    s32 startB;
    s32 unk10;
    s32 unk14;
    s32 currentA;
    s32 currentB;
};

extern "C" void func_001057F8(Obj *self) {
    self->currentA = self->startA;
    self->currentB = self->startB;
    self->unk14 = 0;
    self->unk10 = 0;
}
