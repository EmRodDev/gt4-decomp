#include "types.h"

struct Obj {
    char pad[0x70];
    s32 unk70;
};

extern "C" void func_006017E8(struct Obj *arg0, f32 arg1) {
    arg0->unk70 = (s32)(arg1 * 128.0f);
}
