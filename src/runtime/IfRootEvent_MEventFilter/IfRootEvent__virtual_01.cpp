#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    s32 unk0;
    VEntry *vtbl;
};

struct Matcher {
    s32 unk0;
    s32 id;
    s32 kind;
    s32 found;
};

extern "C" s32 mWidget__getRootWindow(s32);
extern "C" s32 func_0028EA18(Obj *);

extern "C" s32 IfRootEvent__virtual_01(Matcher *self, Obj **ref) {
    s32 ok = 0;
    s32 t = func_0028EA18(*ref);
    if (t != 0) {
        Obj *o = *ref;
        VEntry *e = &o->vtbl[10];
        if (e->fn((char *)o + e->delta) == self->kind) {
            ok = mWidget__getRootWindow(t) == self->id;
        }
    }
    if (ok != 0) {
        self->found = 1;
    }
    return ok;
}
