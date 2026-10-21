/* Calls 003B0428 with the buffer at +0x46, source and the size 0x20 (it reads like a bounded copy into a 32-byte field, inferred
 * from the constant only) and then clears the field at +0x24. Purpose unknown. */
#include "types.h"

struct Obj {
    u8 pad[0x24];
    s32 unk24;
};

extern "C" void func_003B0428(char *self, s32 source, s32 arg2);

extern "C" void func_003A4308(Obj *self, s32 source) {
    func_003B0428((char *)self + 0x46, source, 0x20);
    self->unk24 = 0;
}
