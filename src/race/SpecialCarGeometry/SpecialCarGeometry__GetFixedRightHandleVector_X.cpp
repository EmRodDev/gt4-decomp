#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

/* Layout backed by include/gt4/SpecialCarGeometry.h:
 *   SpecialCarGeometry: virtual function dispatch via vtable slot 40 (0x140 / 8)
 */
struct Obj {
    VEntry *vtbl;
};

extern "C" f32 SpecialCarGeometry__GetFixedRightHandleVector_X(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[40];

    return -e->fn((char *)arg0 + e->delta);
}
