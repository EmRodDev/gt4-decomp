/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Advances one rigid body by timeStep and reports whether it is still above a plane. Read from the arithmetic (all inferred): body +0x08/0C/10
 * are three Euler angles wrapped into [0, 2 pi) at the end, +0x14..0x1C the position, +0x20..0x28 the linear velocity, +0x2C..0x34 the
 * angular velocity, and +0x4C points to a property block (+0x04 mass, which gives the 9.81 gravity force; +0x10 the inverse mass applied to
 * the force; +0x18/0x1C/0x20 the principal inertias used in the Euler equations omega' = (torque + (Iy - Iz) wy wz) / Ix; +0x24/0x28 drag
 * factors on the body-frame velocity; +0x2C/0x30 angular drag). The rotation matrix comes from 0040AD10 and the Euler angle rates from
 * sin/cos of two of the angles (update skipped when the second sin/cos output is 0, the gimbal case). The angular velocity is also damped by
 * 0.9985 per step. Return value: 0 when the plane (normal at +0x38/0x3C/0x40, offset +0x44) is crossed by the position, else 1. What the body
 * represents (a loose part or prop is the likely case) is purpose unknown. */
typedef float f32;
typedef int s32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern "C" void func_0040AD10(float (*)[4],float,float,float) throw();
extern "C" void func_0040AE20(float (*)[4], const float *,float *) throw();
extern "C" void func_0040AE78(float (*)[4], const float *,float *) throw();
extern "C" void func_0057D8A0(float,float *,float *);
extern "C"
s32 func_0040AFB0(void *body, f32 timeStep) {
    struct StackFrame { float force[4]; float torque[4]; float m[4][4]; float local[4]; float scaled[4]; float trigAFirst,trigASecond,trigCFirst,trigCSecond; } frame;
    f32 wrappedAngle;
    f32 eulerRateY;
    f32 inertiaX;
    f32 inertiaZ;
    f32 inertiaY;
    f32 angularVelX;
    f32 angularVelY;
    f32 angularVelZ;
    f32 angleAt0C;
    f32 angleAt10;
    f32 angleAt8;
    s32 var_v0;
    void *properties;
    void *properties2;
    void *properties3;
    void *properties4;

    properties = M2C_FIELD(body, void **, 0x4C);
    angularVelX = M2C_FIELD(body, f32 *, 0x2C);
    inertiaX = M2C_FIELD(properties, f32 *, 0x18);
    inertiaY = M2C_FIELD(properties, f32 *, 0x1C);
    inertiaZ = M2C_FIELD(properties, f32 *, 0x20);
    angularVelZ = M2C_FIELD(body, f32 *, 0x34);
    angularVelY = M2C_FIELD(body, f32 *, 0x30);
    func_0040AD10(frame.m, M2C_FIELD(body, f32 *, 8), M2C_FIELD(body, f32 *, 0xC), M2C_FIELD(body, f32 *, 0x10));
    func_0040AE78(frame.m, (float *)((char *)body + 0x20), &frame.local[0]);
    properties2 = M2C_FIELD(body, void **, 0x4C);
    frame.scaled[0] = M2C_FIELD(properties2, f32 *, 0x28) * frame.local[0];
    frame.scaled[1] = M2C_FIELD(properties2, f32 *, 0x24) * frame.local[1];
    frame.scaled[2] = M2C_FIELD(properties2, f32 *, 0x28) * frame.local[2];
    func_0040AE20(frame.m, &frame.scaled[0], frame.force);
    properties3 = M2C_FIELD(body, void **, 0x4C);
    frame.force[1] += -M2C_FIELD(properties3, f32 *, 4) * 0x1.39eb840000000p+3f;
    frame.torque[0] = M2C_FIELD(properties3, f32 *, 0x2C) * angularVelX;
    frame.torque[1] = 0x0.0p+0f;
    frame.torque[2] = M2C_FIELD(properties3, f32 *, 0x30) * angularVelZ;
    func_0057D8A0(M2C_FIELD(body, f32 *, 8), &frame.trigAFirst, &frame.trigASecond);
    func_0057D8A0(M2C_FIELD(body, f32 *, 0x10), &frame.trigCFirst, &frame.trigCSecond);
    M2C_FIELD(body, f32 *, 0x2C) = (f32) (M2C_FIELD(body, f32 *, 0x2C) + (((frame.torque[0] + ((inertiaY - inertiaZ) * angularVelY * angularVelZ)) * timeStep) / inertiaX));
    M2C_FIELD(body, f32 *, 0x30) = (f32) (M2C_FIELD(body, f32 *, 0x30) + (((frame.torque[1] + ((inertiaZ - inertiaX) * angularVelZ * angularVelX)) * timeStep) / inertiaY));
    M2C_FIELD(body, f32 *, 0x34) = (f32) (M2C_FIELD(body, f32 *, 0x34) + (((frame.torque[2] + ((inertiaX - inertiaY) * angularVelX * angularVelY)) * timeStep) / inertiaZ));
    if (frame.trigASecond != 0x0.0p+0f) {
        eulerRateY = ((angularVelX * frame.trigCFirst) - (angularVelY * frame.trigCSecond)) / frame.trigASecond;
        M2C_FIELD(body, f32 *, 8) = (f32) (M2C_FIELD(body, f32 *, 8) + (-((angularVelX * frame.trigCSecond) + (angularVelY * frame.trigCFirst)) * timeStep));
        M2C_FIELD(body, f32 *, 0xC) = (f32) (M2C_FIELD(body, f32 *, 0xC) + (eulerRateY * timeStep));
        M2C_FIELD(body, f32 *, 0x10) = (f32) (M2C_FIELD(body, f32 *, 0x10) + (-((eulerRateY * frame.trigAFirst) + angularVelZ) * timeStep));
    }
    angleAt8 = M2C_FIELD(body, f32 *, 8);
    if (angleAt8 < 0x0.0p+0f) {
        wrappedAngle = angleAt8 + 0x1.921fb40000000p+2f;
        M2C_FIELD(body, f32 *, 8) = wrappedAngle;
        angleAt8 = wrappedAngle;
    }
    if (angleAt8 >= 0x1.921fb40000000p+2f) {
        M2C_FIELD(body, f32 *, 8) = (f32) (angleAt8 - 0x1.921fb40000000p+2f);
    }
    angleAt0C = M2C_FIELD(body, f32 *, 0xC);
    if (angleAt0C < 0x0.0p+0f) {
        angleAt0C += 0x1.921fb40000000p+2f;
        M2C_FIELD(body, f32 *, 0xC) = angleAt0C;
    }
    if (angleAt0C >= 0x1.921fb40000000p+2f) {
        M2C_FIELD(body, f32 *, 0xC) = (f32) (angleAt0C - 0x1.921fb40000000p+2f);
    }
    angleAt10 = M2C_FIELD(body, f32 *, 0x10);
    if (angleAt10 < 0x0.0p+0f) {
        angleAt10 += 0x1.921fb40000000p+2f;
        M2C_FIELD(body, f32 *, 0x10) = angleAt10;
    }
    if (angleAt10 >= 0x1.921fb40000000p+2f) {
        M2C_FIELD(body, f32 *, 0x10) = (f32) (angleAt10 - 0x1.921fb40000000p+2f);
    }
    M2C_FIELD(body, f32 *, 0x14) = (f32) (M2C_FIELD(body, f32 *, 0x14) + (M2C_FIELD(body, f32 *, 0x20) * timeStep));
    M2C_FIELD(body, f32 *, 0x18) = (f32) (M2C_FIELD(body, f32 *, 0x18) + (M2C_FIELD(body, f32 *, 0x24) * timeStep));
    M2C_FIELD(body, f32 *, 0x1C) = (f32) (M2C_FIELD(body, f32 *, 0x1C) + (M2C_FIELD(body, f32 *, 0x28) * timeStep));
    M2C_FIELD(body, f32 *, 0x20) = (f32) (M2C_FIELD(body, f32 *, 0x20) + (frame.force[0] * M2C_FIELD(M2C_FIELD(body, void **, 0x4C), f32 *, 0x10) * timeStep));
    properties4 = M2C_FIELD(body, void **, 0x4C);
    M2C_FIELD(body, f32 *, 0x24) = (f32) (M2C_FIELD(body, f32 *, 0x24) + (frame.force[1] * M2C_FIELD(properties4, f32 *, 0x10) * timeStep));
    M2C_FIELD(body, f32 *, 0x28) = (f32) (M2C_FIELD(body, f32 *, 0x28) + (frame.force[2] * M2C_FIELD(properties4, f32 *, 0x10) * timeStep));
    M2C_FIELD(body, f32 *, 0x2C) = (f32) (M2C_FIELD(body, f32 *, 0x2C) * 0x1.ff7cec0000000p-1f);
    M2C_FIELD(body, f32 *, 0x30) = (f32) (M2C_FIELD(body, f32 *, 0x30) * 0x1.ff7cec0000000p-1f);
    M2C_FIELD(body, f32 *, 0x34) = (f32) (M2C_FIELD(body, f32 *, 0x34) * 0x1.ff7cec0000000p-1f);
    if (((M2C_FIELD(body, f32 *, 0x38) * M2C_FIELD(body, f32 *, 0x14)) + (M2C_FIELD(body, f32 *, 0x3C) * M2C_FIELD(body, f32 *, 0x18)) + (M2C_FIELD(body, f32 *, 0x40) * M2C_FIELD(body, f32 *, 0x1C)) + M2C_FIELD(body, f32 *, 0x44)) < 0x0.0p+0f) {
        return 0;
    }
    return 1;
}
