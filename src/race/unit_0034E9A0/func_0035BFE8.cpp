/* Handles a 4-byte event (opcode plus three bytes) on the state block at self+0x104, which has a u16 flag word at
 * +0x4B8 of the block and a u16 timer right after it. Opcode 1 acts only when flag 0x10 is set: with flag 4 it
 * sets 0x40 / 0x80 when byte 1 / byte 2 are not 0xFF and stores both bytes at +0x64E / +0x64F; with flag 8 it sets
 * 0x100 when byte 3 is non-zero; then it clears the bits 0x1C and resets the timer to 0 if no flags remain. Opcode
 * 2 clears flag 0x100 if set and, when neither 0x40 nor 0x80 remains, sets the timer to 0x5A (90; probably frames,
 * inferred). Meaning of the individual flags is unknown. The flag word is stored back and re-read into a local
 * after every set because that is how the compiler keeps it in a register. */
#include "types.h"

struct Sub {
    char pad0[0x4B8];
    u16 flags;
    u16 timer;
    char pad1[0x64E - 0x4BC];
    u8 b64E;
    u8 b64F;
};

struct Info {
    u8 op;
    u8 b1;
    u8 b2;
    u8 b3;
};

extern "C" void func_0035BFE8(char *self, Info *info) {
    Sub *sub = (Sub *)(self + 0x104);
    if (info->op == 1) {
        u16 curFlags = sub->flags;
        if (!(curFlags & 0x10))
            return;
        if (curFlags & 4) {
            if (info->b1 != 0xFF) {
                u16 updated = curFlags | 0x40;
                sub->flags = updated;
                curFlags = updated;
            }
            if (info->b2 != 0xFF) {
                u16 updated = curFlags | 0x80;
                sub->flags = updated;
                curFlags = updated;
            }
            sub->b64E = info->b1;
            sub->b64F = info->b2;
        }
        if (curFlags & 8) {
            if (info->b3 != 0) {
                u16 updated = curFlags | 0x100;
                sub->flags = updated;
                curFlags = updated;
            }
        }
        u16 masked = curFlags & 0xFFE3;
        sub->flags = masked;
        if (masked == 0)
            sub->timer = 0;
    } else if (info->op == 2) {
        u16 flagsNow = sub->flags;
        if (flagsNow & 0x100) {
            u16 updated = flagsNow ^ 0x100;
            sub->flags = updated;
            if (!(updated & 0xC0))
                sub->timer = 0x5A;
        }
    }
}
