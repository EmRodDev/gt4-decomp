/* Sets two fields on the object: +0x108 = 1 and +0x10C = flag ^ 1 (the inverse of a boolean-like value). Field purposes unknown. */
#include "types.h"

struct Obj {
    char pad[0x108];
    s32 unk108;
    s32 unk10C;
};

extern "C" void func_001D93A8(s32 flag, Obj *self) {
    self->unk10C = flag ^ 1;
    self->unk108 = 1;
}
