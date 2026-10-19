typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

/* Layout backed by include/gt4/DevelopCamera.h:
 *   DevelopCamera: forwarding wrapper via vtable slot 4 (0x20 / 8)
 */
struct ObjInner {
    VEntry *vtbl;
};

struct Obj {
    char pad[0xC44];
    ObjInner *unkC44;
};

extern "C" void DevelopCamera__virtual_03(Obj *arg0) {
    ObjInner *a1 = arg0->unkC44;
    VEntry *e = &a1->vtbl[4];

    e->fn((char *)a1 + e->delta);
}
