/* Setter: stores two 32-bit values at +0x194 and +0x198 (purpose unknown). */
#include "types.h"
struct Obj {
    char pad[0x194];
    s32 unk194;
    s32 unk198;
};
extern "C" void func_00475D68(Obj *self, s32 first, s32 second) {
    self->unk194 = first;
    self->unk198 = second;
}
