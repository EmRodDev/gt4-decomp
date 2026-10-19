typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

/* Layout backed by include/gt4/MTRGeometry.h:
 *   MTRGeometry: virtual function dispatch via vtable slot 35 (0x118 / 8)
 */
struct Obj {
    VEntry *vtbl;
};

extern "C" void MTRGeometry__GetFixedRightHandlePosition_Y(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[35];

    e->fn((char *)arg0 + e->delta);
}
