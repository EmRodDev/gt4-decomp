/* Returns one of two float fields (+0xC0 or +0xC4) depending on whether the integer field at +0xB0 is zero.
 * What the selector or the two values mean is unknown. */
#include "types.h"

struct Obj {
    char pad0[0xB0];
    s32 unkB0;
    char pad1[0xC0 - 0xB0 - 4];
    f32 unkC0;
    f32 unkC4;
};

extern "C" f32 func_002B1FE0(struct Obj *obj) {
    if (obj->unkB0 == 0) {
        return obj->unkC0;
    }
    return obj->unkC4;
}
