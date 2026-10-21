/* Copy-assignment for a 4-float vector (x, y, z, w): copies all four components unless source and destination are the same object, then returns the destination. */
#include "types.h"

struct Vec4 {
    f32 x, y, z, w;
};

extern "C" Vec4 *func_002030E8(Vec4 *dst, Vec4 *src) {
    if (dst != src) {
        dst->x = src->x;
        dst->y = src->y;
        dst->z = src->z;
        dst->w = src->w;
    }
    return dst;
}
