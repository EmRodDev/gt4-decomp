/* Sets a block of 16 fields to default values (8, 3, 0x10, 1, 2 and zeros). The settings' meaning is unknown. */
#include "types.h"

struct Obj_00471EB8 {
    s32 m0;
    s32 m4;
    s32 m8;
    s32 mC;
    s32 m10;
    s32 m14;
    s32 m18;
    char m1C;
    char m1D;
    char pad1E[2];
    s32 m20;
    s32 m24;
    s32 m28;
    s32 m2C;
    s32 m30;
    s32 m34;
    s32 m38;
};

extern "C" void func_00471EB8(Obj_00471EB8 *self) {
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 3;
    self->mC = 8;
    self->m10 = 0;
    self->m14 = 0;
    self->m18 = 0;
    self->m1C = 1;
    self->m1D = 2;
    self->m20 = 0;
    self->m24 = 0;
    self->m28 = 0x10;
    self->m2C = 0x10;
    self->m30 = 0;
    self->m34 = 0;
    self->m38 = 0;
}
