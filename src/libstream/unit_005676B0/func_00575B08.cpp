/* Deleting destructor shape: stores the class's vtable pointer (D_00689D90) at +0x18, calls no base-class destructor, and frees the
 * object with func_005C1628 only when bit 0 of the flags argument is set (inferred from the generic ee-gcc 2.96 destructor pattern). */
#include "types.h"

struct Obj {
    char pad[0x18];
    void *unk18;
};

extern "C" char D_00689D90;
extern "C" void func_00575B68(Obj *arg0, s32 arg1);
extern "C" void func_005C1628(Obj *arg0);

extern "C" void func_00575B08(Obj *self, s32 deleteFlag) {
    self->unk18 = &D_00689D90;
    func_00575B68(self, deleteFlag);
    if (deleteFlag & 1) {
        return func_005C1628(self);
    }
}
