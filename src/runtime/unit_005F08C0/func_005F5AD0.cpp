/* Array setter: stores value at +0x5C of element [index] in an array of 0x6C-byte elements starting at base. */
#include "types.h"

struct Elem005F5AD0 {
    char pad0[0x5C];
    f32 unk5C;
};

extern "C" void func_005F5AD0(char *base, s32 index, f32 value) {
    base = base + index * 0x6C;
    ((struct Elem005F5AD0 *)base)->unk5C = value;
}
