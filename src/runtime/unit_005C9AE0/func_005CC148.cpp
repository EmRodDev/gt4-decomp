/* Stores value * 128 (truncated to an integer, a fixed-point conversion, inferred) at +0x80 of the object pointed to by +0x10. */
#include "types.h"

struct Obj2 {
    char pad[0x80];
    s32 unk80;
};

struct Obj {
    char pad[0x10];
    struct Obj2 *unk10;
};

extern "C" void func_005CC148(struct Obj *self, f32 value) {
    self->unk10->unk80 = (s32)(value * 128.0f);
}
