/* Writes bit 3 of the four-flag low nibble at +0x98 from the argument (nonzero = set), keeping the other three flags.
 * The nibble is cleared and re-merged in one store, which is the shape the compiler produced for this accessor.
 * Siblings func_00266060, func_00266100, func_002661A0, func_002661D8 write bits 0 to 3. */
#include "types.h"

struct Obj {
    char pad[0x98];
    s32 unk98;
};

extern "C" void func_002661D8(Obj *obj, s32 enable) {
    s32 flags = obj->unk98;
    s32 keptBits = flags & 7;
    flags &= ~0xF;
    s32 newBits = keptBits;
    if (enable != 0) {
        newBits = keptBits | 8;
    }
    obj->unk98 = flags | newBits;
}
