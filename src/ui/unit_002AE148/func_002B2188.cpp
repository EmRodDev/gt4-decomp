/* Moves the widget at +0x11C: calls mWidget::setWindowPosition with (x, y) as given when the flag at +0xB0 is zero and swapped when it is nonzero (a horizontal/vertical orientation switch, inferred from the swap). */
#include "types.h"

void mWidget__setWindowPosition(void *c, f32 x, f32 y);      /* extern */

struct func_002B2188_arg0 {
    char pad0[0xB0];
    s32 unkB0;
    char padB4[0x11C - 0xB4];
    void *unk11C;
};

void func_002B2188(struct func_002B2188_arg0 *obj, f32 a, f32 b) {
    if (obj->unkB0 == 0) {
        return mWidget__setWindowPosition(obj->unk11C, a, b);
    }
    mWidget__setWindowPosition(obj->unk11C, b, a);
}
