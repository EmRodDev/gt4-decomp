/* Sets three fields of a small state object: +0x18 and +0x24 get the two arguments and +0x14 is cleared. func_004745E8 calls it
 * with (a3, a4, 0xFF) right after func_00473620, so the 0xFF value looks like a maximum alpha/intensity (inferred; purpose unknown). */
#include "types.h"

struct Obj {
    char pad[0x14];
    s32 unk14;
    s32 unk18;
    char pad3[0x8];
    s32 unk24;
};

extern "C" void func_00473608(Obj *self, s32 value18, s32 value24) {
    self->unk18 = value18;
    self->unk24 = value24;
    self->unk14 = 0;
}
