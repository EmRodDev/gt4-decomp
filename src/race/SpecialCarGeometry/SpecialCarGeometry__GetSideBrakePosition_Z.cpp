#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

/* Layout backed by include/gt4/SpecialCarGeometry.h:
 *   SpecialCarGeometry: virtual function dispatch via vtable slot 20 (0xA0 / 8)
 */
struct Obj {
    VEntry *vtbl;
};

extern "C" void SpecialCarGeometry__GetSideBrakePosition_Z(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[20];

    e->fn((char *)arg0 + e->delta);
}
