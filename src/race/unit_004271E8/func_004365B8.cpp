/* Applies a loaded configuration block to global state: sets two doubled sizes (fields at +0x18/+0x1C, doubled) through 004A0BE0, stores
 * the result of 004390D0 on the sub-block at +0x24 in D_006184F0, passes field +0xC to 00472528 together with the PDISTD UNIT_MANAGER
 * global, writes the three bytes at +0x10..+0x12 into the first three words of that global, then runs 00439888 on the block at +0x1650 and
 * 00460AF8 on the field at +0x10B0. What the block configures is purpose unknown (the callee names are not recovered). */
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

extern s32 D_006184F0;
extern char PDISTD__UNIT_MANAGER[];
extern "C" void func_004A0BE0(s32, s32);
extern "C" s32 func_004390D0(void *);
extern "C" void func_00472528(void *, s32);
extern "C" void func_00439888(void *);
extern "C" void func_00460AF8(s32);

struct func_004365B8_arg0 {
    char pad0[0xC];
    s32 unkC;
    char pad10[0x8];
    s32 unk18;
    s32 unk1C;
    char pad20[0x1090];
    s32 unk10B0;
};
struct func_004365B8_v_s1 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

extern "C" void func_004365B8(s32 *config) {
    char *unitManager;
    s32 handle;
    unitManager = (char *)&PDISTD__UNIT_MANAGER;
    func_004A0BE0((((struct func_004365B8_arg0 *)config)->unk18 << 1), (((struct func_004365B8_arg0 *)config)->unk1C << 1));
    handle = func_004390D0((char *)config + 0x24);
    D_006184F0 = handle;
    func_00472528(unitManager, ((struct func_004365B8_arg0 *)config)->unkC);
    *(s32 *)(char *)unitManager = (s32)*(u8 *)((char *)config + 0x10);
    ((struct func_004365B8_v_s1 *)unitManager)->unk4 = (s32)*(u8 *)((char *)config + 0x11);
    ((struct func_004365B8_v_s1 *)unitManager)->unk8 = (s32)*(u8 *)((char *)config + 0x12);
    func_00439888((char *)config + 0x1650);
    func_00460AF8(((struct func_004365B8_arg0 *)config)->unk10B0);
}
