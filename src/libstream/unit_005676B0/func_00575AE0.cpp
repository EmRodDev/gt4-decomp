/* Constructor shape: stores three arguments at +0, +4 and +8, clears +0xC, +0x10 and +0x14, and stores the static table
 * D_00689D90 at +0x18. Purpose of the fields unknown. */
#include "types.h"

struct S_00575AE0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    void *unk18;
};

extern "C" char D_00689D90[];

extern "C" void func_00575AE0(struct S_00575AE0 *self, s32 first, s32 second, s32 third)
{
    self->unk0 = first;
    self->unk4 = second;
    self->unk18 = D_00689D90;
    self->unk8 = third;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
}
