/* Setter: stores one 32-bit value at +0x10C. Sits in unit_0044F488, the DRIVERSUPPORT_NAME (motorist parameter) unit, next to the
 * matching getter/setter pairs for +0x100..+0x114 (inferred from the unit); the meaning of the field is unknown. */
#include "types.h"
struct func_0044FBB8_a0 {
    char pad0[0x10C];
    s32 unk10C;
};
extern "C" void func_0044FBB8(struct func_0044FBB8_a0 *self, s32 value) {
    self->unk10C = value;
}
