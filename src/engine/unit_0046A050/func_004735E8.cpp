/* Resets a small state: the field at +0x14 is cleared and the one at +8 is set to 1 (sibling of func_004735F8, which clears both). */
#include "types.h"
struct Obj {
    char pad8[0x8];
    s32 unk8;
    char pad14[0x14 - 0xC];
    s32 unk14;
};
extern "C" void func_004735E8(Obj *self) {
    self->unk14 = 0;
    self->unk8 = 1;
}
