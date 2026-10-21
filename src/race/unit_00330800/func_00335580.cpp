/* Resets an object: clears two embedded members (at +0xF8 and +0x108) and two fields, and, when it has an owner, resets the owner's
 * sub-object (func_003BFFE8) and re-registers its pair (f80, f78) with func_00394ED8 and func_00394D48. Class unknown. */
#include "types.h"

struct Sub {
    char pad0[0x78];
    s64 f78;
    void *f80;
};

struct Inner {
    char pad0[0x6C];
    Sub *p6C;
};

struct Self {
    Inner *p0;
    char pad4[0x108 - 4];
    char pad108[0x164 - 0x108];
    s32 f164;
    s32 f168;
};

extern "C" void func_005CD8E8(void *self);
extern "C" void func_003BFFE8(void *self);
extern "C" void func_00394ED8(void *self, s64 arg1);
extern "C" void func_00394D48(void *self);

extern "C" void func_00335580(Self *self) {
    func_005CD8E8((char *)self + 0x108);
    func_005CD8E8((char *)self + 0xF8);
    self->f168 = 0;
    {
        Inner *owner = self->p0;
        self->f164 = 0;
        if (owner != 0) {
            func_003BFFE8(owner->p6C);
            func_00394ED8(self->p0->p6C->f80, self->p0->p6C->f78);
            func_00394D48(self->p0->p6C->f80);
        }
    }
}
