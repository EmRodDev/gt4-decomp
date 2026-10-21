/* Adds delta to the four pointer-like fields at +0x10, +0x14, +0x18 and +0x1C when they are nonzero (a rebase after the data moved or was
 * loaded at a new address; inferred from the add-if-nonzero pattern), then calls 003E6CE0 with the pointer at +0x14 and delta once for each of
 * the count (u16 at +8) entries. The loop passes the same pointer every time, as in the original. What the data is is purpose unknown. */
#include "types.h"

struct Obj {
    char pad0[8];
    u16 count;
    char pad1[6];
    s32 f10;
    s32 ptr14;
    s32 f18;
    s32 f1C;
};

extern "C" void func_003E6CE0(int *self, int delta);

extern "C" void func_003E6D00(Obj *self, s32 delta)
{
    s32 deltaCopy = delta;

    {
        s32 *h = (s32 *)((char *)self + 0x14);
        if (*h != 0) {
            *h = *h + deltaCopy;
        }
    }

    {
        s32 *h = (s32 *)((char *)self + 0x18);
        if (*h != 0) {
            *h = *h + deltaCopy;
        }
    }

    {
        s32 *h = (s32 *)((char *)self + 0x1C);
        if (*h != 0) {
            *h = *h + deltaCopy;
        }
    }

    {
        s32 *h = (s32 *)((char *)self + 0x10);
        if (*h != 0) {
            *h = *h + deltaCopy;
        }
    }

    s32 iteration = 0;

    if (self->count != 0) {
        do {
            iteration += 1;
            func_003E6CE0((int *)self->ptr14, deltaCopy);
        } while (iteration < (s32)self->count);
    }
}
