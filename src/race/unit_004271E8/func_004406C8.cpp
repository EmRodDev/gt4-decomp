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

extern "C" void func_00440030(void *, s32);
extern "C" s32 func_004452A8(void *, u8, u8, u8);

struct func_004406C8_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_004406C8_v_s1 {
    char pad0[0x58];
    s64 unk58;
    char pad60[0xF0];
    s8 unk150;
    s8 unk151;
    s8 unk152;
    s8 unk153;
    s8 unk154;
    s8 unk155;
};
struct func_004406C8_arg2 {
    char pad0[0xF8];
    u8 unkF8;
    u8 unkF9;
    u8 unkFA;
    char padFB[0x1];
    u8 unkFC;
    u8 unkFD;
    u8 unkFE;
    char padFF[0x1];
    u8 unk100;
    u8 unk101;
    u8 unk102;
    char pad103[0x1];
    u8 unk104;
    u8 unk105;
    u8 unk106;
    char pad107[0x1];
    u8 unk108;
    u8 unk109;
    u8 unk10A;
    char pad10B[0x1];
    u8 unk10C;
    u8 unk10D;
    u8 unk10E;
};

extern "C" void func_004406C8(s32 *table, void *owner, s32 source) {
    char *slot;
    s32 packed0;
    s32 packed1;
    s32 packed2;
    s32 packed3;
    s32 packed4;
    s32 packed5;
    slot = (char *)table + (((((((struct func_004406C8_arg0 *)table)->unk490 << 1) + ((struct func_004406C8_arg0 *)table)->unk490) << 4) - ((struct func_004406C8_arg0 *)table)->unk490) << 3);
    slot = (char *)slot + 0x8;
    ((struct func_004406C8_v_s1 *)slot)->unk58 = (s64)owner;
    func_00440030(table, source);
    packed0 = func_004452A8(slot, ((struct func_004406C8_arg2 *)source)->unkF8, ((struct func_004406C8_arg2 *)source)->unkFA, ((struct func_004406C8_arg2 *)source)->unkF9);
    ((struct func_004406C8_v_s1 *)slot)->unk150 = (s8)packed0;
    packed1 = func_004452A8(slot, ((struct func_004406C8_arg2 *)source)->unk104, ((struct func_004406C8_arg2 *)source)->unk106, ((struct func_004406C8_arg2 *)source)->unk105);
    ((struct func_004406C8_v_s1 *)slot)->unk151 = (s8)packed1;
    packed2 = func_004452A8(slot, ((struct func_004406C8_arg2 *)source)->unkFC, ((struct func_004406C8_arg2 *)source)->unkFE, ((struct func_004406C8_arg2 *)source)->unkFD);
    ((struct func_004406C8_v_s1 *)slot)->unk152 = (s8)packed2;
    packed3 = func_004452A8(slot, ((struct func_004406C8_arg2 *)source)->unk108, ((struct func_004406C8_arg2 *)source)->unk10A, ((struct func_004406C8_arg2 *)source)->unk109);
    ((struct func_004406C8_v_s1 *)slot)->unk153 = (s8)packed3;
    packed4 = func_004452A8(slot, ((struct func_004406C8_arg2 *)source)->unk100, ((struct func_004406C8_arg2 *)source)->unk102, ((struct func_004406C8_arg2 *)source)->unk101);
    ((struct func_004406C8_v_s1 *)slot)->unk154 = (s8)packed4;
    packed5 = func_004452A8(slot, ((struct func_004406C8_arg2 *)source)->unk10C, ((struct func_004406C8_arg2 *)source)->unk10E, ((struct func_004406C8_arg2 *)source)->unk10D);
    ((struct func_004406C8_v_s1 *)slot)->unk155 = (s8)packed5;
}
