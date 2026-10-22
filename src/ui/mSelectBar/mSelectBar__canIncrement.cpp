/* mSelectBar::canIncrement (inferred from the symbol name): tells whether the bar can still step forward, i.e. whether its items overflow the window.
 * The items container sits at +0xBC; func_0057CEC8 tests it for empty (result 0 then). The word at +0xB0 picks the axis: 0 uses the item width at +0xE4 and mWidget__getWindowW,
 * otherwise the item height at +0xE8 and mWidget__getWindowH. itemStep is itemSize plus the value from func_002D4980(this) (spacing, inferred from the sum).
 * The result is windowExtent < margin(+0xEC) + itemStep * (count - 1) + itemSize * (float at +0xD4), with count from func_0057CE60. The same body as mSelectBox::canIncrement. */
#include "types.h"

struct C {
    char pad[1];
};

struct Obj {
    char pad[1];
};

struct mSelectBox {
    char pad0[0xB0];
    s32 axis;      /* 0xB0 */
    char padB4[0x20];
    f32 unkD4;      /* 0xD4 */
    char padD8[0xC];
    f32 itemWidth;      /* 0xE4 */
    f32 itemHeight;      /* 0xE8 */
    f32 margin;      /* 0xEC */
};

extern "C" f32 mWidget__getWindowW(struct C *self);
extern "C" f32 mWidget__getWindowH(struct C *self);
extern "C" f32 func_002D4980(Obj *self);
extern "C" s32 func_0057CE60(Obj *self);
extern "C" bool func_0057CEC8(Obj *o);

extern "C" s32 mSelectBar__canIncrement(struct mSelectBox *self) {
    Obj *items = (Obj *)((char *)self + 0xBC);
    f32 itemSize;
    f32 windowExtent;
    f32 itemStep;
    s32 axis;
    s32 lastIndex;

    if (func_0057CEC8(items)) {
        return 0;
    }
    axis = self->axis;
    if (axis == 0) {
        itemSize = self->itemWidth;
    } else {
        itemSize = self->itemHeight;
    }
    if (axis == 0) {
        windowExtent = mWidget__getWindowW((struct C *)self);
    } else {
        windowExtent = mWidget__getWindowH((struct C *)self);
    }
    itemStep = itemSize + func_002D4980((Obj *)self);
    lastIndex = func_0057CE60(items) - 1;
    return windowExtent < (self->margin + ((itemStep * (f32)lastIndex) + (itemSize * self->unkD4)));
}
