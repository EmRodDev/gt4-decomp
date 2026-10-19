typedef short s16;

struct VEntry_0038C6D0 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

/* Layout backed by include/gt4/SpecialCarGeometry.h:
 *   SpecialCarGeometry: virtual function dispatch via vtable slot 36 (0x120 / 8)
 */
struct Obj_0038C6D0 {
    VEntry_0038C6D0 *vtbl;
};

extern "C" void SpecialCarGeometry__GetFixedRightHandlePosition_Z(Obj_0038C6D0 *arg0) {
    VEntry_0038C6D0 *e = &arg0->vtbl[36];

    e->fn((char *)arg0 + e->delta);
}
