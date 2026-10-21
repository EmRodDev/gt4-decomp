/* Returns 1 when either the field at +0x88 or the field at +0xD8 is nonzero, else 0 (an 'is anything set' test; field meanings unknown). */
#include "types.h"

struct Struct_001FE1D8 {
    char pad0[0x88];
    s32 unk88;
    char pad8C[0xD8 - 0x88 - 4];
    s32 unkD8;
};

extern "C" s32 func_001FE1D8(struct Struct_001FE1D8 *obj) {
    s32 result;

    result = 0;
    if ((obj->unk88 != 0) || (obj->unkD8 != 0)) {
        result = 1;
    }
    return result;
}
