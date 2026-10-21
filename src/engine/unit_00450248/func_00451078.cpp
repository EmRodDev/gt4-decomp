/* Like func_004510B0 but the node comes from the owner's child pointer at +0x20+0xC (selector non-zero) or +0x24+0xC (selector zero); returns the
 * node's field +0x7C or 0. */
#include "types.h"

struct Node_00451078 {
    char pad0[0x7C];
    s32 unk7C;
};

extern "C" s32 func_00451078(s32 *self, s32 selector) {
    char *owner;
    char *slotAddr;
    s32 offset;
    s32 altOffset;
    Node_00451078 *node;
    s32 result;

    owner = *(char **)self;
    if (owner != 0) {
        altOffset = 0x24;
        offset = 0x20;
        if (selector == 0) {
            offset = altOffset;
        }
        slotAddr = owner + offset;
        node = *(Node_00451078 **)(slotAddr + 0xC);
    } else {
        node = 0;
    }
    result = 0;
    if (node != 0) {
        result = node->unk7C;
    }
    return result;
}
