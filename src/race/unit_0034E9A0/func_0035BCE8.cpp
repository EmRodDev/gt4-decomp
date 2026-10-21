/* Returns 1 unless bit 0x10 of the byte at 0x4B1 in the sub-state at +0x104 is set; when it is set, returns whether the
 * 16-bit value at 0x64C equals 1. Purpose of the flag and of the value unknown. */
#include "types.h"

struct Sub {
    char pad[0x4B1];
    u8 unk4B1;
    char pad2[0x64C - 0x4B2];
    s16 unk64C;
};

extern "C" s32 func_0035BCE8(void *self) {
    struct Sub *state = (struct Sub *)((char *)self + 0x104);
    s32 result = 1;

    if (!(state->unk4B1 & 0x10)) {
        return result;
    }
    result = state->unk64C == 1;
    return result;
}
