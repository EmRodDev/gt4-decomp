/* Calls virtual slot +0x2C0 on the global object D_00618840, then runs func_00387EF0 on it with its field +0xCC8 and 0, and, between the lock begin/end pair on D_00821D18 (func_00576100 / func_00576140, inferred from their pairing), sets arg0's fields +0xA4 = 0 and +0xA8 = 1. Meaning of the two flags unknown. */
#include "types.h"

struct VEntry {
    s16 delta;
    s16 pad;
    void (*fn)(void *);
};

struct Obj {
    char pad0[0x64];
    char *vt;
    char pad68[0x3C];
    s32 unkA4;
    s32 unkA8;
    char padAC[0xC1C];
    s32 unkCC8;
};

extern "C" void *D_00618840;
extern "C" char D_00821D18[];

extern "C" void func_00387EF0(Obj *arg0, s32 arg1, s32 arg2);
extern "C" void func_00576100(Obj *arg0);
extern "C" void func_00576140(Obj *arg0);

extern "C" void func_0012B888(Obj *target) {
    Obj **globalPtr = (Obj **)&D_00618840;
    Obj *globalObj = *globalPtr;
    VEntry *slot = (VEntry *)((char *)globalObj->vt + 0x2C0);
    slot->fn((char *)globalObj + slot->delta);

    Obj *globalObj2 = *globalPtr;
    func_00387EF0(globalObj2, globalObj2->unkCC8, 0);
    func_00576100((Obj *)&D_00821D18);
    target->unkA4 = 0;
    target->unkA8 = 1;
    func_00576140((Obj *)&D_00821D18);
}
