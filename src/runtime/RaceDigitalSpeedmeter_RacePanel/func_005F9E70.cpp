/* Replaces the low byte of the word at +0x1C with value, keeping the upper 24 bits (field purpose unknown). */
#include "types.h"

struct Obj {
    char pad[0x1C];
    s32 unk1C;
};

extern "C" void func_005F9E70(Obj *self, u8 value) {
    self->unk1C = (self->unk1C & ~0xFF) | value;
}
