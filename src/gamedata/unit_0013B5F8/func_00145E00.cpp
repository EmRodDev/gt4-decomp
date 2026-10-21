/* Resolves the object at +0x14 with func_00441248 and calls func_00445A50 with it and the second argument; returns the result. Purpose unknown. */
#include "types.h"

struct Obj {
    char pad[0x14];
    s32 unk14;
};

extern "C" s32 func_00441248(s32 self);
extern "C" s32 func_00445A50(s32 self, s32 value);

extern "C" s32 func_00145E00(Obj *self, s32 value) {
    s32 savedValue = value;
    s32 resolved = func_00441248(self->unk14);
    return func_00445A50(resolved, savedValue);
}
