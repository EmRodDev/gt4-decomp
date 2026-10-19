#include "types.h"

struct Obj {
    char pad0[8];
    s32 unk8;
};

extern "C" s32 func_0046BC00(s32 arg0);

extern "C" s32 func_0046BC80(Obj *arg0)
{
    return func_0046BC00(arg0->unk8);
}
