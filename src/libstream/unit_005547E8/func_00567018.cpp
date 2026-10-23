/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Looks key up through func_005657E0 on the object's table (+0x60) and, when the object is open
   (+0x14) and the lookup succeeds (returns 0), passes the found slot with the length clamped to
   0x80 bytes to func_00553EF8 (command 6). Returns the clamped length, or 0 on failure. Both
   failure tests are one condition; separate early returns or an enclosing if change the schedule. */
#include "types.h"

struct func_00567018_a0 {
    char pad0[0x14];
    s32 open;
    char pad18[0x44];
    s32 unk5C;
    s32 table;
};

extern "C" s32 func_005657E0(s32 table, s32 key, s32 *slot);
extern "C" void func_00553EF8(s32 a0, struct func_00567018_a0 *obj, s32 slot, s32 cmd, s32 a4, u32 len, s32 a6);

extern "C" u32 func_00567018(struct func_00567018_a0 *obj, s32 key, s32 a2, u32 len, s32 a4) {
    s32 slot;
    if (obj->open == 0 || func_005657E0(obj->table, key, &slot) != 0)
        return 0;
    if (len > 0x80)
        len = 0x80;
    func_00553EF8(obj->unk5C, obj, slot, 6, a2, len, a4);
    return len;
}
