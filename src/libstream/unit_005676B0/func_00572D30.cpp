/* Initializer: clears the 64-bit word at +0, sets +8 to -0x20 and clears +0xC and +0x10. Purpose of the fields unknown. */
#include "types.h"

struct __attribute__((aligned(8))) Obj {
    s64 unk0;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern "C" void func_00572D30(Obj *self) {
    self->unk0 = 0;
    self->unk8 = -0x20;
    self->unkC = 0;
    self->unk10 = 0;
}
