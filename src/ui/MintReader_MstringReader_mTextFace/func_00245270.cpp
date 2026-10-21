/* Resets the text face read state: clears the field at +0xF4, calls func_002B7310 on the object at +0x104 (purpose unknown) and sets the field at +0x114 to 1.
 * The class folder holds mTextFace and two reader classes; which one this belongs to is not known. */
#include "types.h"

struct Obj {
    char pad0[0xF4];
    s32 unkF4;
    char pad1[0x104 - 0xF8];
    s32 unk104;
    char pad2[0x114 - 0x108];
    s32 unk114;
};

extern "C" void func_002B7310(s32 face);

extern "C" void func_00245270(struct Obj *face) {
    struct Obj *self = face;

    self->unkF4 = 0;
    func_002B7310(self->unk104);
    self->unk114 = 1;
}
