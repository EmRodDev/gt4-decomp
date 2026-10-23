/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Clears *out, then, when the object is open (+0x14), looks key up through func_005657E0 and
   stores func_00554DD8(handle of the found slot, a, b) to *out. Returns 3 for a closed object,
   the lookup's status when it fails, else 0. */
#include "types.h"

struct func_00565BA8_a0 {
    char pad0[0x8];
    s32 handles[3];
    s32 open;
    char pad18[0x48];
    s32 table;
};

extern "C" s32 func_005657E0(s32 table, s32 key, s32 *slot);
extern "C" s32 func_00554DD8(s32 handle, s32 a, s32 b);

extern "C" s32 func_00565BA8(struct func_00565BA8_a0 *obj, s32 key, s32 a, s32 b, s32 *out) {
    s32 slot;
    *out = 0;
    if (obj->open == 0)
        return 3;
    s32 err = func_005657E0(obj->table, key, &slot);
    if (err != 0)
        return err;
    *out = func_00554DD8(obj->handles[slot], a, b);
    return 0;
}
