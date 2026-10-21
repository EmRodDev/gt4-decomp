/* If the flag at +0x3F20 is set, clears the field at +0x3F24 and returns 1, otherwise returns 0 (an acknowledge/consume of a pending state, inferred from the shape). */
#include "types.h"

struct Obj004FFDD0 {
    char pad0[0x3F20];
    s32 unk3F20;
    s32 unk3F24;
};

extern "C" s32 func_004FFDD0(struct Obj004FFDD0 *self) {
    if (self->unk3F20 == 0) {
        return 0;
    }
    self->unk3F24 = 0;
    return 1;
}
