/* Sets (nonzero argument) or clears (zero) bit 14 (mask 0x4000) of the flag word at +0x98 of the UI object.
 * The argument is first normalised to 0/1 and shifted into place, which is why the mask/or sequence is spelled out.
 * What the bit controls is unknown (field stays unk98). */
#include "types.h"

struct S00265E50 {
    char pad0[0x98];
    s32 unk98;
};

extern "C" void func_00265E50(struct S00265E50 *obj, s32 enable) {
    s32 enableBit = (s32)(enable != 0);
    s32 flags = obj->unk98;
    flags = flags & ~0x4000;
    flags = flags | (enableBit << 14);
    obj->unk98 = flags;
}
