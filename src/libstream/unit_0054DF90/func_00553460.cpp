/* Looks up an entry index through func_005657E0 on the object at +0x60. On success (status 0) copies the 16-byte record at
 * that index of the array starting at +0x6C into *out; returns the lookup's status. */
#include "types.h"

struct Obj {
    char pad0[0x60];
    void *unk60;
    char pad64[0x6C - 0x64];
};

struct Rec16 {
    char b[16];
};

extern "C" s32 func_005657E0(void *o, s32 i, s32 *out);

extern "C" s32 func_00553460(Obj *self, Rec16 *out) {
    s32 index[4];
    Rec16 *items = (Rec16 *)((char *)self + 0x6C);
    s32 result;
    s32 status = func_005657E0(self->unk60, 0, index);
    if (status != 0) {
        result = status;
    } else {
        result = 0;
        *out = items[index[0]];
    }
    return result;
}
