/* Relocation fix-up (inferred): adds delta to the stored pointer at +0 and to the table pointer 'base' when they are not null, then
 * asks func_00485CA8 to fix up each of the 'count' 8-byte table entries by the same delta. */
#include "types.h"

struct Obj {
    s32 unk0;
    s32 count;
    s32 base;
};

extern "C" void func_00485CA8(int *p, int base);

extern "C" void func_00485CD8(Obj *self, s32 delta)
{
    if (self->unk0 != 0) {
        self->unk0 = self->unk0 + delta;
    }

    s32 *basePtr = &self->base;

    if (*basePtr != 0) {
        *basePtr = *basePtr + delta;
    }

    s32 index = 0;

    if (self->count > 0) {
        do {
            s32 byteOffset = index << 3;
            index += 1;
            func_00485CA8((int *)(self->base + byteOffset), delta);
        } while (index < self->count);
    }
}
