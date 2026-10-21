/* Marks a slot as used: for slot < 0x80 (the bound suggests a table of 0x80 bytes starting at +0x1C; inferred) it sets bits 0 and 2
 * of that slot's byte, stores the slot at +0, clears +4 and sets the field at +0x11C to 1. Larger slots are ignored.
 * Meaning of the bits unknown. */
#include "types.h"

struct Obj0047D080 {
    s32 unk0;
    s32 unk4;
    char pad8[0x14];
    u8 unk1C;
    char pad1D[0xFF];
    s32 unk11C;
};

extern "C" void func_0047D080(struct Obj0047D080 *self, u32 slot) {
    if (slot < 0x80U) {
        s32 address = (s32)slot + (s32)self;
        u8 *flags = (u8 *)(address + 0x1C);
        *flags = (u8)(*flags | 5);
        self->unk11C = 1;
        self->unk0 = (s32)slot;
        self->unk4 = 0;
    }
}
