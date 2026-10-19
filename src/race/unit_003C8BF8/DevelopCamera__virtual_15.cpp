#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Sub {
    VEntry *vtbl;
};

/* Layout backed by include/gt4/DevelopCamera.h:
 *   DevelopCamera: forwarding wrapper via vtable slot 16 (0x80 / 8)
 */
struct Obj {
    char pad0[0xC44];
    Sub *unkC44;
};

extern "C" void DevelopCamera__virtual_15(Obj *arg0) {
    Sub *s = arg0->unkC44;
    VEntry *e = &s->vtbl[16];

    e->fn((char *)s + e->delta);
}
