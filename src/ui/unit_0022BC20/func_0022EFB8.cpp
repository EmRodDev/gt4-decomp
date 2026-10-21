/* Returns the total element count of two pointer-pair vectors embedded at +0x14 and +0x34 of the object ((end - begin) / 4 for each, summed).
 * The element type (4 bytes, pointer or int) and the owner class are unknown. */
#include "types.h"

struct Sub {
    char pad0[4];
    s32 unk4;
    s32 unk8;
};

extern "C" s32 func_0022EFB8(char *obj) {
    Sub *vecA = (Sub *)(obj + 0x14);
    Sub *vecB = (Sub *)(obj + 0x34);

    return ((s32)(vecA->unk8 - vecA->unk4) >> 2) + ((s32)(vecB->unk8 - vecB->unk4) >> 2);
}
