/* Returns func_0056FB90(sub-object at +4, field at +0x7C, value). Sibling of func_004EF768 and func_004EF9A0 (same +4/+0x7C pattern); purpose unknown. */
#include "types.h"

struct Obj {
    char pad[0x7C];
    s32 unk7C;
};

extern "C" s32 func_0056FB90(void *self, s32 value, s32 arg2);

extern "C" s32 func_004EF6B0(Obj *self, s32 value) {
    return func_0056FB90((char *)self + 4, self->unk7C, value);
}
