/* Setter: stores one 32-bit value at +0x114. Same unit and pattern as func_0044FBB8; field meaning unknown. */
#include "types.h"
struct func_0044FBD8_a0 {
    char pad0[0x114];
    s32 unk114;
};
extern "C" void func_0044FBD8(struct func_0044FBD8_a0 *self, s32 value) {
    self->unk114 = value;
}
