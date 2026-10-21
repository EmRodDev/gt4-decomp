/* mMovieFace member (class taken from the directory): stores the first argument at +0x158 and passes the second to the
 * embedded sub-object at +0x118 (callee func_005A609C). Purpose of both unknown. */
#include "types.h"

struct Obj {
    char pad0[0x118];
    char embedded118[0x158 - 0x118];
    s32 unk158;
};

extern "C" void func_005A609C(char *sub, s32 value);

extern "C" void func_0021F310(Obj *self, s32 value, s32 subValue) {
    self->unk158 = value;
    func_005A609C((char *)self + 0x118, subValue);
}
