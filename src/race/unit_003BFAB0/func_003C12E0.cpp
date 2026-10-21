/* Runs the library routine 005A609C on the sub-object embedded at +0x14, then sets the field at +0x24 to 1. The 1 is stored right after
 * the sub-object call, so it is probably an "initialised" flag (inferred from order only; purpose unknown). */
#include "types.h"

struct Obj {
    char pad[0x24];
    s32 readyFlag;
};

extern "C" s32 func_005A609C(char *self);

extern "C" void func_003C12E0(struct Obj *self) {
    func_005A609C((char *)self + 0x14);
    self->readyFlag = 1;
}
