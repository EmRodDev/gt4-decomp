/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Initializer of an object with an embedded oscillator at +0x48. It sets floats +0x34 and +0x38 to 1.0 and fetches
 * a pointer by following owner+0x80 -> +4 -> +0x84, stored at +0x18. Two 16-bit fields at +0x3C and +0x3E receive
 * 10-bit values plus 1, taken from bits 14..23 and bits 34..43 of the 64-bit word at +0x20 of a block reached
 * through parent+0x28 -> +0x18 (read twice; the meaning, perhaps sizes, is unknown). Words +0x40 and +0x44 are
 * cleared. The oscillator is set up with a cycle of 0.5 and 0.5 (Oscillator__setCycle), a waveform of 0.1 and 0.3
 * (Oscillator__setWaveform, hex floats) and a count of -1 with 0 (Oscillator__setCount; -1 probably means endless,
 * inferred). */
#include "types.h"
#define NULL 0

extern "C" {
void Oscillator__setCycle(void *, f32, f32);
void Oscillator__setWaveform(void *, f32, f32);
void Oscillator__setCount(void *, s32, u8);
}

extern "C" void func_003BECB0(char *arg0, char *owner) {
    char *self;
    char *parent;
    char *info;
    unsigned long bitsA;
    unsigned long bitsB;

    self = arg0;
    char *osc=self+0x48;
    *(f32 *)(self + 0x34) = 1.0f;
    *(f32 *)(self + 0x38) = 1.0f;
    parent = *(char **)(*(char **)(*(char **)(owner + 0x80) + 4) + 0x84);
    *(char **)(self + 0x18) = parent;
    info = *(char **)(parent + 0x28);
    bitsA = *(unsigned long *)(*(char **)(info + 0x18) + 0x20);
    *(s16 *)(self + 0x3C) = (s16)((((bitsA >> 14) & 0x3FF) + 1) & 0xFFFF);
    bitsB = *(unsigned long *)(*(char **)(info + 0x18) + 0x20);
    *(s16 *)(self + 0x3E) = (s16)((((bitsB >> 34) & 0x3FF) + 1) & 0xFFFF);
    *(s32 *)(self + 0x44) = 0;
    *(s32 *)(self + 0x40) = 0;
    Oscillator__setCycle(osc, 0.5f, 0.5f);
    Oscillator__setWaveform(osc, 0x1.999998p-4f, 0x1.333332p-2f);
    Oscillator__setCount(osc, -1, 0);
}
