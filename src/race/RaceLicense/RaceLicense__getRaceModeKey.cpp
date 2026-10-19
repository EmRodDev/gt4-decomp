/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *);
};

struct RaceLicenseLayout {
    char pad0[0x64];
    VEntry *vtbl;
};

extern "C" int RaceBase__getRaceModeKeyString(int arg0);

extern "C" int RaceLicense__getRaceModeKey(RaceLicenseLayout *arg0, void *arg1) {
    VEntry *e = &arg0->vtbl[96];
    s32 r = e->fn((char *)arg0 + e->delta, arg1);
    return RaceBase__getRaceModeKeyString(r);
}
