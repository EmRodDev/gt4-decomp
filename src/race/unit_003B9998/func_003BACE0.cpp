/* Returns the second byte (+9) of the 32-bit flag word at +8 and, when clearIt is nonzero, zeroes that byte in the word (mask
 * 0xFFFF00FF). The same byte 1 of a flags word is the "active" state in 003FC168. Read-and-clear shape; the flag's meaning is purpose unknown. */
#include "types.h"

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" u8 func_003BACE0(Obj *self, s32 clearIt) {
    u8 flagByte = *((u8 *)self + 9);
    if (clearIt != 0) {
        self->unk8 = self->unk8 & 0xFFFF00FF;
    }
    return flagByte;
}
