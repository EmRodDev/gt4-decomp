/* Integer-colour twin of func_00473438: the colour word has its alpha in the top byte and is handed to
 * func_004AA168 at the end. If state+0x14 is zero, func_00473638 initializes the state. When state+0xC is non-
 * zero, the alpha byte is replaced by the value at state+0x24 and id 9 is switched off with func_004AB040.
 * Otherwise, when state+0 is non-zero and state+4 is zero, an alpha byte of exactly 0x80 (full opacity in PS2
 * terms, which is why func_00473438 scales by 1/128; inferred) turns id 9 on with func_004A1638, any other alpha
 * turns it off. The unused memcpy and NULL declarations came with the file. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00473638();                            /* extern */
s32 func_004A1638(s32);                     /* extern */
s32 func_004AA168(u32);                         /* extern */
s32 func_004AB040(s32);                     /* extern */

struct func_00473380_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
    char pad10[0x4];
    s32 unk14;
    char pad18[0xC];
    s32 unk24;
};

void func_00473380(void *state, u32 color) {
    u32 colorOut;

    colorOut = color;
    if (((struct func_00473380_arg0 *)state)->unk14 == 0) {
        func_00473638();
    }
    if (((struct func_00473380_arg0 *)state)->unkC != 0) {
        colorOut = (colorOut & 0xFFFFFF) | (((struct func_00473380_arg0 *)state)->unk24 << 0x18);
        func_004AB040(9);
    } else if ((((struct func_00473380_arg0 *)state)->unk0 != 0) && (((struct func_00473380_arg0 *)state)->unk4 == 0)) {
        if ((colorOut >> 0x18) == 0x80) {
            func_004A1638(9);
        } else {
            func_004AB040(9);
        }
    }
    func_004AA168(colorOut);
}
