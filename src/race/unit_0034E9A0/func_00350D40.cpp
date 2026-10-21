/* Advances a damped spring by one 1/60 s step (inferred from the arithmetic): the velocity at +0x640 gains
 * ((target at +0x588 - position at +0x63C) * 500 - velocity * 20) / 60, then the position at +0x63C gains velocity / 60.
 * 500 acts as stiffness and 20 as damping. The step 1/60 is written as the hex float literal 0x1.111110p-6f, which is what matched. */
#include "types.h"

void func_00350D40(void *self) {
    f32 timeStep = 0x1.111110p-6f;
    f32 *position = (f32 *)((char *)self + 0x63C);
    f32 target = *(f32 *)((char *)self + 0x588);
    f32 positionBefore = *position;
    f32 *velocity = (f32 *)((char *)self + 0x640);
    f32 oldVelocity = *velocity;
    f32 newVelocity;
    f32 displacement;

    newVelocity = oldVelocity + ((((target - positionBefore) * 500.0f) - (oldVelocity * 20.0f)) * timeStep);
    *velocity = newVelocity;
    displacement = newVelocity * timeStep;
    *position = *position + displacement;
}
