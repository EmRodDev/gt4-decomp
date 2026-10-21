/* Same formula as func_00369510 for the first two wheels (field at +0x20 of the 0xEC-byte wheel records): writes 0.012 * mean |f20| + 0.4
 * to *outFactor and returns a quarter of the value at +0x104+0x51C. Meaning of both results is unknown. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" f32 func_00356D88(char *self, f32 *outFactor)
{
    s32 remaining;
    f32 sumAbs;
    f32 zero;
    f32 value;
    char *state;
    char *wheelField;

    sumAbs = 0.0f;
    zero = sumAbs;
    state = self + 0x104;
    wheelField = self + 0x184;
    remaining = 1;
    do {
        value = *(f32 *)wheelField;
        wheelField += 0xEC;
        if (value < zero) {
            value = -value;
        }
        remaining -= 1;
        sumAbs += value;
    } while (remaining >= 0);

    sumAbs = sumAbs * 0x1.0000000000000p-1f;
    *outFactor = (sumAbs * 0x1.89374Cp-7f) + 0x1.999998p-2f;

    return *(f32 *)(state + 0x51C) * 0x1.0000000000000p-2f;
}
