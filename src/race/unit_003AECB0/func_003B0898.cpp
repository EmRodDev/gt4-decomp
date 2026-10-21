/* Copies 16 floats (64 bytes, the size of a 4x4 matrix; inferred from the count only) from the source address to
 * destination + 8, one float per iteration. memcpy is declared but not used: the loop is the form that matched. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_003B0898(s32 dstBase, s32 srcBase) {
    s32 byteOffset;
    s32 i;
    s8 *dstBytes;

    dstBytes = (s8 *)(dstBase + 8);
    i = 0;
    do {
        byteOffset = i * 4;
        i += 1;
        *(f32 *)(dstBytes + byteOffset) = *(f32 *)(byteOffset + srcBase);
    } while (i < 0x10);
}
