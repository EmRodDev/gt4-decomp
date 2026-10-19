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
 *   vtable slot 11 (0x58 / 8)
 */
struct Obj {
    u8 pad0[0x1C];
    Sub *unk1C;
};

extern "C" void CarGeometry__GetSteeringWheelCenter_X(Obj *arg0) {
    Sub *s = arg0->unk1C;
    VEntry *e = &s->vtbl[11];

    e->fn((char *)s + e->delta);
}
