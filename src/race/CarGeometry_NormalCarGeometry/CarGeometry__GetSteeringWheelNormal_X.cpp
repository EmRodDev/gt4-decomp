typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct ObjInner {
    VEntry *vtbl;
};

/* Layout backed by include/gt4/CarGeometry.h and include/gt4/NormalCarGeometry.h:
 *   CarGeometry: forwarding wrapper to inner geometry instance at 0x1C
 *   vtable slot 14 (0x70 / 8)
 */
struct Obj {
    char pad[0x1C];
    ObjInner *unk1C;
};

extern "C" void CarGeometry__GetSteeringWheelNormal_X(Obj *arg0) {
    ObjInner *a1 = arg0->unk1C;
    VEntry *e = &a1->vtbl[14];

    e->fn((char *)a1 + e->delta);
}
