/* Expat 1.95.7 poolInit (identified by address with tools/libmatch.py scan expat): clears a string pool (blocks +0, freeBlocks +4, end +8, ptr +0xC, start +0x10) and stores the memory-handling suite at +0x14. */
#include "types.h"

struct Obj {
    s32 blocks;
    s32 freeBlocks;
    s32 end;
    s32 ptr;
    s32 start;
    s32 mem;
};

extern "C" void func_004D6658(Obj *pool, s32 memorySuite) {
    pool->mem = memorySuite;
    pool->freeBlocks = 0;
    pool->start = 0;
    pool->ptr = 0;
    pool->end = 0;
    pool->blocks = 0;
}
