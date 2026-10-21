/* Stores 'value' into the field at +0x30, but stores 0 instead when the signed field at +0 is negative (a negative value there
 * acts as an 'invalid / unset' marker, inferred from the test). What the object is and what +0x30 holds are unknown. */
#include "types.h"

struct Obj {
    s32 unk0;
    char pad[0x2C];
    s32 unk30;
};

extern "C" void func_00105510(Obj *self, s32 value) {
    self->unk30 = (self->unk0 < 0) ? 0 : value;
}
