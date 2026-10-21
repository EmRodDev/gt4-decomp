/* Setter: stores two 32-bit values at +0x30 and +0x34 (purpose unknown). Sibling of func_00475D88 (+0x38/+0x3C). */
#include "types.h"
struct Obj {
    char pad[0x30];
    s32 unk30;
    s32 unk34;
};
extern "C" void func_00475D78(Obj *self, s32 first, s32 second) {
    self->unk30 = first;
    self->unk34 = second;
}
