typedef short s16;

struct VEntry_0020E640 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Inner_0020E640 {
    char pad0[0x0];
    VEntry_0020E640 *vtbl;
};

/* Layout backed by include/gt4/CarGeometry.h and include/gt4/NormalCarGeometry.h:
 *   CarGeometry: forwarding wrapper to inner geometry instance at 0x1C
 *   vtable slot 34 (0x110 / 8)
 */
struct Obj_0020E640 {
    char pad[0x1C];
    Inner_0020E640 *unk8;
};

extern "C" void CarGeometry__GetFixedLeftHandlePosition_X(struct Obj_0020E640 *arg0) {
    Inner_0020E640 *a1 = arg0->unk8;
    VEntry_0020E640 *e = &a1->vtbl[34];

    e->fn((char *)a1 + e->delta);
}
