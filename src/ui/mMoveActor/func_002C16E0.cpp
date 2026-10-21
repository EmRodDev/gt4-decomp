/* Stores a widget handle at +0x14 and fills four fields at +0x18, +0x1C, +0x20 and +0x24 from it through func_0025B500 (the wrapper around mWidget::getWindowGeometry).
 * The four values are probably the widget window rectangle (inferred from the callee). */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_0025B500(s32, s32, void *, void *, s32); /* extern */

struct func_002C16E0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_002C16E0(char *actor, s32 widget) {
    ((struct func_002C16E0_arg0 *)actor)->unk14 = widget;
    func_0025B500(widget, (s32)(actor + 0x18), actor + 0x1C, actor + 0x20, (s32)(actor + 0x24));
}

}
