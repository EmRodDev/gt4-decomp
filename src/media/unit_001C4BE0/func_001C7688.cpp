/* Stores the two given integers into the consecutive fields at +0x8F0 and +0x8F4 (purpose unknown). */
#include "types.h"

struct Obj {
    char pad[0x8F0];
    s32 unk8F0;
    s32 unk8F4;
};

extern "C" void func_001C7688(Obj *self, s32 first, s32 second) {
    self->unk8F0 = first;
    self->unk8F4 = second;
}
