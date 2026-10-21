/* Pushes an object up out of a plane (inferred from the signed-distance test): for each of pointCount points it evaluates the plane
 * stored at +0x34 (normal and offset), counts consecutive frames a point stays below it and finds the deepest vertical
 * penetration. The object's height at +0x14 rises by that amount and the deepest point is passed on for the contact response. */
#include "types.h"

extern "C" void func_003E3218(void *a0);
extern "C" void func_003E3840(void *a0, s32 a1, void *a2);

extern "C" void func_003E3748(char *body, char *points, s32 pointCount) {
    char *point = points;
    f32 best = 0.0f;
    s32 bestIdx = -1;
    s32 i = 0;
    if (pointCount > 0) {
        do {
            f32 px = *(f32 *)point;
            f32 planeNy = *(f32 *)(body + 0x38);
            f32 planeNx = *(f32 *)(body + 0x34);
            f32 planeD = *(f32 *)(body + 0x40);
            f32 planeNz = *(f32 *)(body + 0x3C);
            f32 py = *(f32 *)(point + 4);
            f32 pz = *(f32 *)(point + 8);
            f32 signedDist = px * planeNx + py * planeNy + pz * planeNz + planeD;
            point += 12;
            if (signedDist < 0.0f) {
                f32 penetration = -(px * planeNx + pz * planeNz + planeD) / planeNy - py;
                if (best < penetration) {
                    best = penetration;
                    bestIdx = i;
                    ((u8 *)body)[0x58 + i] = ((u8 *)body)[0x58 + i] + 1;
                }
            } else {
                ((u8 *)body)[0x58 + i] = 0;
            }
            i++;
        } while (i < pointCount);
    }
    *(f32 *)(body + 0x14) = *(f32 *)(body + 0x14) + best;
    if (bestIdx >= 0) {
        func_003E3840(body, bestIdx, (void *)((char *)body + 0x34));
    }
    func_003E3218(body);
}
