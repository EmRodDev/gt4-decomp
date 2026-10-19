typedef short s16;
typedef unsigned char u8;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Sub {
    VEntry *vtbl;
};

/* Layout backed by include/gt4/CarGeometry.h and include/gt4/NormalCarGeometry.h:
 *   CarGeometry: forwarding wrapper to inner geometry instance at 0x1C
 *   vtable slot 15 (0x78 / 8)
 */
struct Obj {
    u8 pad0[0x1C];
    Sub *unk1C;
};

extern "C" void CarGeometry__GetSteeringWheelNormal_Y(Obj *arg0) {
    Sub *s = arg0->unk1C;
    VEntry *e = &s->vtbl[15];

    e->fn((char *)s + e->delta);
}
