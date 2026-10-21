/* If the member at +0x2A4 exists, calls its virtual method in vtable slot 54 with the given integer. The class of the member and the method are not identified. */
#include "types.h"

struct VEntry0013A9A8 {
    s16 delta;
    s16 index;
    void (*fn)(void *, int);
};

struct Sub0013A9A8 {
    char pad0[4];
    VEntry0013A9A8 *vtbl;
};

struct Obj0013A9A8 {
    char pad0[0x2A4];
    Sub0013A9A8 *unk2A4;
};

extern "C" void func_0013A9A8(struct Obj0013A9A8 *self, int value) {
    Sub0013A9A8 *member = self->unk2A4;

    if (member != 0) {
        VEntry0013A9A8 *entry = &member->vtbl[54];
        entry->fn((char *)member + entry->delta, value);
    }
}
