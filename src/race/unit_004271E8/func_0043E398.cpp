#include "types.h"

struct Obj {
    char pad[0x490];
    s32 unk490;
};

extern "C" void func_0043E398(Obj *arg0, s8 arg1) {
    *(s8 *)((char *)arg0 + arg0->unk490 * 0x178 + 0x136) = arg1;
}
