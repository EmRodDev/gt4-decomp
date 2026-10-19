#include "types.h"

typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct ObjInner {
    VEntry *vtbl;
};

/* Layout backed by include/gt4/CarGeometry.h and include/gt4/NormalCarGeometry.h:
 *   CarGeometry: forwarding wrapper to inner geometry instance at 0x1C
 *   vtable slot 48 (0x180 / 8): DoesLieOnBelly
 */
struct Obj {
    char pad[0x1C];
    ObjInner *unk30;
};

extern "C" void CarGeometry__DoesLieOnBelly(Obj *arg0) {
    ObjInner *a1 = arg0->unk30;
    VEntry *e = &a1->vtbl[48];

    e->fn((char *)a1 + e->delta);
}
