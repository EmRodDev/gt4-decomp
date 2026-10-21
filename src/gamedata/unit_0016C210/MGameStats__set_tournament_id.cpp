/* Script setter set_tournament_id: gets the MGameStats record of the running game (func_0016BF98 fills a 16-byte handle, released with mode 2 at the
 * end), reads the script argument through vtable slot 11 (+0x58, an integer getter, inferred from its return type) and stores it as a byte (s8) at record+0x31. */
#include "types.h"

struct VEntry_16C {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj_16C {
    char pad0[4];
    VEntry_16C *vtbl;
};

extern "C" void func_0016BF40(void *arg0, s32 arg1);
extern "C" void func_0016BF98(void *arg0);

extern "C" void MGameStats__set_tournament_id(void *, void *, s32, void **args) {
    s32 handle[4];
    s32 stats;
    Obj_16C *value;
    VEntry_16C *entry;
    s8 number;

    func_0016BF98((void *)handle);
    stats = handle[0];
    value = (Obj_16C *)*args;
    entry = &value->vtbl[11];
    number = (s8)entry->fn((char *)value + entry->delta);
    *(s8 *)((char *)stats + 0x31) = number;
    func_0016BF40((void *)handle, 2);
}
