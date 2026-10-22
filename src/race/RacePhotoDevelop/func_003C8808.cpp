/* Resets both entries of a two-entry table of 0x3C-byte records at D_0061850C (the byte index of the current
 * record is at +0x78, so the second entry is 1 - currentIndex; this reads as double buffering, inferred). Steps:
 * func_004A3078(0) and func_004A2980(-1) first, then for the current record func_001056A0 is called on it and
 * func_004A3230(1); the same for the other record; finally the word at +0x30 of both records is cleared. The
 * record address is index * 60, written in the source as ((x << 4) - x) << 2. The argument is unused.
 * func_00330CA8 is the same sequence in another unit. */
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

extern char D_0061850C[];
extern "C" void func_004A3078(s32);
extern "C" void func_004A2980(s32);
extern "C" void func_001056A0(void *);
extern "C" void func_004A3230(s32);

struct func_003C8808_v_s0 {
    char pad0[0x78];
    s32 currentIndex;
};

extern "C" void func_003C8808(s32 *unusedArg) {
    char *frames;
    s32 otherIndex;
    frames = (char *)&D_0061850C;
    func_004A3078(0);
    otherIndex = 0x1;
    func_004A2980(-0x1);
    func_001056A0((char *)frames + (((((struct func_003C8808_v_s0 *)frames)->currentIndex << 4) - ((struct func_003C8808_v_s0 *)frames)->currentIndex) << 2));
    func_004A3230(0x1);
    func_001056A0((char *)frames + ((((otherIndex - ((struct func_003C8808_v_s0 *)frames)->currentIndex) << 4) - (otherIndex - ((struct func_003C8808_v_s0 *)frames)->currentIndex)) << 2));
    func_004A3230(0x1);
    *(s32 *)((char *)frames + (((((struct func_003C8808_v_s0 *)frames)->currentIndex << 4) - ((struct func_003C8808_v_s0 *)frames)->currentIndex) << 2) + 0x30) = 0;
    otherIndex = (otherIndex - ((struct func_003C8808_v_s0 *)frames)->currentIndex);
    *(s32 *)((char *)frames + (((otherIndex << 4) - otherIndex) << 2) + 0x30) = 0;
}
