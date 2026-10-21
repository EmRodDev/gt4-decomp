/* Sets (nonzero argument) or clears (zero) bit 8 (mask 0x100) of the flag word at +0x308 of the UI object.
 * The argument is first normalised to 0/1 and shifted into place, which is why the mask/or sequence is spelled out.
 * What the bit controls is unknown (field stays unk308). */
#include "types.h"

struct S002BEB40 {
    char pad0[0x308];
    s32 unk308;
};

extern "C" void func_002BEB40(struct S002BEB40 *obj, s32 enable) {
    s32 enableBit = (s32)(enable != 0);
    s32 flags = obj->unk308;
    flags = flags & ~0x100;
    flags = flags | (enableBit << 8);
    obj->unk308 = flags;
}
