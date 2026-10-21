/* Returns the window width or height of the widget at +0x11C: width when the flag at +0xB0 is zero, height otherwise (a horizontal/vertical orientation switch, inferred from the W/H pairing). */
#include "types.h"

struct Obj {
    char pad[0xB0];
    s32 unkB0;
    char pad2[0x11C - 0xB0 - 4];
    void *unk11C;
};

extern "C" f32 mWidget__getWindowW(void *widget);
extern "C" f32 mWidget__getWindowH(void *widget);

extern "C" f32 func_002B2128(Obj *obj) {
    s32 orientation = obj->unkB0;
    void *widget = obj->unk11C;
    if (orientation == 0) {
        return mWidget__getWindowW(widget);
    }
    return mWidget__getWindowH(widget);
}
