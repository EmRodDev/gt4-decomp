/* Reads the widget window X, lets func_0025BFE0 adjust it using the two float arguments, writes the result back with mWidget::setWindowX and returns func_0025BFE0's result.
 * Sibling func_0025C0A0 does the same for Y. What the adjustment is (a clamp or a step) is unknown. */
#include "types.h"

extern "C" f32 mWidget__getWindowX(void);
extern "C" s32 func_0025BFE0(void *out, f32 a, f32 b);
extern "C" void mWidget__setWindowX(s32 widget, f32 arg1);

extern "C" s32 func_0025C030(s32 widget, f32 a, f32 b) {
    f32 windowX;
    s32 adjustResult;

    windowX = mWidget__getWindowX();
    adjustResult = func_0025BFE0(&windowX, a, b);
    mWidget__setWindowX(widget, windowX);
    return adjustResult;
}
