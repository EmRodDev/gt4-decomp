/* Sets (nonzero argument) or clears (zero) bit 13 (mask 0x2000) of the flag word at +0x98 of the UI object.
 * The argument is first normalised to 0/1 and shifted into place, which is why the mask/or sequence is spelled out.
 * What the bit controls is unknown (field stays unk98). */
#include "types.h"

struct S00265DA8 {
    char pad0[0x98];
    s32 unk98;
};

extern "C" void func_00265DA8(struct S00265DA8 *obj, s32 enable) {
    s32 enableBit = (s32)(enable != 0);
    s32 flags = obj->unk98;
    flags = flags & ~0x2000;
    flags = flags | (enableBit << 13);
    obj->unk98 = flags;
}
