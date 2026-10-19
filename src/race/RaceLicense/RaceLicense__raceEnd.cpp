/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;
typedef float f32;

extern "C" void RacePS2Base__raceEnd(void *self, s32 a);

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, f32, f32);
};

struct RaceLicenseLayout {
    char pad0[0x64];
    VEntry *vtbl;
    char pad1[0xCD0 - 0x68];
    s32 unkCD0;
    s32 unkCD4;
    s32 unkCD8;
    s32 unkCDC;
    s32 unkCE0;
    char pad2[0x24EE0 - 0xCE4];
    s32 unk24EE0;
};

extern "C" void RaceLicense__raceEnd(RaceLicenseLayout *arg0, s32 arg1) {
    RaceLicenseLayout *self = arg0;
    s32 endMode = arg1;
    if ((self->unk24EE0 != 0) || (self->unkCD0 != 0)) {
        endMode = 1;
        if (self->unkCE0 == 0) {
            VEntry *e = &self->vtbl[87];
            f32 z = 0.0f;
            e->fn((char *)self + e->delta, 1, z, z);
            return;
        }
    }
    RacePS2Base__raceEnd(arg0, endMode);
}
