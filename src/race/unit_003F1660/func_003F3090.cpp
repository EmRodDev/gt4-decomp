/* compiler: ee-gcc2.96-nogcse */
/* Per-frame update of a ramped factor and two derived outputs (what the quantity is stays unknown). The factor at +0x5A0 of the
 * block at +0x104 moves up (by input * D_00622314 * rate) while the input at +0x59C is non-zero, otherwise down (by D_00622318 * rate),
 * clamped to 0..1. From it and the speed-like value at +0x53C it forms f5a4 = -sign * aux->f1068 * factor * speed^2 (factor
 * forced to 20 when the byte at +0x5C3 is 2) and f5a8[i] = aux->f106c[i] * gain * speed^2, where the gain fades linearly to 0 as the absolute angle
 * func_0057D118(dot product, speed) grows from 0x1.657182p-4 to 0x1.657182p-3 (about 5 to 10 degrees if the angle is in radians; inferred from the
 * constants). The gain is also passed to func_003F2DB8. */
struct Aux { char p[0x1068]; float f1068; float f106c[2]; };
struct Inner {
    char p0[0x24]; float f24, f28, f2c;
    char p1[0x53C - 0x30]; float f53c; char p2[4]; float f544, f548, f54c;
    char p3[0x59C - 0x550]; float f59c, f5a0, f5a4, f5a8[2];
    char p4[0x5C3 - 0x5B0]; char c5c3;
};
struct Obj { char p[0x10]; Aux *aux; char q[0x104 - 0x14]; Inner s; };
extern float D_0062230C, D_00622310, D_00622314, D_00622318;
extern "C" void func_003F2DB8(char *, float) throw();
extern "C" float func_0057D118(float, float);

extern "C" void func_003F3090(Obj *car)
{
    Inner *block = &car->s;
    float input = block->f59c;
    float speed = block->f53c;
    Aux *aux = car->aux;
    float rate = *(float *)((char *)car + 0x54C);
    float speedSquared = speed * speed;
    if (input != 0.0f) {
        float level = block->f5a0 + input * D_00622314 * rate;
        block->f5a0 = level;
        if (level > 1.0f)
            block->f5a0 = 1.0f;
    } else {
        float level = block->f5a0 - D_00622318 * rate;
        block->f5a0 = level;
        if (level < 0.0f)
            block->f5a0 = 0.0f;
    }
    float angle = func_0057D118(block->f544 * block->f24 + block->f548 * block->f28 + block->f54c * block->f2c, block->f53c);
    float factor = D_0062230C;
    float range = 1.0f - factor;
    float remaining = 1.0f - block->f5a0;
    factor += range * remaining;
    if (block->c5c3 == 2)
        factor = 20.0f;
    factor *= speedSquared;
    float result = aux->f1068 * factor;
    if (block->f53c >= 0.0f)
        result = -result;
    block->f5a4 = result;
    float gain = D_00622310 + (1.0f - D_00622310) * remaining;
    if (angle < 0.0f)
        angle = -angle;
    if (angle > 0x1.657182p-3f)
        gain = 0.0f;
    else if (angle > 0x1.657182p-4f)
        gain *= (0x1.657182p-3f - angle) / 0x1.657182p-4f;
    gain *= speedSquared;
    for (int i = 0; i < 2; i++)
        block->f5a8[i] = aux->f106c[i] * gain;
    func_003F2DB8((char *)car, gain);
}
