/* mSelectBox::canIncrement (inferred from the symbol name): returns 1 when the content is longer than the window, so the selection can move on; 0 for an empty list.
 * Layout data (offsets from this): items vector at +0xBC, axis switch at +0xB0, item width +0xE4, item height +0xE8, edge margin +0xEC, and a float at +0xD4 whose purpose is unknown.
 * Horizontal (axis 0) compares against mWidget__getWindowW, vertical against mWidget__getWindowH. The expression is (itemSize + func_002D4980(this)) * (count - 1)
 * plus itemSize * unkD4 plus the margin, tested with 'window extent less than that'; the mSelectBar copy is byte-for-byte the same shape. */
#include "types.h"

struct C {
    char pad[1];
};

struct Obj {
    char pad[1];
};

struct mSelectBox {
    char pad0[0xB0];
    s32 unkB0;      /* 0xB0 */
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

extern "C" s32 mSelectBox__canIncrement(struct mSelectBox *self) {
    Obj *items = (Obj *)((char *)self + 0xBC);
    f32 itemSize;
    f32 windowExtent;
    f32 itemStep;
    s32 axis;
    s32 lastIndex;

    if (func_0057CEC8(items)) {
        return 0;
    }
    axis = self->unkB0;
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
