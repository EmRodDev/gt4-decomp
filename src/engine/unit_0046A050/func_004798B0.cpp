/* Returns the sum of the two 16-bit fields at +0x12 and +0x14 (for example a width made of two parts; purpose unknown).
 * func_004798C0 is the same function with local typedefs. */
#include "types.h"
struct Obj004798B0 {
    char pad[0x12];
    s16 unk12;
    s16 unk14;
};
extern "C" s32 func_004798B0(struct Obj004798B0 *self) {
    return self->unk12 + self->unk14;
}
