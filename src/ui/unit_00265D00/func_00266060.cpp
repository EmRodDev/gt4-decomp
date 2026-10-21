/* Writes bit 0 of the low-nibble flags at +0x98 from the argument (nonzero = set), preserving bits 1-3 and clearing the rest of the nibble first.
 * The nibble looks like a small mode field whose other bits are owned by sibling setters (func_002661A0 sets bit 2). */
#include "types.h"

struct Obj {
    char pad[0x98];
    s32 unk98;
};

extern "C" void func_00266060(Obj *obj, s32 enable) {
    s32 oldFlags = obj->unk98;
    s32 newBits = oldFlags & 0xE;
    if (enable != 0) {
        newBits = newBits | 1;
    }
    obj->unk98 = (oldFlags & ~0xF) | newBits;
}
