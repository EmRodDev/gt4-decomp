/* Getter with error code: writes 0 to the output first, returns 0xD2F2 when the object is missing (the library's 'invalid argument' code, inferred from this being the
 * only failure value), otherwise copies the field at +0x60 out and returns 0. */
#include "types.h"

struct Obj {
    char pad[0x60];
    s32 unk60;
};

extern "C" s32 func_00529028(struct Obj *self, s32 *out) {
    *out = 0;
    if (self == 0) {
        return 0xD2F2;
    }
    *out = self->unk60;
    return 0;
}
