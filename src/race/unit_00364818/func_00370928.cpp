/* Thin wrapper: calls 00370548 with the object, its embedded block at +0x60 and the int at +0x80. Purpose unknown. */
#include "types.h"

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" void func_00370548(Obj *self, void *arg1, s32 arg2);

extern "C" void func_00370928(Obj *self) {
    func_00370548(self, (char *)self + 0x60, self->unk80);
}
