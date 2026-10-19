#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

/* Layout backed by include/gt4/MTRGeometry.h:
 *   MTRGeometry: virtual function dispatch via vtable slot 34 (0x110 / 8)
 */
struct Obj {
    VEntry *vtbl;
};

extern "C" f32 MTRGeometry__GetFixedRightHandlePosition_X(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[34];

    return -e->fn((char *)arg0 + e->delta);
}
