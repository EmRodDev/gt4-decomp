/* Fills a destination record from a database-style row and a state block, almost entirely by single-byte copies at fixed offsets (the
 * two layouts are not in the same order, which is why the list is long and the field names stay generic). About 60 bytes of row and ten
 * bytes/halfwords of state (+0x139..+0x145, +0x13C/+0x13E halfwords) are copied directly; ten more destination bytes are computed by
 * 004452C0(state, byteB, byteC, groupByte, selector) from row byte triples at +0x48..+0x6C, where one row byte (groupByte) is shared by
 * two calls and the selector comes from state bytes +0x146, +0x147, +0x14A..+0x14D (the pairing suggests two related values per group,
 * inferred). The last copy is row +0x6E into destination +0xA8. It sits among the slot setters of unit 004271E8 (see 00440B50) but what
 * it assembles is purpose unknown. */
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

extern "C" s32 func_004452C0(void *, u8, u8, u8, u8);

struct func_00441EE0_arg1 {
    char pad0[0x58];
    s8 unk58;
    s8 unk59;
    s8 unk5A;
    s8 unk5B;
    s8 unk5C;
    s8 unk5D;
    s8 unk5E;
    s8 unk5F;
    s8 unk60;
    s8 unk61;
    s8 unk62;
    s8 unk63;
    char pad64[0x1];
    s8 unk65;
    s16 unk66;
    char pad68[0x8];
    s8 unk70;
    s8 unk71;
    s8 unk72;
    s8 unk73;
    s8 unk74;
    s8 unk75;
    s8 unk76;
    s8 unk77;
    s8 unk78;
    s8 unk79;
    s8 unk7A;
    s8 unk7B;
    char pad7C[0x1];
    s8 unk7D;
    s16 unk7E;
    char pad80[0x8];
    s8 unk88;
    s8 unk89;
    char pad8A[0x2];
    s8 unk8C;
    s8 unk8D;
    s8 unk8E;
    s8 unk8F;
    s8 unk90;
    s8 unk91;
    s8 unk92;
    s8 unk93;
    s8 unk94;
    s8 unk95;
    char pad96[0x4];
    s16 unk9A;
    s16 unk9C;
    char pad9E[0xA];
    s8 unkA8;
    char padA9[0x127];
    s8 unk1D0;
    s8 unk1D1;
    s8 unk1D2;
    s8 unk1D3;
    s8 unk1D4;
    s8 unk1D5;
    s8 unk1D6;
    s8 unk1D7;
    s8 unk1D8;
    s8 unk1D9;
    s8 unk1DA;
    s8 unk1DB;
    s8 unk1DC;
    s8 unk1DD;
    s8 unk1DE;
    s8 unk1DF;
};

struct func_00441EE0_arg2 {
    char pad0[0x48];
    u8 unk48;
    u8 unk49;
    u8 unk4A;
    char pad4B[0x1];
    u8 unk4C;
    u8 unk4D;
    char pad4E[0x1];
    u8 unk4F;
    u8 unk50;
    u8 unk51;
    char pad52[0x1];
    u8 unk53;
    u8 unk54;
    char pad55[0x1];
    u8 unk56;
    u8 unk57;
    u8 unk58;
    char pad59[0x1];
    u8 unk5A;
    u8 unk5B;
    char pad5C[0x1];
    u8 unk5D;
    u8 unk5E;
    u8 unk5F;
    char pad60[0x1];
    u8 unk61;
    u8 unk62;
    char pad63[0x3];
    u8 unk66;
    u8 unk67;
    u8 unk68;
    char pad69[0x1];
    u8 unk6A;
    u8 unk6B;
    u8 unk6C;
};
struct func_00441EE0_arg0 {
    char pad0[0x146];
    u8 unk146;
    u8 unk147;
    char pad148[0x2];
    u8 unk14A;
    u8 unk14B;
    u8 unk14C;
    u8 unk14D;
    u8 unk14E;
    u8 unk14F;
};

