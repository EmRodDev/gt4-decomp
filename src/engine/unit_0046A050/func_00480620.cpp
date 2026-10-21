/* Thin wrapper: passes the 32-bit field at +0x60 to func_00474A40 and returns its result (purpose unknown). */
#include "types.h"
struct Obj {
    char pad0[0x60];
    s32 unk60;
};
extern "C" s32 func_00474A40(s32 value);
extern "C" s32 func_00480620(Obj *self)
{
    return func_00474A40(self->unk60);
}
