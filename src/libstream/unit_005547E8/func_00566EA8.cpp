/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Looks key up through func_005657E0 on the object's table (+0x60); on success copies key's
   8-byte record (array from +0x6C) to *out. Returns the lookup's status. The result is its own
   variable, set to 0 before the copy (as in func_00553460). */
#include "types.h"

struct func_00566EA8_rec {
    s32 unk0;
    s32 unk4;
};

struct func_00566EA8_a0 {
    char pad0[0x60];
    s32 table;
    char pad64[0x8];
    struct func_00566EA8_rec recs[1];
};

extern "C" s32 func_005657E0(s32 table, s32 key, s32 *slot);

extern "C" s32 func_00566EA8(struct func_00566EA8_a0 *obj, s32 key, struct func_00566EA8_rec *out) {
    s32 slot;
    struct func_00566EA8_rec *recs = obj->recs;
    s32 err = func_005657E0(obj->table, key, &slot);
    s32 ret;
    if (err != 0) {
        ret = err;
    } else {
        ret = 0;
        *out = recs[slot];
    }
    return ret;
}
