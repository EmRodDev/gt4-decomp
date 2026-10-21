/* Setter for id 27 of the 00440B50 dispatcher (which switches on the high 32 bits of a 64-bit parameter; three 0x178-byte slots from +8,
 * current slot index at +0x490): stores the 64-bit key, which arrives in a pointer-typed argument, at +0xF8 of the current slot, lets
 * 00440170 fill the slot, then copies the byte at row+0x13F to +0x167 of the slot. What id 27 stands for is purpose unknown. */
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

extern "C" void func_00440170(void *, s32);

struct func_004408D8_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_004408D8_v_s0 {
    char pad0[0xF8];
    s64 unkF8;
    char pad100[0x67];
    s8 unk167;
};
struct func_004408D8_arg2 {
    char pad0[0x13F];
    u8 unk13F;
};

extern "C" void func_004408D8(s32 *state, void *key, s32 row) {
    char *slot;
    slot = (char *)state + (((((((struct func_004408D8_arg0 *)state)->unk490 << 1) + ((struct func_004408D8_arg0 *)state)->unk490) << 4) - ((struct func_004408D8_arg0 *)state)->unk490) << 3);
    slot = (char *)slot + 0x8;
    ((struct func_004408D8_v_s0 *)slot)->unkF8 = (s64)key;
    func_00440170(state, row);
    ((struct func_004408D8_v_s0 *)slot)->unk167 = (s8)*(u8 *)((char *)row + 0x13f);
}
