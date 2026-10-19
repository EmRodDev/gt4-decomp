typedef short s16;

struct VEntry_0038C5A0 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

/* Layout backed by include/gt4/SpecialCarGeometry.h:
 *   SpecialCarGeometry: virtual function dispatch via vtable slot 32 (0x100 / 8)
 */
struct Obj_0038C5A0 {
    VEntry_0038C5A0 *vtbl;
};

extern "C" void SpecialCarGeometry__GetSideBrakeLength(Obj_0038C5A0 *arg0) {
    VEntry_0038C5A0 *e = &arg0->vtbl[32];

    e->fn((char *)arg0 + e->delta);
}
