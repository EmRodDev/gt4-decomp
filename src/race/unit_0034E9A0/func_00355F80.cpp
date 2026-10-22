/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Updates the level at car+0x104+0x494 (clamped to 0..1) and returns a torque-like value; skipped, returning
 * func_003554A0(car, level) as it is, when func_00355D88 reports 1.0 or more. Constants seen: 9542.84 divides by
 * the short at +0x4FA (called rpm here; inferred because 9542.84 is close to 9549, the kW to Nm per rpm factor),
 * and 0x1.B7860Ep-14 is about 1.047e-4, which is 2*pi/60 divided by 1000 (rpm to rad/s over 1000), so the last
 * call hands func_00355E88 a power-like product torque * rpm * factor read at car+0x54C. torque is the smaller of
 * f4E8 times D_008438F0 and a cap computed from D_008438F4 and rpm. The wanted level adds (torque + f4EC) / (f4E8
 * + f4EC) to (D_008438E8 - rpm) * D_008438EC. All the D_008438xx globals and the meaning of the fields are
 * unknown; the physical reading above is an inference. */
struct Sub {
    char p0[0x494];
    float f494;
    char p1[0x4E8 - 0x498];
    float f4E8;
    float f4EC;
    char p3[0x4FA - 0x4F0];
    short h4FA;
};
struct Obj {
    char p0[0x104];
    Sub sub;
};
extern float D_008438E8;
extern float D_008438EC;
extern float D_008438F0;
extern float D_008438F4;
extern "C" float func_003554A0(void *, float) throw();
extern "C" float func_00355D88(void *) throw();
extern "C" float func_00355E88(void *, float) throw();

extern "C" float func_00355F80(Obj *car) {
    Sub *state = &car->sub;
    float rpm = (float)state->h4FA;
    float level = state->f494;
    if (func_00355D88(car) >= 1.0f)
        return func_003554A0(car, level);
    float a = state->f4E8;
    float torque = a * D_008438F0;
    float torqueCap = (D_008438F4 * 9542.84f) / rpm;
    float wanted = (D_008438E8 - rpm) * D_008438EC;
    if (torqueCap < torque)
        torque = torqueCap;
    float b = state->f4EC;
    wanted += (torque + b) / (a + b);
    if (wanted < 0.0f)
        wanted = 0.0f;
    if (level < wanted)
        level = wanted;
    if (level > 1.0f)
        level = 1.0f;
    state->f494 = level;
    float result = func_003554A0(car, level) - torque;
    float factor = *(float *)((char *)car + 0x54C);
    func_00355E88(car, torque * rpm * 0x1.B7860Ep-14f * factor);
    return result;
}
