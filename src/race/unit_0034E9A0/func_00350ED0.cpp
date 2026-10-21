/* Advances a damped spring by one step (same shape as func_00350D40, but with the step read from +0x54C): position +0x738 is pulled toward
 * the 16-bit value at +0x5FE with stiffness 1000 and damping 50 (hex floats 0x1.F4p+9 and 0x1.9p+5); velocity is kept at +0x73C. */
#include "types.h"

struct func_00350ED0_arg0 {
    char pad0[0x54C];
    f32 unk54C;
    char pad550[0xAE];
    s16 unk5FE;
    char pad600[0x138];
    f32 unk738;
    f32 unk73C;
};

void func_00350ED0(struct func_00350ED0_arg0 *self) {
    f32 *position = &self->unk738;
    f32 *velocity = &self->unk73C;
    f32 oldVelocity;
    f32 timeStep;
    f32 newVelocity;

    oldVelocity = *velocity;
    timeStep = self->unk54C;
    newVelocity = oldVelocity + (((((f32) self->unk5FE - *position) * 0x1.F4p+9f) - (oldVelocity * 0x1.9p+5f)) * timeStep);
    *velocity = newVelocity;
    *position = *position + (newVelocity * timeStep);
}
