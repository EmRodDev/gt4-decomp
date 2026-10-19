typedef short s16;

struct VEntry_0038C7F8 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

/* Layout backed by include/gt4/MTRGeometry.h:
 *   MTRGeometry: virtual function dispatch via vtable slot 42 (0x150 / 8)
 */
struct Obj_0038C7F8 {
    VEntry_0038C7F8 *vtbl;
};

extern "C" void MTRGeometry__GetFixedRightHandleVector_Z(Obj_0038C7F8 *arg0) {
    VEntry_0038C7F8 *e = &arg0->vtbl[42];

    e->fn((char *)arg0 + e->delta);
}
