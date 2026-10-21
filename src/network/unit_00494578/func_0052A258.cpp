/* Setter with error code: returns 2 when the object is missing, otherwise stores the value at +0x70 and returns 0. Same pattern as func_00541150. */
#include "types.h"

struct Obj {
    char pad[0x70];
    s32 unk70;
};

extern "C" s32 func_0052A258(Obj *self, s32 value) {
    s32 status;

    status = 2;
    if (self != 0) {
        self->unk70 = value;
        status = 0;
    }
    return status;
}
