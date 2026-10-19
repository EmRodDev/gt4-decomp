#include "types.h"

struct Obj {
    char pad[0x268];
    u64 unk268;
};

extern "C" void func_005F5C30(Obj *arg0) {
    arg0->unk268 = arg0->unk268 & 0xFFFFFFFFFF00FFFFULL;
}
