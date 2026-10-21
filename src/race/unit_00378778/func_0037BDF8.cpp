/* Calls virtual slot 10 of the object at (self->unk18C)->unk2880 and returns the field at +0x40 of what it returns. Class unknown. */
#include "types.h"

struct VEntry0037BDF8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *);
};

struct ObjInner0037BDF8 {
    char pad0[8];
    VEntry0037BDF8 *vtbl;
};

struct Result0037BDF8 {
    char pad0[0x40];
    s32 unk40;
};

struct Mid0037BDF8 {
    char pad0[0x2880];
    ObjInner0037BDF8 *unk2880;
};

struct Obj0037BDF8 {
    char pad0[0x18C];
    Mid0037BDF8 *unk18C;
};

extern "C" s32 func_0037BDF8(struct Obj0037BDF8 *self) {
    ObjInner0037BDF8 *model = self->unk18C->unk2880;
    VEntry0037BDF8 *slot = &model->vtbl[10];
    struct Result0037BDF8 *result = (struct Result0037BDF8 *)slot->fn((char *)model + slot->delta);

    return result->unk40;
}
