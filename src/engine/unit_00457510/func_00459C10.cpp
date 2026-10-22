/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Writes a three-float vector (x, y, z, inferred from the three getters) for a table entry and returns the output
 * pointer. The 16-byte-stride table at table+0x18 gives, for entry index, a linked index at +0x1C; the three
 * getters func_00364C40, func_00364BB0 and func_00364C60 are called with the object id at table+4, that linked
 * index and two zero floats, producing the x, y and z components. The y component additionally has the float at
 * +0x18 of the linked entry added (a vertical offset, inferred from it being added to y only). The unused memcpy
 * and NULL declarations came with the file and are not referenced. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00364BB0(s32, s32, f32, f32);                /* extern */
f32 func_00364C40(s32, s32, f32, f32);          /* extern */
f32 func_00364C60(s32, s32, f32, f32);                /* extern */

struct func_00459C10_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_00459C10_arg1 {
    char pad0[0x4];
    s32 unk4;
};
struct func_00459C10_temp_a2 {
    char pad0[0x18];
    f32 unk18;
    s32 unk1C;
};

void *func_00459C10(struct func_00459C10_arg0 *outVec, struct func_00459C10_arg1 *table, s32 index) {
    f32 z;
    f32 y;
    f32 x;
    s32 linkedIndex;
    struct func_00459C10_temp_a2 *entry;

    entry = (struct func_00459C10_temp_a2 *)((index * 0x10) + (s32)table);
    linkedIndex = entry->unk1C;
    x = func_00364C40(table->unk4, linkedIndex, 0.0f, 0.0f);
    y = func_00364BB0(table->unk4, linkedIndex, 0.0f, 0.0f) + ((struct func_00459C10_temp_a2 *)((linkedIndex * 0x10) + (s32)table))->unk18;
    z = func_00364C60(table->unk4, linkedIndex, 0.0f, 0.0f);
    outVec->unk0 = x;
    outVec->unk4 = y;
    outVec->unk8 = z;
    return outVec;
}
