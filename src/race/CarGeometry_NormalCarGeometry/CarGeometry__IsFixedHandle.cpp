typedef short s16;
typedef int s32;

struct VEntry_0038E738 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Inner_0038E738 {
    VEntry_0038E738 *vtbl;
};

/* Layout backed by include/gt4/CarGeometry.h and include/gt4/NormalCarGeometry.h:
 *   CarGeometry: forwarding wrapper to inner geometry instance at 0x1C
 *   vtable slot 46 (0x170 / 8)
 */
struct Obj_0038E738 {
    char pad[0x1C];
    Inner_0038E738 *unk1C;
};

static inline s32 vcall_0038E738(struct Inner_0038E738 *o) {
    VEntry_0038E738 *e = &o->vtbl[46];
    return e->fn((char *)o + e->delta);
}

extern "C" void CarGeometry__IsFixedHandle(struct Obj_0038E738 *arg0) {
    vcall_0038E738(arg0->unk1C);
}
