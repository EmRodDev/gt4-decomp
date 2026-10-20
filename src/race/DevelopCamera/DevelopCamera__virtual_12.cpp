#include "types.h"

struct VEntry_00371CA8 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

/* Layout backed by include/gt4/DevelopCamera.h:
 *   DevelopCamera: virtual function dispatch via vtable slot 14 (0x70 / 8)
 */
struct Obj_00371CA8 {
    VEntry_00371CA8 *vtbl;
};

extern "C" f32 DevelopCamera__virtual_12(Obj_00371CA8 *arg0) {
    VEntry_00371CA8 *e = &arg0->vtbl[14];
    f32 v = e->fn((char *)arg0 + e->delta);

    return v * 0x1.8p4f / 0x1.F4p9f;
}
