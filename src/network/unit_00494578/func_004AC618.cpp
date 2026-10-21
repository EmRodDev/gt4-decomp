/* If the field at +0x48 is set, passes it to func_004AC7E0 (release-shaped guard, inferred from the null check; purpose unknown). */
#include "types.h"

struct Obj {
    char pad[0x48];
    s32 unk48;
};

extern "C" void func_004AC7E0(s32 self);

extern "C" void func_004AC618(Obj *self) {
    s32 member = self->unk48;
    if (member != 0) {
        func_004AC7E0(member);
    }
}
