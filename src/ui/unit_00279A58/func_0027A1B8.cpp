/* Counts down a float timer at +0x18: while it is positive it is reduced by the argument (elapsed time, inferred from the countdown shape) and 1 is returned; once it is zero or below, returns 0. */
#include "types.h"

struct Obj {
    char pad0[0x18];
    f32 unk18;
};

extern "C" s32 func_0027A1B8(struct Obj *obj, f32 elapsed) {
    f32 remaining = obj->unk18;

    if (remaining > 0.0f) {
        obj->unk18 = (f32)(remaining - elapsed);
        return 1;
    }
    return 0;
}
