/* Calls func_0025B538 (the wrapper around mWidget::setWindowGeometry) with the four floats as given when the flag at +0xC4 is nonzero,
 * and with each pair swapped (second before first) otherwise: the flag mirrors the pairs (inferred from the swap; probably a horizontal/vertical orientation). */
#include "types.h"

struct func_002E9830_arg0 {
    char pad0[0xC4];
    s32 unkC4;
};

extern "C" void func_0025B538(s32 c, f32 f0, f32 f1, f32 f2, f32 f3);

extern "C" void func_002E9830(struct func_002E9830_arg0 *obj, s32 widget, f32 a0, f32 a1, f32 b0, f32 b1) {
    if (obj->unkC4 != 0) {
        return func_0025B538(widget, a0, a1, b0, b1);
    }
    func_0025B538(widget, a1, a0, b1, b0);
}
