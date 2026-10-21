/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-step wheel and body angle update. Angles are kept inside (-2*pi, 2*pi) (0x1.921fb4p+2 = 2*pi): the body angle at
 * dyn+0x570 wraps and drags the copy at +0x8C4 with it; each wheel angle (+0x24) advances by wheel speed (+0x20) times a
 * per-wheel coefficient from the engine record times dt, then wraps the same way (the loops at the end of the wheel body
 * update the matching entries at arg0+0x8C4 onwards). Afterwards the previous vectors (+0x888..) are copied to +0x8A4..
 * (previous frame, inferred from the copy) and new ones are built from the dynamics block, and two smoothed values
 * (indices 2 and 3 of func_0035A540/func_0035A618) blend toward targets with the weights D_0062075C and D_00620760.
 * Field meanings beyond that are purpose unknown. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" u8 *func_00359510(void *);                          /* extern */
extern "C" void *func_00359F50(void *);                        /* extern */
extern "C" s32 func_0035A080(void *);                          /* extern */
extern "C" f32 func_0035A540(void *, M2C_UNK);                 /* extern */
extern "C" void func_0035A618(void *, s32, f32);        /* extern */

extern float D_0062075C, D_00620760;
struct Coeff { char pad[0x2C0]; float values[256]; };
static inline float *angle(char *p, int offset) { return (float *)((int)(p + 0x10) + offset); }
extern "C" void func_00344040(char *car) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 weight3;
    f32 temp_f20;
    f32 weight2;
    f32 var_f0;
    f32 newWheelAngle;
    f32 clampLimit;
    f32 angleStep;
    f32 blendWeight;
    s32 wheelNo;
    s32 angleSlotUp;
    s32 angleSlotDown;
    s32 var_v0;
    u8 *wheelInfo;
    u8 *coeffIndexTable;
    u8 temp_v1;
    u8 coeffIndex;
    char *dyn;
    char *eng;
    char *wheel;

    dyn = car + 0x104;
    eng = M2C_FIELD(car, char **, 0x10);
    wheelInfo = func_00359510(eng);
    float dt = M2C_FIELD(car, f32 *, 0x54C);
    temp_f1 = M2C_FIELD(dyn, f32 *, 0x570);
    if (temp_f1 >= 0x1.921fb40000000p+2f) {
        temp_f1 -= 0x1.921fb40000000p+2f;
        M2C_FIELD(dyn, f32 *, 0x570) = temp_f1;
        var_f0 = M2C_FIELD(car, f32 *, 0x8C4) - 0x1.921fb40000000p+2f;
        M2C_FIELD(car, f32 *, 0x8C4) = var_f0;
    }
    else if (temp_f1 <= -0x1.921fb40000000p+2f) {
        temp_f1 += 0x1.921fb40000000p+2f;
        M2C_FIELD(dyn, f32 *, 0x570) = temp_f1;
        var_f0 = M2C_FIELD(car, f32 *, 0x8C4) + 0x1.921fb40000000p+2f;
        M2C_FIELD(car, f32 *, 0x8C4) = var_f0;
    }
    temp_v1 = M2C_FIELD(wheelInfo, u8 *, 1);
    wheelNo = 0;
    if (temp_v1 != 0) {
        Coeff *coeff = (Coeff *)(eng + 0xC);
        angleSlotDown = 0x900;
        angleSlotUp = 0x900;
        coeffIndexTable = wheelInfo + 0x14;
        wheel = car + 0x164;
        var_v0 = (s32) temp_v1 > 0;
        do {
            coeffIndex = 0;
            if (wheelNo < (s32)wheelInfo[1]) {
                coeffIndex = *coeffIndexTable;
            }
            angleStep = M2C_FIELD(wheel, f32 *, 0x20) * coeff->values[coeffIndex] * dt;
            if (M2C_FIELD(dyn, u8 *, 0x4BC) != 0) {
                angleStep = 0x0.0p+0f;
            }
            newWheelAngle = M2C_FIELD(wheel, f32 *, 0x24) + angleStep;
            while (newWheelAngle >= 0x1.921fb40000000p+2f) {
                newWheelAngle -= 0x1.921fb40000000p+2f;
                *angle(car, angleSlotUp) -= 0x1.921fb40000000p+2f;
            }
            while (newWheelAngle <= -0x1.921fb40000000p+2f) {
                newWheelAngle += 0x1.921fb40000000p+2f;
                *angle(car, angleSlotDown) += 0x1.921fb40000000p+2f;
            }
            M2C_FIELD(wheel, f32 *, 0x24) = newWheelAngle;
            wheel += 0xEC;
            wheelNo += 1;
            angleSlotDown += 4;
            angleSlotUp += 4;
            var_v0 = wheelNo < (s32) M2C_FIELD(wheelInfo, u8 *, 1);
            coeffIndexTable += 1;
        } while (var_v0 != 0);
    }
    temp_f20 = M2C_FIELD(eng, f32 *, 0x50);
    M2C_FIELD(car, f32 *, 0x8A4) = (f32) M2C_FIELD(car, f32 *, 0x888);
    M2C_FIELD(car, f32 *, 0x8A8) = (f32) M2C_FIELD(car, f32 *, 0x88C);
    M2C_FIELD(car, f32 *, 0x8AC) = (f32) M2C_FIELD(car, f32 *, 0x890);
    M2C_FIELD(car, f32 *, 0x888) = (f32) (M2C_FIELD(dyn, f32 *, 0) - (temp_f20 * M2C_FIELD(dyn, f32 *, 0xC)));
    M2C_FIELD(car, f32 *, 0x88C) = (f32) (M2C_FIELD(dyn, f32 *, 8) - (temp_f20 * M2C_FIELD(dyn, f32 *, 0x14)));
    M2C_FIELD(car, f32 *, 0x890) = (f32) -(M2C_FIELD(dyn, f32 *, 4) - (temp_f20 * M2C_FIELD(dyn, f32 *, 0x10)));
    if (func_0035A080(eng) != 0) {
        temp_f1_2 = (M2C_FIELD(eng, f32 *, 0x2C8) - M2C_FIELD(func_00359F50(car), f32 *, 0x10)) - M2C_FIELD(eng, f32 *, 0x3C);
        M2C_FIELD(car, f32 *, 0x888) = (f32) (M2C_FIELD(car, f32 *, 0x888) + (temp_f1_2 * M2C_FIELD(dyn, f32 *, 0x24)));
        M2C_FIELD(car, f32 *, 0x88C) = (f32) (M2C_FIELD(car, f32 *, 0x88C) + (temp_f1_2 * M2C_FIELD(dyn, f32 *, 0x2C)));
        M2C_FIELD(car, f32 *, 0x890) = (f32) (M2C_FIELD(car, f32 *, 0x890) + (temp_f1_2 * M2C_FIELD(dyn, f32 *, 0x28)));
    }
    M2C_FIELD(car, f32 *, 0x8B0) = (f32) M2C_FIELD(car, f32 *, 0x894);
    M2C_FIELD(car, f32 *, 0x8B4) = (f32) M2C_FIELD(car, f32 *, 0x898);
    M2C_FIELD(car, f32 *, 0x8B8) = (f32) M2C_FIELD(car, f32 *, 0x89C);
    M2C_FIELD(car, f32 *, 0x894) = (f32) (M2C_FIELD(dyn, f32 *, 0x30) - (temp_f20 * M2C_FIELD(dyn, f32 *, 0x3C)));
    M2C_FIELD(car, f32 *, 0x898) = (f32) (M2C_FIELD(dyn, f32 *, 0x38) - (temp_f20 * M2C_FIELD(dyn, f32 *, 0x44)));
    M2C_FIELD(car, f32 *, 0x89C) = (f32) -(M2C_FIELD(dyn, f32 *, 0x34) - (temp_f20 * M2C_FIELD(dyn, f32 *, 0x40)));
    M2C_FIELD(car, f32 *, 0x990) = (f32) M2C_FIELD(car, f32 *, 0x8A0);
    if (*func_00359510(eng) == 1) {
        blendWeight = 0.5f - (M2C_FIELD(dyn, f32 *, 0x65C) * 0.5f);
    } else {
        blendWeight = 0.5f - ((M2C_FIELD(dyn, f32 *, 0x468) / M2C_FIELD(eng, f32 *, 0x54)) * 0.5f);
    }
    clampLimit = 0x0.0p+0f;
    if ((blendWeight < 0x0.0p+0f) || (clampLimit = 0x1.0000000000000p+0f, (blendWeight > 0x1.0000000000000p+0f))) {
        blendWeight = clampLimit;
    }
    M2C_FIELD(car, f32 *, 0x8A0) = blendWeight;
    temp_f20 = 1.0f;
    float prevValue2 = func_0035A540(car, 2);
    weight2 = D_0062075C;
    func_0035A618(car, 2, (M2C_FIELD(dyn, f32 *, 0x494) * weight2) + (prevValue2 * (temp_f20 - weight2)));
    float prevValue3 = func_0035A540(car, 3);
    float target3 = M2C_FIELD(dyn, f32 *, 0x48C);
    weight3 = D_00620760;
    temp_f20 -= weight3;
    func_0035A618(car, 3, (target3 * weight3) + (prevValue3 * temp_f20));
}
