/* Clears the six integer fields at +0x174..+0x188, except +0x180 which becomes -1 (probably a 'none' index, inferred from the value). The store order is the original's. Meaning of the fields is unknown
 * (the neighbours at +0x178 and +0x184 are read as hundredths by func_001465D8 and func_00146600). */
#include "types.h"

struct Obj {
    char pad0[0x174];
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
};

extern "C" void func_00146628(Obj *self) {
    self->unk174 = 0;
    self->unk180 = -1;
    self->unk178 = 0;
    self->unk17C = 0;
    self->unk184 = 0;
    self->unk188 = 0;
}
