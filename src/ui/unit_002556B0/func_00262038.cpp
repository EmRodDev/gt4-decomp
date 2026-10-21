/* Builds a Vec4 in place: a zeroed temporary is filled by func_00261FF8 from the argument, then copied into self, which is returned.
 * The zero-fill before the call is kept because the original does it; what func_00261FF8 converts from is unknown. */
#include "types.h"

struct Vec4_00262038 {
    f32 x, y, z, w;
};

extern "C" void func_00261FF8(s32 arg0, Vec4_00262038 *out);

extern "C" void *func_00262038(Vec4_00262038 *self, s32 source) {
    Vec4_00262038 tmp;
    f32 zeroValue = 0.0f;
    tmp.x = zeroValue;
    tmp.y = zeroValue;
    tmp.z = zeroValue;
    tmp.w = zeroValue;
    func_00261FF8(source, &tmp);
    self->x = tmp.x;
    self->y = tmp.y;
    self->z = tmp.z;
    self->w = tmp.w;
    return self;
}
