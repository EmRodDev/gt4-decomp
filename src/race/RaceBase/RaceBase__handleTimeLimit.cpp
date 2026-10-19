/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, f32, f32);
};

struct RaceBaseLayout {
    char pad0[0x64];
    VEntry *vtbl;
};

extern "C" void RaceBase__handleTimeLimit(RaceBaseLayout *arg0) {
    VEntry *e = &arg0->vtbl[87];
    e->fn((char *)arg0 + e->delta, 6, 0.0f, 0.0f);
}
