/* Sets up a timing record: +0x70 = value, +0x74 = 0, +0x78 / +0x7C / +0x84 / +0x88 = 15, and +0x80 = duration * 30
 * (the factor 30 suggests a frame count at 30 per second, inferred). Field purposes unknown. */
#include "types.h"

struct Obj00109048 {
    char pad[0x70];
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
};

extern "C" void func_00109048(struct Obj00109048 *self, s32 value, f32 duration) {
    self->unk70 = value;
    self->unk74 = 0;
    self->unk7C = 0xF;
    self->unk78 = 0xF;
    self->unk88 = 0xF;
    self->unk84 = 0xF;
    self->unk80 = (s32)(duration * 30.0f);
}
