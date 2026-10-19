#include "types.h"

struct Obj { char pad[0x98]; s32 unk98; };

extern "C" s32 func_00268440(Obj *arg0) {
    return ((u32)arg0->unk98 >> 0x1B) & 0xF;
}
