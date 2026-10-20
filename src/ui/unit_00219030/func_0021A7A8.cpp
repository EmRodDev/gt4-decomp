#include "types.h"

struct S { char pad[0x14]; s32 unk14; };

extern "C" s32 func_0021A7A8(S *arg0) {
    return arg0->unk14;
}
