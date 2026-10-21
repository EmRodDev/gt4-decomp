/* Slot setter: stores the owner pointer into slot number table->unk490 of a table whose slots are 0x178 bytes apart (inferred from the shift/add
 * arithmetic), calls the shared slot initialiser, then converts byte triples of the source record through func_004452A8 into
 * packed values kept in the slot. What the packed values mean (colours or indices) is unknown. */
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

extern "C" void func_004400D0(void *, s32);
extern "C" s32 func_004452A8(void *, s32, u8, u8);

struct func_00440820_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_00440820_v_s0 {
    char pad0[0xE0];
    s64 unkE0;
    char padE8[0x6F];
    s8 unk157;
    s8 unk158;
    s8 unk159;
    s8 unk15A;
};
struct func_00440820_arg2 {
    char pad0[0x11E];
    u8 unk11E;
    char pad11F[0x2];
    u8 unk121;
    char pad122[0x2];
    u8 unk124;
    char pad125[0x2];
    u8 unk127;
    char pad128[0x1];
    u8 unk129;
    char pad12A[0x2];
    u8 unk12C;
    char pad12D[0x2];
    u8 unk12F;
    char pad130[0x2];
    u8 unk132;
};

extern "C" void func_00440820(s32 *table, void *owner, s32 source) {
    char *slot;
    s32 packed0;
    s32 packed1;
    s32 packed2;
    s32 packed3;
    slot = (char *)table + (((((((struct func_00440820_arg0 *)table)->unk490 << 1) + ((struct func_00440820_arg0 *)table)->unk490) << 4) - ((struct func_00440820_arg0 *)table)->unk490) << 3);
    slot = (char *)slot + 0x8;
    ((struct func_00440820_v_s0 *)slot)->unkE0 = (s64)owner;
    func_004400D0(table, source);
    packed0 = func_004452A8(slot, 0x1, ((struct func_00440820_arg2 *)source)->unk121, ((struct func_00440820_arg2 *)source)->unk11E);
    ((struct func_00440820_v_s0 *)slot)->unk157 = (s8)packed0;
    packed1 = func_004452A8(slot, 0x1, ((struct func_00440820_arg2 *)source)->unk127, ((struct func_00440820_arg2 *)source)->unk124);
    ((struct func_00440820_v_s0 *)slot)->unk158 = (s8)packed1;
    packed2 = func_004452A8(slot, 0x1, ((struct func_00440820_arg2 *)source)->unk12C, ((struct func_00440820_arg2 *)source)->unk129);
    ((struct func_00440820_v_s0 *)slot)->unk159 = (s8)packed2;
    packed3 = func_004452A8(slot, 0x1, ((struct func_00440820_arg2 *)source)->unk132, ((struct func_00440820_arg2 *)source)->unk12F);
    ((struct func_00440820_v_s0 *)slot)->unk15A = (s8)packed3;
}
