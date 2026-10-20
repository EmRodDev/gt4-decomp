#include "types.h"

struct Rect {
    s32 x, y, w, h;
};

/* Layout backed by include/gt4/mWidget.h and config/class_fields.json:
 *   mWidget: offset 0x34 is window geometry (Rect)
 */
struct mWidgetLayout {
    char pad[0x34];
    Rect window_geometry;
};

extern "C" void mWidget__getWindowGeometry(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern "C" void mWidget__getWindowSize(mWidgetLayout *arg0, s32 arg1, s32 arg2) {
    mWidget__getWindowGeometry(arg0, &arg0->window_geometry, 0, 0, arg1, arg2);
}
