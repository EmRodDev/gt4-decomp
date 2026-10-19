#include "types.h"

struct VEntry_00109910 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

/* Layout backed by include/gt4/SpecialCarGeometry.h:
 *   SpecialCarGeometry: virtual function dispatch via vtable slot 3 (0x18 / 8)
 */
struct Obj_00109910 {
    char pad[0x0];
    VEntry_00109910 *vtbl;
};

extern "C" void SpecialCarGeometry__GetOppositeSeatPosition_Y(Obj_00109910 *arg0) {
    VEntry_00109910 *e = &arg0->vtbl[3];

    e->fn((char *)arg0 + e->delta);
}
