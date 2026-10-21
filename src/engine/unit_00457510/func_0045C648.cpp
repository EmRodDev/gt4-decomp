/* Resets the per-step collision result of one item before it is tested again: clears the fields at +0x3F0, +0x3F4, +0x3F8 and +0x400
 * and sets the earliest-contact time at +0x404 to 2.0 (inferred from the caller func_0045BB60, which steps time over 0..1 and keeps the
 * smallest contact time; 2.0 is therefore 'no contact yet'). +0x3F0 is the 'hit' flag and +0x3F4 the 'special' flag in that caller;
 * +0x3F8 and +0x400 are cleared but their purpose is unknown. */
#include "types.h"

extern "C" void func_0045C648(char *item) {
    *(s32 *)(item + 0x3F0) = 0;
    *(s32 *)(item + 0x3F4) = 0;
    *(s32 *)(item + 0x3F8) = 0;
    *(s32 *)(item + 0x400) = 0;
    *(f32 *)(item + 0x404) = 2.0f;
}
