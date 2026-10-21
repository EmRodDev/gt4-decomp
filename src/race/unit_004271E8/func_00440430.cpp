/* Setter for category 14 of the 00440B50 dispatcher (three 0x178-byte slots from +8, current slot index at +0x490): stores a 64-bit
 * key, which arrives in a pointer-typed argument, at +0xB0 of the current slot, lets 0043FF90 fill the slot, then copies the six bytes
 * at +0x7A..+0x7F of row to +0x133..+0x138 of the slot. What category 14 stands for is purpose unknown. */
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

extern "C" void func_0043FF90(void *, s32);

struct func_00440430_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_00440430_v_s0 {
    char pad0[0xB0];
    s64 unkB0;
    char padB8[0x7B];
    s8 unk133;
    s8 unk134;
    s8 unk135;
    s8 unk136;
    s8 unk137;
    s8 unk138;
};

extern "C" void func_00440430(s32 *state, void *key, s32 row) {
    char *slot;
    slot = (char *)state + (((((((struct func_00440430_arg0 *)state)->unk490 << 1) + ((struct func_00440430_arg0 *)state)->unk490) << 4) - ((struct func_00440430_arg0 *)state)->unk490) << 3);
    slot = (char *)slot + 0x8;
    ((struct func_00440430_v_s0 *)slot)->unkB0 = (s64)key;
    func_0043FF90(state, row);
    ((struct func_00440430_v_s0 *)slot)->unk133 = (s8)*(u8 *)((char *)row + 0x7a);
    ((struct func_00440430_v_s0 *)slot)->unk134 = (s8)*(u8 *)((char *)row + 0x7b);
    ((struct func_00440430_v_s0 *)slot)->unk135 = (s8)*(u8 *)((char *)row + 0x7c);
    ((struct func_00440430_v_s0 *)slot)->unk136 = (s8)*(u8 *)((char *)row + 0x7d);
    ((struct func_00440430_v_s0 *)slot)->unk137 = (s8)*(u8 *)((char *)row + 0x7e);
    ((struct func_00440430_v_s0 *)slot)->unk138 = (s8)*(u8 *)((char *)row + 0x7f);
}
