#include "types.h"

struct Obj {
    char pad0[0x80];
    s32 unk80;
};

extern "C" void func_00529760(Obj *arg0, s32 arg1) {
    if (arg0 != 0) {
        arg0->unk80 = arg1;
    }
}
