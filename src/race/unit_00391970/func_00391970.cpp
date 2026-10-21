/* Copies a described byte range into the buffer at +0x24 of the object and returns the object. The descriptor holds
 * the source address at +4 and the byte count at +8 (inferred from the memcpy argument order).
 * memcpy is declared with integer arguments here because that is the declaration that matched. */
#include "types.h"

struct ByteSpan {
    char pad0[4];
    s32 source;
    s32 byteCount;
};

extern "C" void memcpy(void *dest, s32 source, s32 size);

extern "C" void *func_00391970(void *self, ByteSpan *span) {
    memcpy((char *)self + 0x24, span->source, span->byteCount);
    return self;
}
