/* Re-initialises the sub-object at +0xCC with the given value (callee func_00330AE8, third argument 0), then clears the
 * field at +0x140 (purpose unknown). Shape of a reset/constructor helper, inferred from the call-then-clear order. */
#include "types.h"

struct Obj003354B8 {
    char pad[0x140];
    s32 unk140;
};

extern "C" void func_00330AE8(char *arg0, s32 arg1, s32 arg2);

extern "C" void func_003354B8(struct Obj003354B8 *self, s32 value) {
    func_00330AE8((char *)self + 0xCC, value, 0);
    self->unk140 = 0;
}
