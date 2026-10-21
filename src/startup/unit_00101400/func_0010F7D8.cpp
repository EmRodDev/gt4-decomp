/* Loads four settings from the global state block pointed to by D_00622F4C (offsets +0x39D70, +0x3A344, +0x39D74, +0x39D94)
 * into the object. If the first one is negative ('unset') the byte at +0x43 of the sub-object at +0x70 is used instead.
 * The meaning of the settings is unknown (purpose unknown). */
#include "types.h"

struct Sub {
    char pad0[0x43];
    u8 fallback43;
};

struct Obj {
    s32 m0;
    s32 m4;
    s32 m8;
    char pad0C[0x70 - 0x0C];
    struct Sub *m70;
    char pad74[0xC4 - 0x74];
    s32 mC4;
};

extern "C" s32 D_00622F4C;

extern "C" void func_0010F7D8(struct Obj *self) {
    s32 *globalStatePtr = &D_00622F4C;
    s32 setting;

    setting = *(s32 *)((char *)*globalStatePtr + 0x39D70);
    if (setting < 0) {
        setting = self->m70->fallback43;
    }
    self->m0 = setting;
    self->mC4 = *(s16 *)((char *)*globalStatePtr + 0x3A344);
    self->m8 = *(s32 *)((char *)*globalStatePtr + 0x39D74);
    self->m4 = *(s32 *)((char *)*globalStatePtr + 0x39D94);
}
