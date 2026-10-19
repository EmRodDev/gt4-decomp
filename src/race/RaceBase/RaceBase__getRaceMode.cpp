/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32 *);
};

struct RaceBaseLayout {
    char pad[0x64];
    VEntry *vtbl;
};

extern "C" s32 RaceBase__getRaceMode(RaceBaseLayout *self, s32 *mode) {
    *mode = -1;
    VEntry *e = &self->vtbl[95];
    return e->fn((char *)self + e->delta, mode);
}
