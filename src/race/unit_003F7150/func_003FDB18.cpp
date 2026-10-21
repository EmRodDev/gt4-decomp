/* Detects whether a position was crossed (inferred): returns 1 when one of the listed marker values lies strictly between the
 * previous position (func_003FC5F8) and the current one at +0x34, provided the car moved less than 30 units; otherwise 0. */
#include "types.h"

struct Obj_003FDB18_s0 {
    char pad0[0x34];
    s32 unk34;
    f32 *unk38;
};

struct Obj_003FDB18_v2 {
    char pad0[0xB0];
    struct Obj_003FDB18_s0 *unkB0;
};

struct Obj_003FDB18_v1 {
    char pad0[0x4];
    struct Obj_003FDB18_v2 *unk4;
};

struct Obj_003FDB18_arg0 {
    char pad0[0x80];
    struct Obj_003FDB18_v1 *unk80;
};

struct Obj_003FDB18_a1 {
    char pad0[0x34];
    f32 unk34;
};

extern "C" f32 func_003FC5F8(struct Obj_003FDB18_a1 *arg0);

extern "C" s32 func_003FDB18(struct Obj_003FDB18_arg0 *arg0, struct Obj_003FDB18_a1 *arg1) {
    f32 currentPos = arg1->unk34;
    struct Obj_003FDB18_s0 *markerTable = arg0->unk80->unk4->unkB0;
    s32 markerCount = markerTable->unk34;
    f32 previousPos = func_003FC5F8(arg1);
    s32 i;

    if (currentPos <= previousPos)
        return 0;
    if (previousPos + 0x1.Ep4f < currentPos)
        return 0;

    i = 0;
    while (i < markerCount) {
        f32 marker = markerTable->unk38[i];
        i++;
        if (previousPos < marker && marker < currentPos)
            return 1;
    }
    return 0;
}
