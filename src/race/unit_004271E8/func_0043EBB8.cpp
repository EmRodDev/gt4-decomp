#include "types.h"

struct Obj {
    char pad[0x490];
    s32 unk490;
};

extern "C" u8 func_0043EBB8(Obj *arg0) {
    return *((u8 *)((char *)arg0 + arg0->unk490 * 0x178) + 0x132);
}
