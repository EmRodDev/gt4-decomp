#include "types.h"

struct Obj {
    char pad0[0xC];
    void *vtbl;
};

extern char D_006233D8[];
extern char D_006881A0[];

extern "C" void *func_004383D8(Obj *self, void *def, s32 arg2, s32 arg3);

extern "C" void *func_0043C310(Obj *self, void *def, s32 arg2, s32 arg3) {
    if (def == 0) {
        def = D_006233D8;
    }
    void *r = func_004383D8(self, def, arg2, arg3);
    self->vtbl = D_006881A0;
    return r;
}
