/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Initialiser of an object of this unit (reached only through a vtable, no direct caller): runs the common setup 00378CB8, sets the field at
 * +0x148 to 0xD, copies params+0x10 into +0x180, and resets a block of state to zero, -1 or fixed values (+0x1B8 = -1, +0x08 = 100.0,
 * +0x0C = 60.0, +0xE8 = 1, a high byte of the 64-bit field at +0x168 cleared, two 12-byte vectors reset with 00384A60 and two with
 * 00384B60). The float zero is produced by storing integer 0 into a union with the float at +0x2EC and reading it back, which is the
 * form the compiler needed. What the object is and what 100/60 mean are purpose unknown. */
typedef int s32;
typedef float f32;
typedef unsigned long u64;

struct V12 { char d[12]; };
struct Obj {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    char pad10[0xE8 - 0x10];
    s32 uE8;
    char padEC[0x148 - 0xEC];
    s32 u148;
    char pad14C[0x168 - 0x14C];
    u64 u168;
    char pad170[0x180 - 0x170];
    s32 u180;
    void *u184;
    V12 m188;
    V12 m194;
    V12 m1A0;
    V12 m1AC;
    s32 u1B8;
    f32 f1BC;
    char pad1C0[0x2EC - 0x1C0];
    union { s32 i; f32 f; } m2EC;
};
struct Arg { char pad[0x10]; s32 u10; };

extern "C" void func_00378CB8(Obj *) throw();
extern "C" void func_00384A60(void *);
extern "C" void func_00384B60(void *, f32, f32);
extern "C" void func_00384E58(void *, void *, f32, f32, f32);

extern "C" void func_00382D40(Obj *self, Arg *params) {
    f32 zero;

    func_00378CB8(self);
    self->u148 = 0xD;
    self->u180 = params->u10;
    self->m2EC.i = 0;
    zero = self->m2EC.f;
    self->f1BC = zero;
    func_00384E58((char *)self + 0x1C0, self->u184, zero, zero, 0.1f);
    self->u1B8 = -1;
    self->f8 = 100.0f;
    self->fC = 60.0f;
    self->u168 &= 0xFFFFFFFF00FFFFFFul;
    self->uE8 = 1;
    func_00384A60(&self->m188);
    func_00384A60(&self->m194);
    func_00384B60(&self->m1A0, zero, zero);
    func_00384B60(&self->m1AC, zero, zero);
}
