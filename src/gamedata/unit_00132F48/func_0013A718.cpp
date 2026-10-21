/* Passes the field at +0x2A8 of the object to func_00145AB8 (an accessor on the object at +0x14 of a garage car) and returns its result. Purpose unknown. */
#include "types.h"

struct Obj {
    char pad[0x2A8];
    s32 unk2A8;
};

extern "C" s32 func_00145AB8(s32 self);

extern "C" s32 func_0013A718(Obj *self) {
    return func_00145AB8(self->unk2A8);
}
