/* Expat 1.95.7 hashTableIterInit (identified by address with tools/libmatch.py scan expat): starts an iterator at the table's bucket array (+0) and sets the end to bucket array + size (+8) buckets of 4 bytes. */
#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" void func_004D65F0(Obj *iter, Obj *table) {
    s32 buckets = table->unk0;
    iter->unk0 = buckets;
    iter->unk4 = buckets + (table->unk8 * 4);
}