extern "C" void func_00441EE0(s32 *state, struct func_00441EE0_arg1 *destination, s32 row) {
    u8 groupByte;
    s32 lookup1;
    s32 lookup2;
    s32 lookup3;
    s32 lookup4;
    s32 lookup5;
    s32 lookup6;
    s32 lookup7;
    s32 lookup8;
    s32 lookup9;
    s32 lookup10;
    destination->unk92 = (s8)*(u8 *)((char *)row + 0x2d);
    destination->unk93 = (s8)*(u8 *)((char *)row + 0x2e);
    destination->unk94 = (s8)*(u8 *)((char *)row + 0x31);
    destination->unk95 = (s8)*(u8 *)((char *)row + 0x32);
    destination->unk5A = (s8)*(u8 *)((char *)row + 0x3c);
    destination->unk72 = (s8)*(u8 *)((char *)row + 0x3d);
    destination->unk1D0 = (s8)*(u8 *)((char *)row + 0x17);
    destination->unk1D1 = (s8)*(u8 *)((char *)row + 0x18);
    destination->unk1D2 = (s8)*(u8 *)((char *)row + 0x19);
    destination->unk1D3 = (s8)*(u8 *)((char *)row + 0x1a);
    destination->unk1D8 = (s8)*(u8 *)((char *)row + 0x1b);
    destination->unk1D9 = (s8)*(u8 *)((char *)row + 0x1c);
    destination->unk1DA = (s8)*(u8 *)((char *)row + 0x1d);
    destination->unk1DB = (s8)*(u8 *)((char *)row + 0x1e);
    destination->unk1D4 = (s8)*(u8 *)((char *)row + 0x1f);
    destination->unk1D5 = (s8)*(u8 *)((char *)row + 0x20);
    destination->unk1D6 = (s8)*(u8 *)((char *)row + 0x21);
    destination->unk1D7 = (s8)*(u8 *)((char *)row + 0x22);
    destination->unk1DC = (s8)*(u8 *)((char *)row + 0x23);
    destination->unk1DD = (s8)*(u8 *)((char *)row + 0x24);
    destination->unk1DE = (s8)*(u8 *)((char *)row + 0x25);
    destination->unk1DF = (s8)*(u8 *)((char *)row + 0x26);
    destination->unk90 = (s8)*(u8 *)((char *)row + 0x15);
    destination->unk91 = (s8)*(u8 *)((char *)row + 0x16);
    destination->unk5B = (s8)*(u8 *)((char *)row + 0x64);
    destination->unk73 = (s8)*(u8 *)((char *)row + 0x65);
    destination->unk5C = (s8)*(u8 *)((char *)row + 0x40);
    destination->unk5E = (s8)*(u8 *)((char *)row + 0x42);
    destination->unk60 = (s8)*(u8 *)((char *)row + 0x44);
    destination->unk62 = (s8)*(u8 *)((char *)row + 0x46);
    destination->unk74 = (s8)*(u8 *)((char *)row + 0x41);
    destination->unk76 = (s8)*(u8 *)((char *)row + 0x43);
    destination->unk78 = (s8)*(u8 *)((char *)row + 0x45);
    destination->unk7A = (s8)*(u8 *)((char *)row + 0x47);
    destination->unk66 = (s16)*(u8 *)((char *)row + 0x2f);
    destination->unk7E = (s16)*(u8 *)((char *)row + 0x30);
    destination->unk65 = (s8)*(u8 *)((char *)row + 0x3e);
    destination->unk7D = (s8)*(u8 *)((char *)row + 0x3f);
    destination->unk9A = (s16)*(u16 *)((char *)state + 0x13c);
    destination->unk9C = (s16)*(u16 *)((char *)state + 0x13e);
    destination->unk88 = (s8)*(u8 *)((char *)state + 0x139);
    destination->unk89 = (s8)*(u8 *)((char *)state + 0x13a);
    destination->unk8E = (s8)*(u8 *)((char *)state + 0x140);
    destination->unk8F = (s8)*(u8 *)((char *)state + 0x141);
    destination->unk58 = (s8)*(u8 *)((char *)state + 0x142);
    destination->unk70 = (s8)*(u8 *)((char *)state + 0x143);
    destination->unk8C = (s8)*(u8 *)((char *)state + 0x144);
    destination->unk8D = (s8)*(u8 *)((char *)state + 0x145);
    groupByte = ((struct func_00441EE0_arg2 *)row)->unk48;
    lookup1 = func_004452C0(state, ((struct func_00441EE0_arg2 *)row)->unk49, ((struct func_00441EE0_arg2 *)row)->unk4A, groupByte, ((struct func_00441EE0_arg0 *)state)->unk146);
    destination->unk5D = (s8)lookup1;
    lookup2 = func_004452C0(state, ((struct func_00441EE0_arg2 *)row)->unk4C, ((struct func_00441EE0_arg2 *)row)->unk4D, groupByte, ((struct func_00441EE0_arg0 *)state)->unk147);
    destination->unk5F = (s8)lookup2;
    groupByte = ((struct func_00441EE0_arg2 *)row)->unk4F;
    lookup3 = func_004452C0(state, ((struct func_00441EE0_arg2 *)row)->unk50, ((struct func_00441EE0_arg2 *)row)->unk51, groupByte, ((struct func_00441EE0_arg0 *)state)->unk146);
    destination->unk61 = (s8)lookup3;
    lookup4 = func_004452C0(state, ((struct func_00441EE0_arg2 *)row)->unk53, ((struct func_00441EE0_arg2 *)row)->unk54, groupByte, ((struct func_00441EE0_arg0 *)state)->unk147);
    destination->unk63 = (s8)lookup4;
    groupByte = ((struct func_00441EE0_arg2 *)row)->unk56;
    lookup5 = func_004452C0(state, ((struct func_00441EE0_arg2 *)row)->unk57, ((struct func_00441EE0_arg2 *)row)->unk58, groupByte, ((struct func_00441EE0_arg0 *)state)->unk14A);
    destination->unk75 = (s8)lookup5;
    lookup6 = func_004452C0(state, ((struct func_00441EE0_arg2 *)row)->unk5A, ((struct func_00441EE0_arg2 *)row)->unk5B, groupByte, ((struct func_00441EE0_arg0 *)state)->unk14B);
    destination->unk77 = (s8)lookup6;
    groupByte = ((struct func_00441EE0_arg2 *)row)->unk5D;
    lookup7 = func_004452C0(state, ((struct func_00441EE0_arg2 *)row)->unk5E, ((struct func_00441EE0_arg2 *)row)->unk5F, groupByte, ((struct func_00441EE0_arg0 *)state)->unk14C);
    destination->unk79 = (s8)lookup7;
    lookup8 = func_004452C0(state, ((struct func_00441EE0_arg2 *)row)->unk61, ((struct func_00441EE0_arg2 *)row)->unk62, groupByte, ((struct func_00441EE0_arg0 *)state)->unk14D);
    destination->unk7B = (s8)lookup8;
    lookup9 = func_004452C0(state, ((struct func_00441EE0_arg2 *)row)->unk67, ((struct func_00441EE0_arg2 *)row)->unk68, ((struct func_00441EE0_arg2 *)row)->unk66, ((struct func_00441EE0_arg0 *)state)->unk14E);
    destination->unk59 = (s8)lookup9;
    lookup10 = func_004452C0(state, ((struct func_00441EE0_arg2 *)row)->unk6B, ((struct func_00441EE0_arg2 *)row)->unk6C, ((struct func_00441EE0_arg2 *)row)->unk6A, ((struct func_00441EE0_arg0 *)state)->unk14F);
    destination->unk71 = (s8)lookup10;
    destination->unkA8 = (s8)*(u8 *)((char *)row + 0x6e);
}
