/* Offset-table lookup (layout inferred from the pointer arithmetic): the object points to a table with its entry count at +4;
 * from +0x10 come count 32-bit offsets, followed by the data area they point into. Returns the 16-bit value found at
 * data area + offsets[index], or 0 when index is out of range. */
#include "types.h"

struct Ent_00449D18 {
    u32 unk0;
    u32 unk4;
};

struct Tab_00449D18 {
    char pad0[4];
    u32 count;
};

struct Self_00449D18 {
    struct Tab_00449D18 *unk0;
};

extern "C" u16 func_00449D18(struct Self_00449D18 *self, u32 index) {
    struct Tab_00449D18 *table = self->unk0;
    if (index >= table->count) {
        return 0;
    }
    struct Ent_00449D18 *offsets = (struct Ent_00449D18 *)((char *)table + 0x10);
    char *dataArea = (char *)offsets + (table->count * 4);
    char *offsetSlot = (char *)offsets + (index * 4);
    return *(u16 *)(dataArea + *(u32 *)(char *)offsetSlot);
}
