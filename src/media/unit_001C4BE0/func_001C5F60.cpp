/* Returns (float)(field at +0x2C + 2 * field at +0x30). Meaning of the fields is unknown. */
#include "types.h"

struct Obj001C5F60 {
    char pad0[0x2C];
    s32 unk2C;
    s32 unk30;
};

extern "C" f32 func_001C5F60(struct Obj001C5F60 *self) {
    return (f32)(self->unk2C + (self->unk30 * 2));
}
