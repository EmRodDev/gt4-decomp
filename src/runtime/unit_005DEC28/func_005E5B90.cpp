#include "types.h"

struct Obj { char pad[0xB4]; u8 unk9C; };

extern "C" u64 func_005E5B90(Obj *arg0) {
    u64 v = arg0->unk9C;
    return v >> 7;
}
