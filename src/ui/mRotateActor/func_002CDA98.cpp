#include "types.h"

struct S { char pad[0x30]; s32 unk30; };

extern "C" void func_002CDA98(S *arg0, s32 arg1) {
    arg0->unk30 = arg1;
}
