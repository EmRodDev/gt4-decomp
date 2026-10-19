#include "types.h"

struct Obj {
    char pad[0xD8];
    f32 unkD8;
};

extern "C" f32 func_0036FFC0(void *cam, f32 x);

extern "C" f32 func_00370188(Obj *arg0) {
    return func_0036FFC0(arg0, arg0->unkD8);
}
