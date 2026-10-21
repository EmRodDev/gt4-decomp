/* Writes the integer at +8 of the object that arg1's field at +0x1C points to into *arg0 and returns arg0 (the output-pointer form of func_003065D8). */
#include "types.h"

struct Inner {
    char pad[0x8];
    s32 unk8;
};

struct Arg1 {
    char pad[0x1C];
    Inner *unk1C;
};

extern "C" s32 *func_003065B0(s32 *out, Arg1 *source) {
    *out = source->unk1C->unk8;
    return out;
}
