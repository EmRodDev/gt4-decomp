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

extern "C" void func_0043FEA0(void *, s32);
extern "C" s32 func_004452A8(void *, u16, u16, u16);

struct func_004402F0_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_004402F0_v_s0 {
    char pad0[0x48];
    s64 unk48;
    char pad50[0xC0];
    s16 unk110;
    s16 unk112;
    s16 unk114;
    s16 unk116;
    s16 unk118;
    s16 unk11A;
    s16 unk11C;
    s16 unk11E;
    char pad120[0x8];
    s16 unk128;
    s8 unk12A;
    char pad12B[0x1];
    s16 unk12C;
};
struct func_004402F0_arg2 {
    char pad0[0x24];
    u16 unk24;
    u16 unk26;
    u16 unk28;
    char pad2A[0x8];
    u8 unk32;
    u8 unk33;
    u8 unk34;
};

extern "C" void func_004402F0(s32 *table, void *owner, s32 source) {
    char *slot;
    s32 packed0;
    s32 packed1;
    slot = (char *)table + (((((((struct func_004402F0_arg0 *)table)->unk490 << 1) + ((struct func_004402F0_arg0 *)table)->unk490) << 4) - ((struct func_004402F0_arg0 *)table)->unk490) << 3);
    slot = (char *)slot + 0x8;
    ((struct func_004402F0_v_s0 *)slot)->unk48 = (s64)owner;
    func_0043FEA0(table, source);
    ((struct func_004402F0_v_s0 *)slot)->unk110 = (s16)*(u16 *)((char *)source + 0x22);
    ((struct func_004402F0_v_s0 *)slot)->unk112 = (s16)*(u16 *)((char *)source + 0xc);
    ((struct func_004402F0_v_s0 *)slot)->unk114 = (s16)*(u16 *)((char *)source + 0xe);
    ((struct func_004402F0_v_s0 *)slot)->unk116 = (s16)*(u16 *)((char *)source + 0x10);
    ((struct func_004402F0_v_s0 *)slot)->unk118 = (s16)*(u16 *)((char *)source + 0x12);
    ((struct func_004402F0_v_s0 *)slot)->unk11A = (s16)*(u16 *)((char *)source + 0x14);
    ((struct func_004402F0_v_s0 *)slot)->unk11C = (s16)*(u16 *)((char *)source + 0x16);
    ((struct func_004402F0_v_s0 *)slot)->unk11E = (s16)*(u16 *)((char *)source + 0x18);
    packed0 = func_004452A8(slot, ((struct func_004402F0_arg2 *)source)->unk24, ((struct func_004402F0_arg2 *)source)->unk28, ((struct func_004402F0_arg2 *)source)->unk26);
    ((struct func_004402F0_v_s0 *)slot)->unk128 = (s16)packed0;
    packed1 = func_004452A8(slot, ((struct func_004402F0_arg2 *)source)->unk32, ((struct func_004402F0_arg2 *)source)->unk34, ((struct func_004402F0_arg2 *)source)->unk33);
    ((struct func_004402F0_v_s0 *)slot)->unk12A = (s8)packed1;
    ((struct func_004402F0_v_s0 *)slot)->unk12C = (s16)*(u16 *)((char *)slot + 0x128);
}
