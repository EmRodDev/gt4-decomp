/* Setter: stores one 32-bit value into the field at +0x108 of the object. What the field means is unknown (purpose unknown). */
#include "types.h"
struct func_0044FBA8_a0 {
    char pad0[0x108];
    s32 unk108;
};

extern "C" void func_0044FBA8(struct func_0044FBA8_a0 *self, s32 value) {
    self->unk108 = value;
}
