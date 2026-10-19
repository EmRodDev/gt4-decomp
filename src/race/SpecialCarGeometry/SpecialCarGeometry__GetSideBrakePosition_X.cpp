typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

/* Layout backed by include/gt4/SpecialCarGeometry.h:
 *   SpecialCarGeometry: virtual function dispatch via vtable slot 18 (0x90 / 8)
 */
struct Obj {
    VEntry *vtbl;
};

extern "C" void SpecialCarGeometry__GetSideBrakePosition_X(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[18];

    e->fn((char *)arg0 + e->delta);
}
