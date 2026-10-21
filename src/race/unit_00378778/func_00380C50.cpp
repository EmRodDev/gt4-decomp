/* Visibility-style test for a camera (inferred from the degree-to-radian half-angle): builds a cube extent of size
 * target.unk44 * 0.7002 / tan-like(fov / 2) + 0.5, asks the scene whether that volume at the camera position is free
 * (func_003FDD60, inverted), and also fails when the field of view is wider than the angle derived from the camera's unk20.
 * Returns non-zero when the shot is acceptable (meaning inferred). */
#include "types.h"

struct Inner {
    char pad0[0x20];
    f32 unk20;
};

struct Self {
    char pad0[0x184];
    struct Inner *unk184;
};

struct Arg2 {
    char pad0[0x44];
    f32 unk44;
};

extern "C" s32 func_003FDD60(s32 a, void *b, f32 *c);
extern "C" f32 func_0057D008(f32 x);
extern "C" f32 func_0057D380(f32 x);

extern "C" s32 func_00380C50(struct Self *self, s32 scene, struct Arg2 *target, f32 fovDegrees) {
    f32 extentVec[3];
    struct Inner *camera;
    f32 extent;
    s32 result;

    camera = self->unk184;
    extent = target->unk44 * 0.70020754f * (1.0f / func_0057D380(fovDegrees * 0.5f * 0.017453292f)) + 0.5f;
    extentVec[0] = extent;
    extentVec[1] = extent;
    extentVec[2] = extent;
    result = func_003FDD60(scene, (char *)camera + 4, extentVec) ^ 1;
    if (fovDegrees < (2.0f * func_0057D008(1.0f / ((2.0f * camera->unk20) / 0.7f))) / 0.017453292f) {
        result = 0;
    }
    return result;
}
