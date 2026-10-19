#include "types.h"

/* Cam is the camera object whose limits the callees read; the two helpers compute the
 * same value from either the first or the second parameter set, selected by arg1. */
extern "C" f32 func_0036FFC0(void *cam, f32 x);
extern "C" f32 func_00370010(void *cam, f32 x);

extern "C" f32 func_00370048(void *cam, s32 selector, f32 x) {
    if (selector != 0) {
        return func_0036FFC0(cam, x);
    }
    return func_00370010(cam, x);
}
