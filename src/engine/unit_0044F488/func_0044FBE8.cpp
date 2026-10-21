/* Setter: stores one 32-bit value at +0x100 (the getter is func_0044FBE0). Same unit and pattern as func_0044FBB8; field meaning unknown. */
#include "types.h"
struct func_0044FBE8_a0 {
    char pad0[0x100];
    s32 unk100;
};
extern "C" void func_0044FBE8(struct func_0044FBE8_a0 *self, s32 value) {
    self->unk100 = value;
}
