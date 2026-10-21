/* Initialiser: runs the base step 004452F8 (self, baseArg), sets the byte at +0x166 to 1, and, when the signed int at source+0x60 is
 * nonnegative, copies it to +0x160, its low byte to +0x161 and sets the byte at +0x165 to 1 (so +0x165 reads as "value was provided",
 * inferred from the guarded write). It then runs 003D6350 with self and source. What the object is is purpose unknown. */
#include "types.h"

struct func_003D6418_arg0 {
    char pad0[0x160];
    s8 unk160;
    u8 unk161;
    char pad1[3];
    s8 unk165;
    u8 unk166;
};

struct func_003D6418_arg1 {
    char pad0[0x60];
    s32 unk60;
};

extern "C" void func_004452F8(void *a, void *lowByte);
extern "C" void func_003D6350(void *a, void *lowByte);

extern "C" void func_003D6418(struct func_003D6418_arg0 *self,
                              struct func_003D6418_arg1 *source,
                              void *baseArg) {
    s32 oneFlag = 1;
    func_004452F8(self, baseArg);
    self->unk166 = (s8)oneFlag;
    s32 value60 = source->unk60;
    if (value60 >= 0) {
        self->unk160 = (s8)value60;
        u8 lowByte = *(u8 *)((char *)source + 0x60);
        self->unk165 = (s8)oneFlag;
        self->unk161 = lowByte;
    }
    func_003D6350(self, source);
}
