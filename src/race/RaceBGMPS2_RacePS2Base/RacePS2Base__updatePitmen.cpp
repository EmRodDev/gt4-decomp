#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct RacePS2Base {
    char pad0[0x64];
    VEntry *vtbl;             /* 0x64: vtable pointer */
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    char pad74[0x3628 - 0x74];
    char pitmen[1];           /* 0x3628: pitmen coordinator */
};

extern "C" u32 func_00579330(s32 arg0);
extern "C" void func_003CC7F8(void *arg0, s32 arg1);
extern "C" void func_003D03E0(void *arg0, s32 arg1, f32 arg2);

extern "C" void RacePS2Base__updatePitmen(RacePS2Base *self, f32 t) {
    VEntry *e = self->vtbl + 26;
    s32 v = e->fn((char *)self + e->delta, 0);
    func_003CC7F8(self->pitmen, func_00579330(v + 4));
    func_003D03E0(self->pitmen, self->unk70, t);
}
