/* Reads the widget window Y, lets func_0025BFE0 adjust it using the two float arguments, writes the result back with mWidget::setWindowY and returns func_0025BFE0's result.
 * Sibling of func_0025C030, which handles X. */
#include "types.h"

extern "C" f32 mWidget__getWindowY(void);
extern "C" s32 func_0025BFE0(void *out, f32 a, f32 b);
extern "C" void mWidget__setWindowY(s32 widget, f32 arg1);

extern "C" s32 func_0025C0A0(s32 widget, f32 a, f32 b) {
    f32 windowY;
    s32 adjustResult;

    windowY = mWidget__getWindowY();
    adjustResult = func_0025BFE0(&windowY, a, b);
    mWidget__setWindowY(widget, windowY);
    return adjustResult;
}
