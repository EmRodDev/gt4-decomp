/* Returns how far the value at +0x18 lies between the range start at +0x10 and the range end at +0x14, as a fraction ((value - start) / (end - start)), or 1.0 when the range is empty (start == end).
 * (Field roles inferred from the interpolation formula.) */
#include "types.h"

struct Obj00228A38 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

extern "C" f32 func_00228A38(struct Obj00228A38 *obj) {
    f32 rangeStart = obj->unk10;
    f32 rangeEnd = obj->unk14;
    f32 fraction = 1.0f;

    if (rangeEnd != rangeStart) {
        fraction = (obj->unk18 - rangeStart) / (rangeEnd - rangeStart);
    }
    return fraction;
}
