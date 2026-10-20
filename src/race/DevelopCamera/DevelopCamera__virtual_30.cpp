#include "types.h"
struct VEntry { s16 delta; s16 index; void *(*fn)(void *, s32); };
struct Peer {
    char pad[0x100];
    char unk100[1];
};
struct Obj {
    VEntry *vtbl;
    char pad[0x9B8];
    s32 arg;
    char pad9C0[0xB40 - 0x9C0];
    char unkB40[1];
};
extern "C" void *DevelopCamera__virtual_30(struct Obj *self) {
    VEntry *e = &self->vtbl[27];
    Peer *r = (Peer *)e->fn((char *)self + e->delta, self->arg);
    if (r == 0)
        return self->unkB40;
    return r->unk100;
}
