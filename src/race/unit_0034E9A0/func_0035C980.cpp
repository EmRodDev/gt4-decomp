#include "types.h"

struct Obj;
extern "C" s32 func_0035C828(Obj *);
extern "C" signed char D_00620890[];

extern "C" s32 func_0035C980(Obj *arg0) {
    return D_00620890[func_0035C828(arg0)] == 2;
}
