/* Returns the object's own value at +0x10 when the field at +0 is non-zero, otherwise the global default D_00623A38.
 * Used as an argument of func_0044D740 by func_00462738 (GTSOUNDINSTRUMENTJAM); the meaning of the value is unknown. */
#include "types.h"

struct Obj00462588 {
    s32 hasOwnValue; /* purpose inferred from use: selects the object's value over the global one */
    char pad[0x10 - 4];
    s32 ownValue;
};

extern s32 D_00623A38;

extern "C" s32 func_00462588(struct Obj00462588 *self) {
    return (self->hasOwnValue == 0) ? D_00623A38 : self->ownValue;
}
