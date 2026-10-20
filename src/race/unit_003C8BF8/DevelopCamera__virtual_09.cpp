#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

/* Layout backed by include/gt4/DevelopCamera.h:
 *   DevelopCamera: forwarding wrapper via vtable slot 10 (0x50 / 8)
 */
struct ObjInner {
    VEntry *vtbl;
};

struct Obj {
    char pad[0xC44];
    ObjInner *unkC44;
};

extern "C" void DevelopCamera__virtual_09(Obj *arg0) {
    ObjInner *a1 = arg0->unkC44;
    VEntry *e = &a1->vtbl[10];

    e->fn((char *)a1 + e->delta);
}
