/* Thin wrapper: passes the 32-bit field at +8 to func_0046BC00 and returns its result (sibling of func_0046BC98, which does the
 * same with func_0046BC40). Purpose unknown. */
#include "types.h"
struct Obj {
    char pad0[8];
    s32 unk8;
};
extern "C" s32 func_0046BC00(s32 value);
extern "C" s32 func_0046BC80(Obj *self)
{
    return func_0046BC00(self->unk8);
}
