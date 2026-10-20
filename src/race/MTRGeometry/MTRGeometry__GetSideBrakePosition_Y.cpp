#include "types.h"

struct VEntry_0038C468 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

/* Layout backed by include/gt4/MTRGeometry.h:
 *   MTRGeometry: virtual function dispatch via vtable slot 19 (0x98 / 8)
 */
struct Obj_0038C468 {
    VEntry_0038C468 *vtbl;
};

extern "C" void MTRGeometry__GetSideBrakePosition_Y(Obj_0038C468 *arg0) {
    Obj_0038C468 *self = arg0;
    VEntry_0038C468 *e = &self->vtbl[19];

    e->fn((char *)self + e->delta);
}
