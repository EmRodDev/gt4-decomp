/* Predicate with the shape of a virtual method (its second parameter is unused; inferred): returns whether the signed byte at
 * owner->(+0x14) + byteOffset + 0x164 is zero. Five functions of this unit have the identical body (00380D80, 00381BC8, 00382C40,
 * 00384340, 0037F4C8: probably one per class that overrides the same slot, inferred); which flag the byte is is purpose unknown. */
#include "types.h"

struct Obj2 {
    char pad[0x14];
    char *unk14;
};

extern "C" s32 func_0037F4C8(s32 byteOffset, s32 unusedArg, struct Obj2 *owner) {
    char *flagAddress = owner->unk14 + byteOffset;
    s8 flagByte = *(s8 *)(flagAddress + 0x164);
    return flagByte == 0;
}
