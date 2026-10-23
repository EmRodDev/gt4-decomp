/* compiler: ee-gcc2.96-no-strict-aliasing */
/* When the object is open (+0x14) and func_005657E0 finds key, moves key's entry (8-byte entries
   from +0x6C) from state 1 to state 2 and passes the matching handle (+0x8 + slot * 4) to
   func_005547F8; returns 1 then, else 0. */
#include "types.h"

struct func_00566F10_entry {
    s32 state;
    s32 unk4;
};

struct func_00566F10_a0 {
    char pad0[0x8];
    s32 handles[3];
    s32 open;
    char pad18[0x48];
    s32 table;
    char pad64[0x8];
    struct func_00566F10_entry entries[1];
};

extern "C" s32 func_005657E0(s32 table, s32 key, s32 *slot);
extern "C" void func_005547F8(s32 handle);

extern "C" s32 func_00566F10(struct func_00566F10_a0 *obj, s32 key) {
    s32 slot;
    if (obj->open == 0 || func_005657E0(obj->table, key, &slot) != 0)
        return 0;
    if (obj->entries[slot].state != 1)
        return 0;
    obj->entries[slot].state = 2;
    func_005547F8(obj->handles[slot]);
    return 1;
}
