/* Reads a three-component position from the source (func_00344798 / func_003447F8 / func_00344828, which func_003821F0 uses as x, y, z of
 * a car) and passes it to func_0044EF18 on the target. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00344798(s32);                             /* extern */
f32 func_003447F8(s32, f32);                        /* extern */
f32 func_00344828(s32, f32);                        /* extern */
s32 func_0044EF18(s32, f32, f32, f32);          /* extern */

void func_0044EFD0(s32 target, s32 source, f32 offset) {
    f32 y;
    f32 x;

    x = func_00344798(source);
    y = func_003447F8(source, offset);
    func_0044EF18(target, x, y, func_00344828(source, offset));
}
