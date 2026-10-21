/* Sets bits 8..15 of the 64-bit word at +0x268 to the value 1 (bit 8 set, the rest of that byte cleared). Meaning unknown. */
#include "types.h"

struct Obj {
    char pad[0x268];
    s64 unk268;
};

extern "C" void func_005F5C98(Obj *self) {
    self->unk268 = (self->unk268 & ~(0xFFLL << 8)) | (1LL << 8);
}
