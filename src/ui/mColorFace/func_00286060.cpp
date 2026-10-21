/* Returns the number of 16-byte entries in the vector member at +0xA0 of mColorFace (begin/end pointer pair, inferred from the shift by 4). */
#include "types.h"

struct S_Vec {
    char pad0[4];
    char *unk4;
    char *unk8;
    s32 size() { return (s32)(unk8 - unk4) >> 4; }
};

struct mColorFace {
    char pad0[0xA0];
    S_Vec vec;
};

extern "C" s32 func_00286060(mColorFace *face) {
    return face->vec.size();
}
