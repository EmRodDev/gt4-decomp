/* Stores a 64-bit value as two words: the high half at +0 and the low half at +4 (big-endian word order, which is the opposite of the machine's own order). */
#include "types.h"

struct Obj001CB8D8 {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_001CB8D8(Obj001CB8D8 *self, s64 value) {
    self->unk0 = (s32)(value >> 32);
    self->unk4 = (s32)(value & 0xFFFFFFFFU);
}
