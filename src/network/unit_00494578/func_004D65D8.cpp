/* Expat 1.95.7 hashTableInit (identified by address with tools/libmatch.py scan expat): empties the table (buckets +0, power +4, size +8, used +0xC) and stores the memory-handling suite pointer at +0x10. */
#include "types.h"

struct Obj {
    s32 buckets;
    u8 power;
    char pad5[3];
    s32 size;
    s32 used;
    s32 mem;
};

extern "C" void func_004D65D8(Obj *table, s32 memorySuite) {
    table->power = 0;
    table->size = 0;
    table->used = 0;
    table->buckets = 0;
    table->mem = memorySuite;
}
