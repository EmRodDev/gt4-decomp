/* Setter: stores one 32-bit value at +0x104 (the getter is func_0044FBF0). Same unit and pattern as func_0044FBB8; field meaning unknown. */
#include "types.h"
struct func_0044FBF8_a0 {
    char pad0[0x104];
    s32 unk104;
};
extern "C" void func_0044FBF8(struct func_0044FBF8_a0 *self, s32 value) {
    self->unk104 = value;
}
