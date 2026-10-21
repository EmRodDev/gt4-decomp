/* Reads a position from the sub-state at +0x104 into the output vector as (value at +0x61C, value at +0x624, minus the value at +0x620),
 * i.e. the second and third components are swapped and one negated (pattern read from the code, probably a change of axis
 * convention; meaning of the position unknown). Returns 0 without writing when byte 0xCBDE of the object linked at +4 is 2
 * or when the int at +0x628 is negative; returns 1 otherwise. */
#include "types.h"

struct Sub {
    char pad[0xCBDE];
    u8 unkCBDE;
};

struct Obj_00350CE8 {
    char pad0[4];
    Sub *unk4;
};

struct Cam_00350CE8 {
    char pad[0x61C];
    f32 unk61C;
    f32 unk620;
    f32 unk624;
    s32 unk628;
};

struct V3_00350CE8 {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" s32 func_00350CE8(Obj_00350CE8 *self, V3_00350CE8 *out) {
    Cam_00350CE8 *state = (Cam_00350CE8 *)((char *)self + 0x104);

    if (self->unk4->unkCBDE == 2) {
        return 0;
    }
    if (state->unk628 < 0) {
        return 0;
    }
    out->x = state->unk61C;
    out->y = state->unk624;
    out->z = -state->unk620;
    return 1;
}
