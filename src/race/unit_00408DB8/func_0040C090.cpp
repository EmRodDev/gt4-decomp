/* Fills four floats: each is func_0040BFE8(values, context, index, param) when enable is non-zero, otherwise 0.0; then calls
 * func_0040BAB0 on the result. What the four values are is unknown. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040BAB0(f32 *, s32);                  /* extern */
f32 func_0040BFE8(f32 *, s32, s32, f32);            /* extern */

void func_0040C090(f32 *values, s32 context, s32 enable, f32 param) {
    f32 *slot;
    s32 index;

    slot = values;
    index = 0;
    do {
        if (enable != 0) {
            *slot = func_0040BFE8(values, context, index, param);
        } else {
            *slot = 0x0.0p+0f;
        }
        index += 1;
        slot += 1;
    } while (index < 4);
    func_0040BAB0(values, context);
}
