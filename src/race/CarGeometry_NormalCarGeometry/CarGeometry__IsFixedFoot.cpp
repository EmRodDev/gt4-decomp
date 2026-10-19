typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Inner {
    VEntry *vtbl;
};

/* Layout backed by include/gt4/CarGeometry.h and include/gt4/NormalCarGeometry.h:
 *   CarGeometry: forwarding wrapper to inner geometry instance at 0x1C
 *   vtable slot 47 (0x178 / 8)
 */
struct Obj {
    char pad[0x1C];
    Inner *unk1C;
};

static inline s32 vcall(struct Inner *o) {
    VEntry *e = &o->vtbl[47];
    return e->fn((char *)o + e->delta);
}

extern "C" void CarGeometry__IsFixedFoot(struct Obj *arg0) {
    vcall(arg0->unk1C);
}
