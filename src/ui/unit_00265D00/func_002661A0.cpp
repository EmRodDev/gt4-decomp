/* Writes bit 2 of the low-nibble flags at +0x98 from the argument (nonzero = set), preserving the other low bits.
 * Sibling of func_00266060, which writes bit 0. */
#include "types.h"

struct Obj {
    char pad[0x98];
    s32 unk98;
};

extern "C" void func_002661A0(Obj *obj, s32 enable) {
    s32 oldFlags = obj->unk98;
    s32 newBits = oldFlags & 0xB;
    if (enable != 0) {
        newBits = newBits | 4;
    }
    obj->unk98 = (oldFlags & ~0xF) | newBits;
}
