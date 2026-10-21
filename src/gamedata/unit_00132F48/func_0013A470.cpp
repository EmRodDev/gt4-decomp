/* If the member at +0x2A4 exists, calls its virtual method in vtable slot 53 (no arguments, no result used). The class of the member and the method are not identified. */
#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Sub {
    char pad0[4];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x2A4];
    Sub *unk2A4;
};

extern "C" void func_0013A470(Obj *self) {
    Sub *member = self->unk2A4;
    if (member != 0) {
        VEntry *entry = &member->vtbl[53];
        entry->fn((char *)member + entry->delta);
    }
}
