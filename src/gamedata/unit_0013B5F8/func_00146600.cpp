/* Returns the integer field at +0x184 of the object as a float in hundredths (divided by 100; a fixed-point value, inferred from the divisor).
 * Sibling of func_001465D8 (+0x178); what the value means is unknown. */
#include "types.h"

struct Obj00146600 {
    char pad0[0x184];
    s32 unk184;
};

extern "C" f32 func_00146600(struct Obj00146600 *self) {
    return (f32)self->unk184 / 100.0f;
}
