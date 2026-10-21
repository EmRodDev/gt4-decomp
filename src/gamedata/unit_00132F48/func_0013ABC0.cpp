/* If the member at +0x2A4 exists, calls its virtual method in vtable slot 51 with the given integer (the function pointer is copied to a local first, as the original does). Not identified further. */
#include "types.h"

struct VEntry0013ABF8 {
    s16 delta;
    s16 index;
    int (*fn)(void *, int);
};

struct Sub0013ABF8 {
    char pad0[4];
    VEntry0013ABF8 *vtbl;
};

struct Obj0013ABF8 {
    char pad0[0x2A4];
    Sub0013ABF8 *unk2A4;
};

extern "C" void func_0013ABC0(struct Obj0013ABF8 *self, int value) {
    Sub0013ABF8 *member = self->unk2A4;

    if (member != 0) {
        VEntry0013ABF8 *entry = &member->vtbl[51];
        int (*fn)(void *, int) = entry->fn;
        fn((char *)member + entry->delta, value);
    }
}
