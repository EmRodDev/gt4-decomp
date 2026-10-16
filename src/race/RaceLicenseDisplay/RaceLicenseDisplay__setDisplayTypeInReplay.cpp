/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct VE {
    short delta;
    short index;
    void (*fn)(void *, s32);
};

struct RD {
    char *vt;
    char pad4[0x1C];
    s32 f20;
    char pad24[0x1D];
    unsigned char f41;
    char pad42[0x1E];
    s32 f60;
    s32 f64;
};

extern "C" void RaceDisplay__setDisplayTypeInReplay(RD *self, s32 a1);

extern "C" void RaceLicenseDisplay__setDisplayTypeInReplay(RD *self, s32 a1) {
    if (self->f41 == 0) {
        RaceDisplay__setDisplayTypeInReplay(self, a1);
        return;
    }
    s32 t = self->f20;
    if (t != 0) {
        self->f64 = a1;
        self->f60 = 0x18;
        VE *e = (VE *)(self->vt + 0x108);
        e->fn((char *)self + e->delta, t);
    }
}
