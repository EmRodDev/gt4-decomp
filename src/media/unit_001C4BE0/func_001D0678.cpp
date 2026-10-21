/* Returns ((field at +8 - field at +4) of the block at arg1 + 0xF8 + 0x47) rounded down to a multiple of 0x40, i.e. a size padded to 64-byte alignment (inferred from the mask). The first argument is unused. */
#include "types.h"

struct Inner {
    char pad[4];
    s32 unk4;
    s32 unk8;
};

extern "C" s32 func_001D0678(s32 arg0, char *base) {
    Inner *block = (Inner *)(base + 0xF8);
    return ((block->unk8 - block->unk4) + 0x47) & ~0x3F;
}
