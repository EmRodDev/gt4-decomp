/* Two easing steps: (1) the value at +0x5CC moves toward the target at +0x5C4 by at most 111.11 * the scale at +0x54C per call; (2) a
 * damped spring (stiffness 200, damping 20, step 1/60, same shape as func_00350D40) pulls the position at +0x560 toward the
 * target at +0x554 with velocity at +0x55C. */
#include "types.h"

void func_0035DC08(void *arg0) {
    char *state = (char *)arg0 + 0x104;
    f32 current = *(f32 *)(state + 0x5CC);
    f32 target = *(f32 *)(state + 0x5C4);
    f32 maxStep = *(f32 *)((char *)arg0 + 0x54C) * 111.1111f;
    f32 moved;
    f32 springPos;
    f32 springVel;
    f32 newVel;

    if (current < target) {
        moved = current + maxStep;
        *(f32 *)(state + 0x5CC) = moved;
        if (target < moved) {
            *(f32 *)(state + 0x5CC) = target;
        }
    } else {
        moved = current - maxStep;
        *(f32 *)(state + 0x5CC) = moved;
        if (moved < target) {
            *(f32 *)(state + 0x5CC) = target;
        }
    }
    springPos = *(f32 *)(state + 0x560);
    springVel = *(f32 *)(state + 0x55C);
    newVel = springVel + ((((*(f32 *)(state + 0x554) - springPos) * 200.0f) - (springVel * 20.0f)) * 0x1.111110p-6f);
    *(f32 *)(state + 0x55C) = newVel;
    *(f32 *)(state + 0x560) = springPos + newVel * 0x1.111110p-6f;
}
