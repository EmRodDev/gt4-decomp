/* Passes the field at +0x14 and the object itself to func_004FAC30. Sibling of func_004FACC8 (func_004FAC78); purpose unknown. */
#include "types.h"

struct S004FAC58 {
    char pad0[0x14];
    s32 unk14;
};

extern "C" void func_004FAC30(s32 self, struct S004FAC58 *arg1);

extern "C" void func_004FAC58(struct S004FAC58 *self) {
    func_004FAC30(self->unk14, self);
}
