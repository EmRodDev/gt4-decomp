/* Runs a query (func_003FDD60) around the object's position with a radius derived from its view angle (unkC is a full angle in degrees:
 * the code halves it and converts to radians, inferred) and a size from virtual slot 0x90. The optional extraVec is added to
 * the extent vector first. Returns 0 when no target is given. */
#include "types.h"

struct VEntry00379B08 {
    s16 delta;
    s16 index;
    void *fn;
};

struct Obj00379B08 {
    void *vtbl;
    char pad4[8];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

extern "C" f32 func_0057D380(f32 x);
extern "C" void func_005F5230(f32 *self, s32 out);
extern "C" void func_005F5040(f32 *self, s32 out);
extern "C" s32 func_003FDD60(s32 a0, f32 *a1, f32 *a2);

extern "C" s32 func_00379B08(struct Obj00379B08 *self, s32 unusedArg, s32 queryTarget, s32 extraVec) {
    f32 extent[4];
    f32 centre[4];
    s32 result;
    f32 radius;
    f32 radiusExtra;
    f32 *p;
    struct VEntry00379B08 *e;

    result = 0;
    if (queryTarget != 0) {
        e = (struct VEntry00379B08 *)((char *)self->vtbl + 0x90);
        radius = ((f32 (*)(void *))e->fn)((char *)self + e->delta);
        radiusExtra = radius * func_0057D380((self->unkC * 0.5f * 3.14159265f) / 180.0f);
        radius = radius + radiusExtra;
        extent[0] = radius;
        extent[1] = radius;
        extent[2] = radius;
        if (extraVec != 0) {
            func_005F5230(extent, extraVec);
            func_005F5040(extent, extraVec);
        }
        p = centre;
        *p = self->unk10;
        centre[1] = self->unk14;
        centre[2] = self->unk18;
        result = func_003FDD60(queryTarget, centre, extent);
    }
    return result;
}
