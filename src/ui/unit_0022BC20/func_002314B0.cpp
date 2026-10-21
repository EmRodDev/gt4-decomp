/* Copy-assignment into the Vec4 stored at +0x710 of the object: copies x, y, z, w from the source unless the source is that very member. */
#include "types.h"

struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

struct Struct_002314B0 {
    char pad0[0x710];
    Vec4 unk710;
};

extern "C" void func_002314B0(struct Struct_002314B0 *obj, Vec4 *src) {
    Vec4 *dst = &obj->unk710;

    if (dst != src) {
        dst->x = src->x;
        dst->y = src->y;
        dst->z = src->z;
        dst->w = src->w;
    }
}
