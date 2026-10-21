/* Returns the integer field at +0x178 of the object as a float in hundredths (divided by 100; a fixed-point value, inferred from the divisor).
 * The object is an mCarGarage-range method (inferred from the directory); what the value means is unknown. */
#include "types.h"

struct Obj001465D8 {
    char pad0[0x178];
    s32 unk178;
};

extern "C" f32 func_001465D8(struct Obj001465D8 *self) {
    return (f32)self->unk178 / 100.0f;
}
