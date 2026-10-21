/* Stores value in the signed byte at +0x520 of the sub-state at +0x104, except when the owner's type byte (reached through
 * the pointer at +0x10, offset 0x32) is 4 and the value is 0: then the store is skipped. Meaning of type 4 unknown. */
#include "types.h"

struct Inner {
    char pad[0x32];
    u8 unk32;
};

struct Sub {
    char pad[0x520];
    s8 unk520;
};

struct Obj {
    char pad0[0x10];
    Inner *unk10;
};

extern "C" void func_0036BEB8(Obj *self, int value) {
    u8 ownerType = self->unk10->unk32;
    Sub *sub = (Sub *)((char *)self + 0x104);
    if (ownerType != 4 || value != 0) {
        sub->unk520 = value;
    }
}
