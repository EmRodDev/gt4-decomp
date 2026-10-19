#include "types.h"

struct Obj {
    char pad[0xEC];
    u8 unkEC;
    u8 unkED;
};

void func_002A39D8(Obj *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = arg0->unkEC;
    *arg2 = arg0->unkED;
}
