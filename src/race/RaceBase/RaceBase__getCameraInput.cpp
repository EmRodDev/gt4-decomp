/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct RaceBaseLayout {
    char pad0[0x64];
    VEntry *vtbl;
};

static inline s32 vcall(RaceBaseLayout *o) {
    VEntry *e = &o->vtbl[70];
    return e->fn((char *)o + e->delta);
}

extern "C" void RaceBase__getCameraInput(RaceBaseLayout *arg0) {
    vcall(arg0);
}
