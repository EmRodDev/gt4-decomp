/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Resets a race overlay object to its defaults (inferred from the member classes it constructs): clears the first 0xA0 bytes
 * except flags at +0x44, +0x74 and +0x78 (1), a 1.0f at +0x84 and -1 at +0x9C, then runs the constructors of the embedded
 * RaceMiniMap (+0x298), RaceFuelMeter (+0x300), RaceTireWearDisplay (+0x328), RaceTooltipDisplay (+0x358) and one more member
 * at +0x12B4 (func_0042DC80, class unknown). What the individual fields hold is unknown. The void function returns the last call's
 * value because that is the shape that matched. */
typedef int s32;
typedef float f32;
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))

extern "C" void RaceFuelMeter__structor_1(void *);                      /* extern */
extern "C" void RaceTireWearDisplay__structor_1(void *);                      /* extern */
extern "C" void RaceTooltipDisplay__structor_0(void *);                      /* extern */
extern "C" int RaceMiniMap__structor_1(void *);                         /* extern */
extern "C" void func_0042DC80(void *);                      /* extern */

struct Obj {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    float f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
};
extern "C" void func_003D7700(Obj *self) {
    self->f0 = 0;
    self->f4 = 0;
    self->f8 = 0;
    self->fc = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f18 = 0;
    self->f1c = 0;
    self->f20 = 0;
    self->f24 = 0;
    self->f28 = 0;
    self->f2c = 0;
    self->f30 = 0;
    self->f34 = 0;
    self->f38 = 0;
    self->f3c = 0;
    self->f40 = 0;
    self->f44 = 1;
    self->f48 = 0;
    self->f4c = 0;
    self->f50 = 0;
    self->f54 = 0;
    self->f58 = 0;
    self->f5c = 0;
    self->f60 = 0;
    self->f64 = 0;
    self->f68 = 0;
    self->f6c = 0;
    self->f70 = 0;
    self->f74 = 1;
    self->f78 = 1;
    self->f7c = 0;
    self->f80 = 0;
    self->f84 = 1.0f;
    self->f88 = 0;
    self->f8c = 0;
    self->f90 = 0;
    self->f94 = 0;
    self->f98 = 0;
    self->f9c = -1;
    RaceMiniMap__structor_1((char *)self + 0x298);
    RaceFuelMeter__structor_1((char *)self + 0x300);
    RaceTireWearDisplay__structor_1((char *)self + 0x328);
    RaceTooltipDisplay__structor_0((char *)self + 0x358);
    return func_0042DC80((char *)self + 0x12B4);
}
