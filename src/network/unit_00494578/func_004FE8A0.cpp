/* Returns the address of entry arg1 of a table of 0xC8-byte entries that starts at +0x1D8 inside the block pointed to by the field at +0x5A8; indexes of 0x40 or more
 * are clamped to the last entry (0x3F). Entry meaning is not identified. */
#include "types.h"

struct S004FE8A0 {
    char pad0[0x5A8];
    char *unk5A8;
};

extern "C" char *func_004FE8A0(struct S004FE8A0 *self, s32 index) {
    if (index >= 0x40) {
        index = 0x3F;
    }

    return self->unk5A8 + (index * 0xC8) + 0x1D8;
}
