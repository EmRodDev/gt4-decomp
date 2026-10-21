/* Calls func_005A609C on the address 0x138C bytes into the object that the pointer at +0x10 refers to. */
#include "types.h"

struct S005CD068 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void func_005A609C(s32 arg0);

extern "C" void func_005CD068(struct S005CD068 *self) {
    func_005A609C(self->unk10 + 0x138C);
}
