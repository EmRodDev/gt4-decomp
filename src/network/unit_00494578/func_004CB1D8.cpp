#include "types.h"

struct Obj {
    char pad[0xB];
    u8 unkB;
};

extern "C" s32 func_004CB1D8(Obj *arg0) {
    return (arg0->unkB & 0x3F) == 0xF;
}
