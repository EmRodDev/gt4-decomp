#include "types.h"

extern "C" f32 func_0036FF38(void *cam, f32 x);
extern "C" f32 func_0036FF78(void *cam, f32 x);

/* The float argument is in $f12 and the selector in $a1: the callees take (cam, x). */
extern "C" f32 func_0036FF98(void *cam, f32 x, s32 selector) {
    if (selector != 0) {
        return func_0036FF38(cam, x);
    }
    return func_0036FF78(cam, x);
}
