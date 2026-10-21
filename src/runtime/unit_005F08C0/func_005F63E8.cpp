/* Copies 0x48 (72) floats, 288 bytes, from src to dst one word at a time and returns dst (a fixed-size copy loop). */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005F63E8(s32 dst, s32 src) {
    s32 byteOffset;
    s32 i;

    i = 0;
    do {
        byteOffset = i * 4;
        i += 1;
        *(f32 *)(dst + byteOffset) = *(f32 *)(src + byteOffset);
    } while (i < 0x48);
    return dst;
}
