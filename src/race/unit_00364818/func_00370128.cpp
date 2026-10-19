#include "types.h"

struct Obj {
    char pad[0x34];
    f32 unk34;
};

extern "C" f32 func_0036FFC0(void *cam, f32 x);

extern "C" f32 func_00370128(Obj *arg0) {
    return func_0036FFC0(arg0, arg0->unk34);
}
