/* Setter for category 2 of the 00440B50 dispatcher (that file declares the state as three 0x178-byte slots from +8 plus the current slot
 * index at +0x490). Stores a 64-bit key, which arrives in a pointer-typed argument, at +0x28 of the current slot, lets 0043FE58 fill the slot
 * from the SPEC_DATABASE row table, then derives two signed bytes at +0x12F/+0x130 with 004452A8 from bytes 3/6 and 7/0xA of row.
 * The slot address is computed as index * 47 * 8, a multiply the compiler spells out in shifts. What category 2 stands for is purpose unknown. */
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

extern "C" void func_0043FE58(void *, s32);
extern "C" s32 func_004452A8(void *, s32, u8, u8);

struct func_00440268_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_00440268_v_s0 {
    char pad0[0x28];
    s64 unk28;
    char pad30[0xFF];
    s8 unk12F;
    s8 unk130;
};
struct func_00440268_arg2 {
    char pad0[0x3];
    u8 unk3;
    char pad4[0x2];
    u8 unk6;
    u8 unk7;
    char pad8[0x2];
    u8 unkA;
};

extern "C" void func_00440268(s32 *state, void *key, s32 row) {
    char *slot;
    s32 resultA;
    s32 resultB;
    slot = (char *)state + (((((((struct func_00440268_arg0 *)state)->unk490 << 1) + ((struct func_00440268_arg0 *)state)->unk490) << 4) - ((struct func_00440268_arg0 *)state)->unk490) << 3);
    slot = (char *)slot + 0x8;
    ((struct func_00440268_v_s0 *)slot)->unk28 = (s64)key;
    func_0043FE58(state, row);
    resultA = func_004452A8(slot, 0x1, ((struct func_00440268_arg2 *)row)->unk6, ((struct func_00440268_arg2 *)row)->unk3);
    ((struct func_00440268_v_s0 *)slot)->unk12F = (s8)resultA;
    resultB = func_004452A8(slot, 0x1, ((struct func_00440268_arg2 *)row)->unkA, ((struct func_00440268_arg2 *)row)->unk7);
    ((struct func_00440268_v_s0 *)slot)->unk130 = (s8)resultB;
}
