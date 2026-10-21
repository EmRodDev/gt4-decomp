/* Releases the resource held at +0x14 of the object through func_00460A28 (when non-null) and then clears the field.
 * Sibling of func_002C3D90, which only releases. */
#include "types.h"

struct Obj {
    char pad0[0x14];
    s32 unk14;
};

extern "C" void func_00460A28(s32 obj);

extern "C" void func_002C3DB8(struct Obj *obj) {
    struct Obj *self = obj;
    s32 handle = self->unk14;

    if (handle != 0) {
        func_00460A28(handle);
        self->unk14 = 0;
    }
}
