#include "types.h"

struct Obj { char pad[0x694]; s16 unk694; };

extern "C" void func_003F37B8(Obj *arg0) {
    arg0->unk694 = 0;
}
