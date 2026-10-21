/* Stores the integer at +0x2B4 (purpose unknown) and, if the member at +0x2A4 exists, forwards the same integer to its virtual method in vtable slot 60. */
#include "types.h"

struct VEntry0013ACC8 {
    s16 delta;
    s16 index;
    void (*fn)(void *, int);
};

struct Sub0013ACC8 {
    char pad0[0x4];
    VEntry0013ACC8 *vtbl;
};

struct Obj0013ACC8 {
    char pad0[0x2A4];
    Sub0013ACC8 *unk2A4;
    char pad1[0xC];
    int unk2B4;
};

extern "C" void func_0013ACC8(struct Obj0013ACC8 *self, int value) {
    self->unk2B4 = value;

    Sub0013ACC8 *member = self->unk2A4;

    if (member != 0) {
        VEntry0013ACC8 *entry = &member->vtbl[60];
        entry->fn((char *)member + entry->delta, value);
    }
}
