/* Sets the value at +0x28 and derives the flag at +0x38 from it: the flag is 1 for any value except 0 and 9 (so those two values
 * mean 'off' in some sense; the meaning of the value itself is unknown). Callers are the movie/texture code in unit_001C4BE0
 * (func_001D6378, func_001D6968), which call it with 0 or with a texture header field. */
#include "types.h"

struct Obj {
    char pad0[0x28];
    s32 unk28;
    char pad1[0x38 - 0x28 - 4];
    s32 flag38;
};

extern "C" void func_001054A0(Obj *self, s32 value) {
    s32 flag;

    self->unk28 = value;
    flag = 0;
    if (value != 0) {
        flag = value != 9;
    }
    self->flag38 = flag;
}
