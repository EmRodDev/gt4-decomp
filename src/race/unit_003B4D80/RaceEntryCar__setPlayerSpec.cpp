/* Copies the player specification from spec into a race entry car (name from the symbol table, source gthd). First
 * func_004452F8 is called on the sub-object at entry+0x20 (purpose unknown) and that sub-object field +0x178
 * (entry+0x198) is set to the entry field +0x14 plus 0x100. When the byte at spec+0x166 is non-zero, spec+0x178,
 * +0x17C and (spec+0x180 != 0, normalised to 0 or 1) go to entry+0x3448, +0x3450 and +0x3454. Independent of that
 * byte, spec+0x184 goes to entry+0x344C and spec+0x188 to entry+0x3458. What the individual fields mean is
 * unknown. */
#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_004452F8(void *);

struct func_003B4F18_arg1 {
    char pad0[0x166];
    s8 unk166;
    char pad167[0x11];
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
};

struct func_003B4F18_v_s0 {
    char pad0[0x178];
    s32 unk178;
};
struct func_003B4F18_arg0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x3430];
    s32 unk3448;
    s32 unk344C;
    s32 unk3450;
    s32 unk3454;
    s32 unk3458;
};

extern "C" void RaceEntryCar__setPlayerSpec(s32 *entry, struct func_003B4F18_arg1 *spec) {
    char *subObject;
    subObject = (char *)entry + 0x20;
    func_004452F8(subObject);
    ((struct func_003B4F18_v_s0 *)subObject)->unk178 = ((struct func_003B4F18_arg0 *)entry)->unk14 + 0x100;
    if (spec->unk166 != 0) {
        ((struct func_003B4F18_arg0 *)entry)->unk3448 = spec->unk178;
        ((struct func_003B4F18_arg0 *)entry)->unk3450 = spec->unk17C;
        ((struct func_003B4F18_arg0 *)entry)->unk3454 = spec->unk180 != 0;
    }
    ((struct func_003B4F18_arg0 *)entry)->unk344C = spec->unk184;
    ((struct func_003B4F18_arg0 *)entry)->unk3458 = spec->unk188;
}
