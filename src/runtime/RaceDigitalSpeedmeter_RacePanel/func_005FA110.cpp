#include "types.h"

struct Obj {
    char pad[0x388];
    s32 unk388;
};

extern "C" void func_005FA110(Obj *arg0, u8 arg1) {
    arg0->unk388 = (arg0->unk388 & ~0xFF) | arg1;
}
