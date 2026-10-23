/* Returns 1 when the seven status words at +0x16C..+0x184 are all clear (the second one only
   needs to be non-negative), else 2. The whole test is one ?: expression: an if/else on the last
   word is if-converted to movn, while the conditional expression keeps the branch. */
#include "types.h"

struct func_004F0D48_a0 {
    char pad0[0x16C];
    s32 unk16C;
    s32 unk170;
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
};

extern "C" s32 func_004F0D48(struct func_004F0D48_a0 *a0) {
    return (a0->unk16C == 0 && a0->unk170 >= 0 && a0->unk174 == 0 && a0->unk178 == 0 &&
            a0->unk17C == 0 && a0->unk180 == 0 && a0->unk184 == 0) ? 1 : 2;
}
