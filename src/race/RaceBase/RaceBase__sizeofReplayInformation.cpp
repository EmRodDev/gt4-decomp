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

extern "C" s32 RaceBase__sizeofReplayInformation(RaceBaseLayout *arg0) {
    VEntry *e = &arg0->vtbl[59];
    return e->fn((char *)arg0 + e->delta) + 0x1AA4;
}
