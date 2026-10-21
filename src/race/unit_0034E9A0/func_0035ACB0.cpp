/* Counts down the byte at offset 0x5FB of the sub-object at +0x104: it is decremented unless it is already 0 or the
 * sentinel 0xFF (the guard suggests 0xFF means 'not counting'; inferred). The decrement is spelled as + 0xFF, the u8 form that matched. */
#include "types.h"

struct Sub {
    char pad[0x5FB];
    u8 unk5FB;
};

extern "C" void func_0035ACB0(void *self) {
    struct Sub *state = (struct Sub *)((char *)self + 0x104);

    if (state->unk5FB != 0 && state->unk5FB != 0xFF) {
        state->unk5FB = state->unk5FB + 0xFF;
    }
}
