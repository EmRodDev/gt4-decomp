/* Stores the argument in the field at +0x10 and zeroes the five words that follow (+0x14 to +0x24): re-initialises a small record around a new first value. */
#include "types.h"

struct Obj001FCA80 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

extern "C" void func_001FCA80(struct Obj001FCA80 *obj, s32 firstValue) {
    obj->unk10 = firstValue;
    obj->unk14 = 0;
    obj->unk18 = 0;
    obj->unk1C = 0;
    obj->unk20 = 0;
    obj->unk24 = 0;
}
