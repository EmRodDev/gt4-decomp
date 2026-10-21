/* Calls func_00435E08 on the address 0x11C8 bytes into the object that the pointer at +0x10 refers to. */
#include "types.h"

struct Obj;

struct S005CBC98 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_00435E08(Obj *arg0);

extern "C" void func_005CBC98(struct S005CBC98 *self) {
    func_00435E08((Obj *)(self->unk10 + 0x11C8));
}
