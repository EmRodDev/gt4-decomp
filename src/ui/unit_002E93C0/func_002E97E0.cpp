/* Calls mWidget::getWindowSize with its last two arguments in the given order when the flag at +0xC4 is nonzero and swapped otherwise (the flag mirrors the pair, inferred from the swap; probably a horizontal/vertical orientation). */
#include "types.h"

extern "C" void mWidget__getWindowSize(s32 obj, s32 widget, s32 a);

struct D_Obj {
    char pad[0xC4];
    s32 unkC4;
};

extern "C" void func_002E97E0(D_Obj *obj, s32 widget, s32 a, s32 b) {
    if (obj->unkC4 != 0) {
        mWidget__getWindowSize(widget, a, b);
    } else {
        mWidget__getWindowSize(widget, b, a);
    }
}
