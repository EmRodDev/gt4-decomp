/* Clears the field at +8 and sets the field at +4 to 0 if the field at +0 is positive, otherwise to -1 (a sign-based flag; meaning unknown). */
#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" void func_001C6D58(struct Obj *self) {
    s32 first = self->unk0;
    self->unk8 = 0;
    self->unk4 = (first > 0) ? 0 : -1;
}
