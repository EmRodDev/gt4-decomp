/* Returns the 16-bit field at +0x20 (converted to float) divided by the float at +0x1C; there is no check for a zero divisor.
 * Purpose unknown. */
#include "types.h"
struct Obj {
    char pad[0x1C];
    f32 divisor;
    char pad2[0x20 - 0x1C - 4];
    s16 numerator;
};
extern "C" f32 func_004743D0(struct Obj *self) {
    return (f32)self->numerator / self->divisor;
}
