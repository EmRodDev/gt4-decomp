/* Returns the address of entry `index` of the vector of 16-byte elements at +0xA0, with the index clamped to [0, count - 1].
 * The vector is stored as a begin/end pointer pair (hence the (end - begin) >> 4 element count). */
#include "types.h"

struct Sub {
    char pad0[4];
    s32 begin;
    s32 end;
};

struct Obj {
    char pad0[0xA0];
    struct Sub vec;
};

extern "C" s32 func_002861D8(struct Obj *face, s32 index) {
    struct Sub *vec = &face->vec;
    s32 begin = vec->begin;
    s32 end = vec->end;
    s32 clampedIndex = (index < 0) ? 0 : index;
    s32 count = (end - begin) >> 4;
    s32 inRange = (clampedIndex < count);
    s32 lastIndex = count - 1;
    clampedIndex = inRange ? clampedIndex : lastIndex;
    return begin + clampedIndex * 0x10;
}
