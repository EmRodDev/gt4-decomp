/* Sets the float at state+0x514 to 0.0 or 1.0 (it is the only thing written; the meaning of the float is unknown).
 * It is 0 whenever the byte at +0x4BC or the 16-bit field at +0x4BA is non-zero or the byte at +0x467 is 8.
 * Otherwise it depends on the byte at +0x522: when that is 0 the result is 1.0 only if the float at +0x48C is
 * below 0.1 (hex float 0x1.999998p-4), and when it is non-zero the result is 1.0 except when +0x48C is above 0.1
 * and the float at +0x53C lies strictly between -0.2778 and 0.2778 (0x1.1C71C6p-2), where it is 0. The 0x522 and
 * 0x48C fields also appear in func_0036D548. The 0.0 is stored first and possibly overwritten afterwards, as in
 * the matched source. */
#include "types.h"

struct func_00348368_arg0 {
    char pad0[0x467];
    u8 unk467;
    char pad468[0x48C - 0x468];
    f32 unk48C;
    char pad490[0x4BA - 0x490];
    u16 unk4BA;
    u8 unk4BC;
    char pad4BD[0x514 - 0x4BD];
    f32 unk514;
    char pad518[0x522 - 0x518];
    u8 unk522;
    char pad523[0x53C - 0x523];
    f32 unk53C;
};

void func_00348368(struct func_00348368_arg0 *state) {
    if (state->unk4BC != 0) {
        state->unk514 = 0x0.0p+0f;
        return;
    }
    if (state->unk4BA != 0) {
        state->unk514 = 0x0.0p+0f;
        return;
    }
    if (state->unk467 == 8) {
        state->unk514 = 0x0.0p+0f;
        return;
    }
    if (state->unk522 == 0) {
        state->unk514 = 0x0.0p+0f;
        if (state->unk48C < 0x1.999998p-4f) {
            state->unk514 = 0x1.0p+0f;
        }
    } else {
        state->unk514 = 0x1.0p+0f;
        if (0x1.999998p-4f < state->unk48C) {
            if (state->unk53C < 0x1.1C71C6p-2f) {
                if (-0x1.1C71C6p-2f < state->unk53C) {
                    state->unk514 = 0x0.0p+0f;
                }
            }
        }
    }
}
