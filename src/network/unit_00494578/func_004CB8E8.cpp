/* Computes (index - 2) << shift + base, with base at +0x60 and shift at +0x70: the address or offset of an element in a table whose first two indexes are reserved
 * (inferred from the - 2). */
#include "types.h"

struct Obj {
    char pad[0x60];
    s32 unk60;
    char pad2[0xC];
    s32 unk70;
};

extern "C" s32 func_004CB8E8(Obj *self, s32 index) {
    s32 shift = self->unk70;
    index = index - 2;
    return (index << shift) + self->unk60;
}
