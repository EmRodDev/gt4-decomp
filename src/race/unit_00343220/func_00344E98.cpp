/* Returns the signed byte number index of the array at +0x4C in the per-variant record of the block at +0x10 (the record comes from
 * func_00359510, a table with 0x54-byte rows, as seen in its own source). What the byte array holds is purpose unknown. */
#include "types.h"

struct Arg0 {
    char pad[0x10];
    void *unk10;
};

extern "C" void *func_00359510(void *self);

extern "C" s8 func_00344E98(Arg0 *self, char *index) {
    char *entry = index + (s32)func_00359510(self->unk10);
    return *(s8 *)(entry + 0x4C);
}
