/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Offset-table lookup, sibling of func_00449D18 (same layout, inferred from the pointer arithmetic): the table has its entry count
 * at +4 and 32-bit offsets from +0x10, followed by the data area. Returns the address 2 bytes after data area + offsets[index]
 * (func_00449D18 returns the 16-bit value stored there), so those 16 bits look like a length prefix and this returns the
 * bytes behind it (inferred from the pair); 0 when index is out of range. */
typedef unsigned int u32;
typedef unsigned short u16;

struct Ent_00449CD8 {
    u32 unk0;
    u32 unk4;
};

struct Tab_00449CD8 {
    char pad0[4];
    u32 count;
};

struct Self_00449CD8 {
    struct Tab_00449CD8 *unk0;
};

extern "C" char * func_00449CD8(struct Self_00449CD8 *self, u32 index) {
    struct Tab_00449CD8 *table = self->unk0;
    if (index >= table->count) {
        return 0;
    }
    struct Ent_00449CD8 *offsets = (struct Ent_00449CD8 *)((char *)table + 0x10);
    char *dataArea = (char *)offsets + (table->count * 4);
    char *offsetSlot = (char *)offsets + (index * 4);
    return dataArea + *(u32 *)(char *)offsetSlot + 2;
}
