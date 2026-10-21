/* Releases the resource block attached to arg1 (field +0xC): after func_004ADDC0, if the block exists and the owner's state (the object at +4, field +0x74) equals 1 and the block has a pending count, func_00550E60 is called with the remaining 0x40 - count; then func_00550E90 closes it and the block and its sub-allocation (+0xC) are returned to the two pools D_0084D5C0 / D_0084D5E0 (func_00575C30). Always returns 0. Which subsystem owns it is not determined. */
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

extern char D_0084D5C0[];
extern char D_0084D5E0[];
extern "C" void func_004ADDC0(void);
extern "C" void func_00550E60(s32, s32, s32);
extern "C" void func_00550E90(s32);
extern "C" void func_00575C30(void *, s32);

struct func_004B0D90_arg1 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
};

struct func_004B0D90_v_s0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

extern "C" s32 func_004B0D90(s32 *owner, struct func_004B0D90_arg1 *connection) {
    s32 block;
    func_004ADDC0();
    block = connection->unkC;
    if (block != 0) {
        if (*(s32 *)((char *)(connection->unk4) + 0x74) == 0x1) {
            if (((struct func_004B0D90_v_s0 *)block)->unk8 != 0) {
                func_00550E60(*(s32 *)(char *)block, ((struct func_004B0D90_v_s0 *)block)->unkC, (0x40 - ((struct func_004B0D90_v_s0 *)block)->unk8));
            }
        }
        func_00550E90(*(s32 *)(char *)block);
        func_00575C30(&D_0084D5E0, ((struct func_004B0D90_v_s0 *)block)->unkC);
        func_00575C30(&D_0084D5C0, block);
        connection->unkC = 0;
    }
    return 0;
}
