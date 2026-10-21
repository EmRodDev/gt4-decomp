/* Linear interpolation between 'from' and 'to' by a 16-bit fixed-point fraction at +0x68: weight = value / 32768 (the constant
 * 0.000030517578125 is 2^-15), result = from + (to - from) * weight. So 0 gives 'from' and 0x8000 gives 'to'. */
#include "types.h"
struct Obj {
    char pad[0x68];
    u16 weight;
};
extern "C" f32 func_00463988(Obj *self, f32 from, f32 to) {
    return from + ((to - from) * ((f32)self->weight * 0.000030517578125f));
}
