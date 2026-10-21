/* Setter: stores one 32-bit value at +0x110. Same unit and pattern as func_0044FBB8; field meaning unknown. */
#include "types.h"
struct func_0044FBC8_a0 {
    char pad0[0x110];
    s32 unk110;
};
extern "C" void func_0044FBC8(struct func_0044FBC8_a0 *self, s32 value) {
    self->unk110 = value;
}
