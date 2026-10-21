/* One step of the car physics update (inferred from the callee sequence): runs the helper passes, evaluates two curves at the
 * value in sub->f4FC, then sums two forces (f5B0, f5A4) with the weight (mass at +0x48 times 9.8) into the result f5BC.
 * The result is the sum of the forces with sign inverted (meaning of f5BC inferred only from this formula). */
#include "types.h"

struct Sub {
    char pad0[0x44];
    f32 f44;
    char p48[0x4BA - 0x48];
    u16 h4BA;
    char p4BC[0x4E8 - 0x4BC];
    f32 f4E8;
    f32 f4EC;
    char p4F0[0x4FC - 0x4F0];
    f32 f4FC;
    char p500[0x5A4 - 0x500];
    f32 f5A4;
    char p5A8[0x5B0 - 0x5A8];
    f32 f5B0;
    char p5B4[0x5BC - 0x5B4];
    f32 f5BC;
};

struct S {
    char pad[0x10];
    char *s4;
    char p14[0x104 - 0x14];
    Sub sub;
};

extern "C" void func_0035C0B8(void);
extern "C" void func_0035ACB0(void *self);
extern "C" void func_003658A0(void *self);
extern "C" void func_00354AC0(void *self);
extern "C" void func_003F3090(void *self);
extern "C" f32 func_0034E9A0(void *a, void *b, f32 c);
extern "C" f32 func_0034EA08(void *a, void *b, f32 c);
extern "C" void func_00357418(void *self);
extern "C" void func_00357690(void *self);

extern "C" void func_00357700(S *self) {
    Sub *sub;
    char *tuningBlock;
    char *carData;
    char *curveTable;

    sub = &self->sub;
    tuningBlock = (char *)self + 0x6DC;
    carData = self->s4;
    if (sub->h4BA != 0) {
        func_0035C0B8();
    }
    curveTable = carData + 0x134;
    func_0035ACB0(self);
    func_003658A0(self);
    func_00354AC0(self);
    func_003F3090(self);
    sub->f4E8 = func_0034E9A0(curveTable, tuningBlock, sub->f4FC);
    sub->f4EC = func_0034EA08(curveTable, tuningBlock, sub->f4FC);
    f32 forceSum;
    forceSum = sub->f5B0;
    forceSum = forceSum + sub->f5A4;
    f32 weightForce;
    weightForce = -(sub->f44 * ((f32 *)carData)[0x48 / 4] * 9.8f);
    sub->f5BC = -(forceSum + weightForce);
    func_00357418(self);
    return func_00357690(self);
}
