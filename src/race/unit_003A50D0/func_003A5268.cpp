/* Stores value at +0x2C and runs the library routine 005A609C on the sub-object at +0x30 (the same call 003C12E0 makes on its sub-object,
 * so likely a shared embedded-object constructor; inferred). The second parameter is not used. Purpose unknown. */
#include "types.h"

struct S003A5268 {
    char pad0[0x2C];
    s32 unk2C;
};

extern "C" void func_005A609C(void *self);

extern "C" void func_003A5268(struct S003A5268 *self, s32 arg1, s32 value) {
    self->unk2C = value;
    func_005A609C((char *)self + 0x30);
}
