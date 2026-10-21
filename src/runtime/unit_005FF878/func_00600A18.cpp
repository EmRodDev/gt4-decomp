/* Advances a position by an amount: +0 is the position and wraps by subtracting 0xB6A (2922) once it reaches that value
 * (a ring-like counter, inferred from the wrap); +8 accumulates the unwrapped total (inferred). */
#include "types.h"

struct Obj {
    s32 unk0;
    char pad4[4];
    s32 unk8;
};

extern "C" void func_00600A18(Obj *self, s32 amount) {
    u32 newPosition = (u32)(self->unk0 + amount);
    if (newPosition >= 0xB6AU) {
        newPosition = newPosition - 0xB6A;
    }
    self->unk8 = self->unk8 + amount;
    self->unk0 = newPosition;
}
