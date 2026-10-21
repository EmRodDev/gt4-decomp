/* Sets only the size part of a widget window geometry: calls mWidget::setWindowGeometry with null x/y pointers and the new width and height,
 * so the position is left as it is (inferred from the null pointers in the x/y slots of the Rect). */
#include "types.h"

struct Rect {
    f32 x, y, w, h;
};

struct Widget {
    char pad[0x34];
    Rect window_geometry;
};

extern "C" void mWidget__setWindowGeometry(struct Widget *self, struct Rect *r, f32 *px, f32 *py, f32 *pw, f32 *ph);

extern "C" void func_0025B4C8(struct Widget *widget, f32 newWidth, f32 newHeight) {
    f32 width = newWidth;
    f32 height = newHeight;

    mWidget__setWindowGeometry(widget, &widget->window_geometry, 0, 0, &width, &height);
}
