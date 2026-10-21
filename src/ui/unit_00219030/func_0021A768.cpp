/* Copy-assignment for a 4-float vector (x, y, z, w): copies all components unless source and destination are the same object. */
#include "types.h"

struct Vec4_0021A768 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern "C" void func_0021A768(struct Vec4_0021A768 *dst, struct Vec4_0021A768 *src) {
    if (dst != src) {
        dst->x = src->x;
        dst->y = src->y;
        dst->z = src->z;
        dst->w = src->w;
    }
}
