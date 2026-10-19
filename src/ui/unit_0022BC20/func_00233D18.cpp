#include "types.h"

struct Obj {
    char pad0[0xE8];
    u32 unkE8;
};

extern "C" void func_00233D18(Obj *arg0) {
    arg0->unkE8 = arg0->unkE8 | 8;
}
