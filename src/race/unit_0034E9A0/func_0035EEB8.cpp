/* Limits the sum of two parallel arrays of six floats to a per-channel range (the limits are the six floats at
 * D_006208B8; what the six channels are is unknown). For each channel, if first+second is below -limit the second
 * value is rewritten so that the sum is exactly -limit; if it is above +limit, so that the sum is +limit. When
 * that rewrite would flip the sign of second, the pair is instead set to (+-limit, 0). Whenever a channel was
 * pushed back, the matching entry of rateA and rateB is clamped to zero if it still points outward (negative for
 * the lower limit, positive for the upper one); this reads like zeroing the velocity into the stop (inferred,
 * names rateA/rateB are guesses). */
#include "types.h"

extern char D_006208B8[];

extern "C" void func_0035EEB8(char *firstArr, char *secondArr, f32 *rateA, f32 *rateB) {
    s32 limits = (s32)D_006208B8;
    s32 i = 0;

    do {
        s32 off = i << 2;
        f32 *firstPtr = (f32 *)(firstArr + off);
        f32 *secondPtr = (f32 *)(secondArr + off);
        f32 limit = *(f32 *)(off + limits);
        f32 firstVal = *firstPtr;
        f32 secondVal = *secondPtr;
        f32 negLimit = -limit;
        f32 sum = firstVal + secondVal;

        if (sum < negLimit) {
            f32 newFirst = firstVal;
            f32 newSecond = negLimit - firstVal;
            if (secondVal * newSecond < 0.0f) {
                newFirst = negLimit;
                newSecond = 0.0f;
            }
            *firstPtr = newFirst;
            *secondPtr = newSecond;
            if (*rateA < 0.0f) {
                *rateA = 0.0f;
            }
            if (*rateB < 0.0f) {
                *rateB = 0.0f;
            }
        } else if (limit < sum) {
            f32 newFirst = firstVal;
            f32 newSecond = limit - firstVal;
            if (secondVal * newSecond < 0.0f) {
                newFirst = limit;
                newSecond = 0.0f;
            }
            *firstPtr = newFirst;
            *secondPtr = newSecond;
            if (0.0f < *rateA) {
                *rateA = 0.0f;
            }
            if (0.0f < *rateB) {
                *rateB = 0.0f;
            }
        }

        i++;
        rateB++;
        rateA++;
    } while (i < 6);
}
