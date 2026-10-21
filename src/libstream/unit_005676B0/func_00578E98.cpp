/* Deleting destructor shape: stores the class's vtable pointer (D_00689E98) at +0x18, runs the base-class destructor func_0057B310, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
#include "types.h"

struct Obj {
    char pad0[0x18];
    void *unk18;
    char unk1C[1];
};

extern void *D_00689E98;
extern "C" void func_00574DA8(void *, s32);
extern "C" void func_0057B310(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void func_00578E98(struct Obj *self, s32 deleteFlag)
{
    self->unk18 = &D_00689E98;
    func_00574DA8(&self->unk1C, 2);
    func_0057B310(self, 0);
    if (deleteFlag & 1) {
        return func_005C1628(self);
    }
}
