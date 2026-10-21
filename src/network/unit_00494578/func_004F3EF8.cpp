/* Returns the address of entry arg1 of a table of 0x70-byte entries that starts at +0x1D8 inside the block pointed to by the field at +0x5A8; indexes of 0x10 or more
 * are clamped to the last entry (0xF); same as func_004F53C8. Entry meaning is not identified. */
#include "types.h"

struct S004F3EF8 {
    char pad0[0x5A8];
    char *unk5A8;
};

extern "C" char *func_004F3EF8(struct S004F3EF8 *self, s32 index) {
    if (index >= 0x10) {
        index = 0xF;
    }

    return self->unk5A8 + (index * 0x70) + 0x1D8;
}
