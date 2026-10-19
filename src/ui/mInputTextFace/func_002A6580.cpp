#include "types.h"

struct S { char pad[0x164]; s32 unk164; };

extern "C" s32 func_002A6580(S *arg0) {
    return arg0->unk164 == 6;
}
