/* Returns the 16-bit field at +0x2C multiplied by 100. */
#include "types.h"

struct Obj00603668 {
    char pad0[0x2C];
    s16 unk2C;
};

extern "C" s32 func_00603668(struct Obj00603668 *self) {
    return self->unk2C * 0x64;
}
