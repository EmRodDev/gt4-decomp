/* Classifies a mode byte (+0x56B overall) and flag word (+0x5BC overall) of the block at +0x104 into three small codes. Mode 4 clears
 * all three codes and returns 1; modes 2 and 3 fill outA/outB/outC (values 0, 1 or 2, taken from different flag bits depending on
 * whether any of bits 0x11 is set) and return the mode (2 or 3); every other mode returns 0 and writes nothing. What the codes and the
 * mode stand for is purpose unknown; the (mode + 0xFE) & 0xFF < 2 test is the compiler's form of "mode is 2 or 3". */
#include "types.h"

struct Sub {
    char pad0[0x467];
    u8 mode;
    char pad468[0x4B8 - 0x468];
    u16 flags;
};

extern "C" int func_0035BD10(Sub *sub, s8 *outA, s8 *outB, s8 *outC) {
    sub = (Sub *)((char *)sub + 0x104);
    unsigned modeByte = sub->mode;
    if (modeByte == 4) {
        *outA = 0;
        *outB = 0;
        *outC = 0;
        return 1;
    }
    modeByte += 0xFE;
    modeByte &= 0xFF;
    if (modeByte >= 2) return 0;
    {
        unsigned flags = sub->flags;
        if (flags & 0x11) {
            if (flags & 4) {
                *outA = 1;
                *outB = 1;
            } else if (flags & 2) {
                *outA = 1;
                *outB = 1;
            } else {
                *outA = 0;
                *outB = 0;
            }
            if (flags & 8) {
                *outC = 1;
            } else if (flags & 2) {
                *outC = 1;
            } else {
                *outC = 0;
            }
        } else {
            if (flags & 0x40) {
                *outA = 2;
            } else {
                *outA = 0;
            }
            if (flags & 0x80) {
                *outB = 2;
            } else {
                *outB = 0;
            }
            if (flags & 0x100) {
                *outC = 2;
            } else {
                *outC = 0;
            }
        }
        unsigned mode = sub->mode;
        if (mode == 2) return 2;
        return (mode == 3) ? 3 : 0;
    }
}
