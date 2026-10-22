/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Advances a damped spring by one 1/60 s step with a weight, like func_00350D40 but with more inputs (inferred
 * from the division by 60 and the velocity update). Fields: f0 is the value, f4 its rate, f8 a gain, fC a damping
 * factor, f10 a multiplier. The sub-objects at +0x14 and +0x11C are updated first (func_00384DB8 gets the target,
 * func_00384C48 gets arg1, 1.0 and the weight), the error is func_0036EB98(target, value) plus the measured value
 * minus the target, the scale is 1.0 or, when arg2 is non-zero, func_00384D70 * 0.9 + 0.6 (the hex float
 * 0x1.333332p-1), and the weight is clamped to 0..1. Then rate += ((gain * scale * error * weight + damping *
 * rate) / 60) * multiplier, and the value becomes func_0036EAD8(value + rate / 60). What the value stands for is
 * unknown. */
struct Sub14 {
    char pad[0x104];
};
struct Sub11C {
    char pad[4];
};
struct Obj {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    Sub14 s14;
    float f118;
    Sub11C s11C;
};

extern "C" float func_0036EAD8(float) throw();
extern "C" float func_0036EB98(float, float) throw();
extern "C" void func_00384C48(Sub11C *, int, float, float) throw();
extern "C" float func_00384D70(Sub11C *) throw();
extern "C" void func_00384DB8(Sub14 *, float) throw();
extern "C" float func_00384E38(Sub14 *) throw();

extern "C" void func_00384EE8(Obj *self, int arg1, int arg2, float target, float weight) {
    self->f118 = weight;
    func_00384DB8(&self->s14, target);
    func_00384C48(&self->s11C, arg1, 1.0f, weight);
    float measured = func_00384E38(&self->s14);
    float error = func_0036EB98(target, self->f0) + (measured - target);
    float scale = 1.0f;
    if (arg2 != 0) scale = func_00384D70(&self->s11C) * 0.9f + 0x1.333332p-1f;
    if (weight <= 0.0f) weight = 0.0f;
    if (weight >= 1.0f) weight = 1.0f;
    float f4 = self->f4;
    f4 = f4 + ((self->f8 * scale * error * weight + self->fC * f4) / 60.0f) * self->f10;
    self->f4 = f4;
    self->f0 = func_0036EAD8(self->f0 + f4 / 60.0f);
}
