#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

/* Layout backed by include/gt4/MTRGeometry.h:
 *   MTRGeometry: virtual function dispatch via vtable slot 41 (0x148 / 8)
 */
struct Obj {
    VEntry *vtbl;
};

extern "C" void MTRGeometry__GetFixedRightHandleVector_Y(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[41];

    e->fn((char *)arg0 + e->delta);
}
