typedef short s16;

typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

/* Layout backed by include/gt4/mSceneViewFace.h: slot 65 (0x208 / 8) */
struct Obj {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void mSceneViewFace__virtual_86(struct Obj *arg0, s32 arg1) {
    VEntry *e = &arg0->vtbl[65];

    e->fn((char *)arg0 + e->delta, arg1);
}
