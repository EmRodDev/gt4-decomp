/* Sums the usable bytes of 16 block chains (heads at +0xC, 4 bytes apart) while holding the lock at +0x4C
 * (func_005769F0 / func_00576A28, inferred lock / unlock). Each block spans from its address to the pointer at +4, minus a 0x10-byte
 * header; the next block is at +0xC. Shape suggests an allocator's free-space total (inferred). */
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

struct E00572B08 {
    s32 p0;
    s32 q4;
    char pad8[0x4];
    s32 pC;
};

extern "C" void func_005769F0(s32 arg0);
extern "C" void func_00576A28(s32 arg0);

extern "C" s32 func_00572B08(s32 self) {
    s32 lock;
    s32 blockSpan;
    s32 chainsLeft;
    s32 totalBytes;
    s32 chainHead;
    s32 block;

    lock = self + 0x4C;
    func_005769F0(lock);
    totalBytes = 0;
    chainHead = self + 0xC;
    chainsLeft = 0xF;
    do {
        block = *(s32 *)(s32 *)(chainHead);
        if (block != 0) {
            do {
                blockSpan = *(s32 *)((char *)block + 0x4) - block;
                block = *(s32 *)((char *)block + 0xC);
                totalBytes = (totalBytes + blockSpan) - 0x10;
            } while (block != 0);
        }
        chainsLeft -= 1;
        chainHead += 4;
    } while (chainsLeft >= 0);
    func_00576A28(lock);
    return totalBytes;
}
