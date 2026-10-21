/* Writes up to two tagged chunks into the bit/byte writer embedded at +0x85C: 0xFFE8 then a length (0x2B), an 8-bit tag, a 0 and a 32-bit value (+0x8EC), and, when +0x8F0/+0x8F4 are set, 0xFFE9 followed by length+0xB, a tag and the +0x8F0 data of +0x8F4 bytes. 0xFFE8/0xFFE9 are the JPEG APP8/APP9 marker codes, so this looks like writing custom application segments into a JPEG stream (inferred from the marker values; unproven). */
#include "types.h"

struct Buf {
    char pad[1];
};

struct func_001C7560_arg0 {
    char pad0[0x85C];
    char pad1[0x90];
    s32 unk8EC;
    s32 unk8F0;
    s32 unk8F4;
};

extern s32 D_00618D08;
extern s32 D_00618D0C;

extern "C" void func_0046F300(Buf *b, int c);
extern "C" void func_0046F378(Buf *b, unsigned int c);
extern "C" void func_0046F400(Buf *b, s32 a, s32 c);

extern "C" void func_001C7560(struct func_001C7560_arg0 *encoder) {
    if (encoder->unk8EC != 0) {
        Buf *writer = (Buf *)((char *)encoder + 0x85C);
        func_0046F378(writer, (u32)0xFFE8);
        func_0046F378((Buf *)((char *)encoder + 0x85C), (u32)0x2B);
        func_0046F400((Buf *)((char *)encoder + 0x85C), D_00618D08, 8);
        func_0046F300((Buf *)((char *)encoder + 0x85C), 0);
        func_0046F400((Buf *)((char *)encoder + 0x85C), encoder->unk8EC, 0x20);
    }
    if (encoder->unk8F0 != 0 && encoder->unk8F4 > 0) {
        Buf *writer = (Buf *)((char *)encoder + 0x85C);
        func_0046F378(writer, (u32)0xFFE9);
        func_0046F378((Buf *)((char *)encoder + 0x85C), (u32)(encoder->unk8F4 + 0xB));
        func_0046F400((Buf *)((char *)encoder + 0x85C), D_00618D0C, 8);
        func_0046F300((Buf *)((char *)encoder + 0x85C), 0);
        func_0046F400((Buf *)((char *)encoder + 0x85C), encoder->unk8F0, encoder->unk8F4);
    }
}
