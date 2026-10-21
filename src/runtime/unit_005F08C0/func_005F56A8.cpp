/* Array accessor: returns the float at +0xC of element [index] in an array of 0x6C-byte elements starting at base. */
#include "types.h"

struct Elem005F56A8 {
    char pad0[0xC];
    f32 unkC;
};

extern "C" f32 func_005F56A8(char *base, s32 index) {
    base = base + index * 0x6C;
    return ((struct Elem005F56A8 *)base)->unkC;
}
