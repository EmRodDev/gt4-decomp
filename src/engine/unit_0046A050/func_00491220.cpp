/* Lays out and optionally draws one line of items with left, centre or right alignment (inferred from the flags &
 * 3 test and the formulas (box - width) * 0.5 and box - width). The cursor x is set to 0; if there is no cached
 * width (cachedWidth <= 0) the line is measured by walking the items with the callback func_00492ED0 (through
 * func_00493C70 when hasLength is set, else func_004940E8; hasLength is inferred from the extra count argument
 * only the first takes), otherwise the cached width is used and the cache is cleared. The width goes to
 * storedWidth, the box width is right - left, and the cursor x becomes the centre or right offset for alignment 1
 * or 2. Unless measureOnly is set, the items are walked again with func_00492EA8 (the drawing pass, inferred).
 * Last, cursor y advances by lineAdvance. The field at +0x78 is saved and restored around the measure pass
 * (purpose unknown). */
#include "types.h"
struct Obj {
    char p0[0x30]; f32 cursorX, cursorY, cachedWidth, storedWidth; char p1[0x54 - 0x40]; f32 left; char p2[4]; f32 right; char p3[4]; int flags;
    char p4[0x78 - 0x68]; int f78;
};
extern "C" {
void func_00492ED0();
void func_00492EA8();
void func_00493C70(Obj *, void *, int, int, int);
void func_004940E8(Obj *, void *, int, int);
}
extern "C" void func_00491220(Obj *self, int a1, int a2, int hasLength, int measureOnly, f32 lineAdvance) {
    self->cursorX = 0.0f;
    f32 cached = self->cachedWidth;
    f32 zero = self->cursorX;
    int saved = self->f78;
    f32 lineWidth;
    if (cached <= zero) {
        if (hasLength != 0) func_00493C70(self, (void *)func_00492ED0, 0, a1, a2);
        else func_004940E8(self, (void *)func_00492ED0, 1, a1);
        lineWidth = self->cursorX;
    } else {
        self->cachedWidth = zero;
        lineWidth = cached;
    }
    int align = self->flags & 3;
    self->f78 = saved;
    f32 boxWidth = self->right - self->left;
    self->storedWidth = lineWidth;
    if (align == 1) {
        self->cursorX = (boxWidth - lineWidth) * 0.5f;
    } else if (align == 2) {
        self->cursorX = boxWidth - lineWidth;
    }
    if (measureOnly == 0) {
        if (hasLength != 0) func_00493C70(self, (void *)func_00492EA8, 0, a1, a2);
        else func_004940E8(self, (void *)func_00492EA8, 0, a1);
    }
    self->cursorY = self->cursorY + lineAdvance;
}
