/* Script method incTotalRankCount: when the script passed a positive argument count, reads the integer argument (vtable slot 11, +0x58) and hands it
 * with the sub-record at +0x348 of the object behind the handle to func_0043AFF0, which presumably adds it to a rank counter (inferred from the name only). */
#include "types.h"

struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

struct Arg3 {
    ObjA *value;
};

struct Out {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void func_0015F388(void *arg0, int selfRef);
extern "C" void func_0015F3E0(void *arg0, void *selfRef);
extern "C" void func_0043AFF0(char *arg0, u32 selfRef);

extern "C" void MGame__incTotalRankCount(s32 arg0, void *selfRef, s32 argc, Arg3 *args) {
    s32 handle[4];
    ObjA *value;
    VEntry *slot;
    s32 result;
    Out *game;

    if (argc > 0) {
        value = args->value;
        slot = value->vtbl + 11;
        result = slot->fn((char *)value + slot->delta);
        func_0015F3E0(handle, selfRef);
        game = (Out *)handle[0];
        func_0043AFF0((char *)(game->unk10 + 0x348), result);
        func_0015F388(handle, 2);
    }
}
