/* When the field at +0x20 is nonzero, clears it and the four following words (+0x24 to +0x30): resets a small record that is active only while its first word is set (inferred from the guard). */
#include "types.h"

struct Obj {
    char pad[0x20];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
};

extern "C" void func_002D1FF8(Obj *obj) {
    if (obj->unk20 != 0) {
        obj->unk20 = 0;
        obj->unk24 = 0;
        obj->unk28 = 0;
        obj->unk2C = 0;
        obj->unk30 = 0;
    }
}
