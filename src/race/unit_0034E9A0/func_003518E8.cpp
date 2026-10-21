/* For every slot (stride 0xEC from +0x164, count from the table func_00359510 returns) turns the product unk54 * unk4C (negated when
 * byte +0x45 is negative) into two value pairs: the signed product goes to the first or second output depending on the sign of byte
 * +0x44, the other output is 0, and the outputs written at +0x7C/+0x80 hold the values scaled by unk3C. The pair at +0x70/+0x74 gets the same
 * scaled values when the global bytes D_00620CD8+0xB6 / +0xB7 equal 2 and the unscaled ones otherwise. The purpose of these slot fields is
 * unknown, so they keep their unkNN names. */
#include "types.h"

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

struct TempV0 {
    char pad0[0x1];
    u8 unk1;
};

struct Glob {
    char pad0[0xB6];
    u8 unkB6;
    u8 unkB7;
};

struct Elem {
    char pad0[0x3C];
    f32 unk3C;
    char pad40[0x4];
    s8 unk44;
    s8 unk45;
    char pad46[0x6];
    f32 unk4C;
    char pad50[0x4];
    f32 unk54;
    char pad58[0x18];
    f32 unk70;
    f32 unk74;
    char pad78[0x4];
    f32 unk7C;
    f32 unk80;
};

extern char D_00620CD8[];
extern "C" void *func_00359510(s32 arg0);

extern "C" void func_003518E8(void *carBlock) {
    struct Obj *self;
    struct TempV0 *slotTable;
    struct Glob *globalFlags;
    struct Elem *slot;
    u32 i;
    f32 valueA, valueB, plainA, plainB;

    self = (struct Obj *)carBlock;
    slotTable = (struct TempV0 *)func_00359510(self->unk10);
    i = 0;
    if (slotTable->unk1 != 0) {
        slot = (struct Elem *)((char *)self + 0x164);
        globalFlags = (struct Glob *)D_00620CD8;
        do {
            valueB = slot->unk54 * slot->unk4C;
            if (slot->unk45 < 0) {
                valueB = -valueB;
            }
            valueA = slot->unk3C * valueB;
            if (slot->unk44 > 0) {
                plainB = 0.0f;
                plainA = valueB;
                valueB = plainB;
            } else {
                plainA = 0.0f;
                plainB = valueB;
                valueB = valueA;
                valueA = plainA;
            }
            slot->unk7C = valueA;
            slot->unk80 = valueB;
            if (globalFlags->unkB6 == 2) {
                slot->unk74 = valueB;
            } else {
                slot->unk74 = plainB;
            }
            if (globalFlags->unkB7 == 2) {
                slot->unk70 = valueA;
            } else {
                slot->unk70 = plainA;
            }
            i += 1;
            slot = (struct Elem *)((char *)slot + 0xEC);
        } while (i < slotTable->unk1);
    }
}
