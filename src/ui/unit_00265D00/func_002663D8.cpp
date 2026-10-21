/* Sets (nonzero argument) or clears (zero) bit 5 (mask 0x20) of the flag word at +0x9C of the UI object.
 * The argument is first normalised to 0/1 and shifted into place, which is why the mask/or sequence is spelled out.
 * What the bit controls is unknown (field stays unk9C). */
#include "types.h"

struct S002663D8 {
    char pad0[0x9C];
    s32 unk9C;
};

extern "C" void func_002663D8(struct S002663D8 *obj, s32 enable) {
    s32 enableBit = (s32)(enable != 0);
    s32 flags = obj->unk9C;
    flags = flags & ~0x20;
    flags = flags | (enableBit << 5);
    obj->unk9C = flags;
}
