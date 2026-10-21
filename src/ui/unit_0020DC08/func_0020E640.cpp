/* Calls virtual method slot 54 on the object referenced at +0x8 of this one. The vtable entry carries a this-adjustment (delta), as in multiple-inheritance thunks, so this is shifted by it before the call.
 * Which method slot 54 is is not known. */
#include "types.h"

struct VEntry_0020E640 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Inner_0020E640 {
    char pad0[4];
    VEntry_0020E640 *vtbl;
};

struct Obj_0020E640 {
    char pad[8];
    Inner_0020E640 *unk8;
};

extern "C" void func_0020E640(struct Obj_0020E640 *obj) {
    Inner_0020E640 *target = obj->unk8;
    VEntry_0020E640 *entry = &target->vtbl[54];

    entry->fn((char *)target + entry->delta);
}
