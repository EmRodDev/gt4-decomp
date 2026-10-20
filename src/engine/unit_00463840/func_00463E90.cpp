#include "types.h"

struct Obj { char pad[0x1B]; s8 unk1B; };

extern "C" void func_00463E90(Obj *arg0) {
    arg0->unk1B = 0;
}
