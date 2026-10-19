typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

/* Layout backed by include/gt4/mColorWindow.h: slot 57 (0x1C8 / 8) */
struct Obj {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void mColorWindow__getAlpha_const(struct Obj *arg0) {
    VEntry *e = &arg0->vtbl[57];

    e->fn((char *)arg0 + e->delta, 0);
}
