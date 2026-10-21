/* Computes regionStart = base (field at +0x5C) + (blockIndex << 16), stores it at +0x60 and calls func_00345B90 on the
 * member at +8 with regionStart + 0x14F4 and 0xEB04. The two constants add up to exactly 0x10000, so the pair ends on the
 * next 64 KiB boundary (an observation; the shift by 16 suggests 64 KiB blocks, inferred). Meaning of the region unknown. */
#include "types.h"

struct Obj {
    char pad0[0x5C];
    s32 unk5C;
    s32 unk60;
};

extern "C" void func_00345B90(struct Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_00346890(struct Obj *self, s32 blockIndex) {
    s32 regionStart = self->unk5C + (blockIndex << 16);
    self->unk60 = regionStart;
    func_00345B90((struct Obj *)((char *)self + 8), regionStart + 0x14F4, 0xEB04);
}
