/* Returns whether func_0054C7B0 (applied to the field at +4 of the object) equals 2; a state test, the state values are not identified. */
#include "types.h"

struct Struct_001D1720 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" s32 func_0054C7B0(s32 self);

extern "C" s32 func_001D1720(struct Struct_001D1720 *self) {
    return func_0054C7B0(self->unk4) == 2;
}
