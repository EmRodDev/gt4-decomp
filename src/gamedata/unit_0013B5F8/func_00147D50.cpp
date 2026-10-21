/* Calls func_004401C0 with the field at +0x14 of the object and the address of the member at +0x30 (purpose unknown). */
#include "types.h"

struct Obj {
    char pad0[0x14];
    s32 unk14;
};

extern "C" void func_004401C0(s32 self, void *arg1);

extern "C" void func_00147D50(Obj *self) {
    func_004401C0(self->unk14, (char *)self + 0x30);
}
