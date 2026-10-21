/* Resolves the object at +0x14 with func_00441248 and passes the result to func_00445808, which takes no other argument. Purpose unknown; part of the
 * family of one-line forwarders (func_00145AB8, func_00145E00) that all start from the same +0x14 lookup. */
#include "types.h"

struct Obj {
    char pad0[0x14];
    void *unk14;
};

extern "C" s32 func_00441248(void *self);
extern "C" s32 func_00445808(s32 self);

extern "C" void func_00145C08(Obj *self) {
    func_00445808(func_00441248(self->unk14));
}
