#include "types.h"

struct S { char pad[0x188]; s32 unk188; };

extern "C" s32 RaceInput__getButtons(S *arg0) {
    return arg0->unk188;
}
