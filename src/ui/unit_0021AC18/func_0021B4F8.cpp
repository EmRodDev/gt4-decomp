/* Advances a float accumulator at +0x14 by `elapsed` only when both the fields at +0x8 and +0x10 are nonzero (a timer that runs while active, inferred from the guarded add). */
#include "types.h"

struct Obj {
    char pad[0x8];
    s32 unk8;
    char pad2[4];
    s32 unk10;
    f32 unk14;
};

extern "C" void func_0021B4F8(struct Obj *obj, f32 elapsed) {
    if (obj->unk8 != 0) {
        if (obj->unk10 != 0) {
            obj->unk14 = obj->unk14 + elapsed;
        }
    }
}
