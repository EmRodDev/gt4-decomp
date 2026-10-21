/* Sets (nonzero argument) or clears (zero) bit 4 (mask 0x10) of the flag word at +0xB4 of the UI object.
 * The argument is first normalised to 0/1 and shifted into place, which is why the mask/or sequence is spelled out.
 * What the bit controls is unknown (field stays unkB4). */
#include "types.h"

struct Obj00293B70 {
    char pad[0xB4];
    s32 unkB4;
};

extern "C" void func_00293B70(struct Obj00293B70 *obj, s32 enable) {
    s32 enableBit = (s32)(enable != 0);
    s32 flags = obj->unkB4;
    flags = flags & ~0x10;
    flags = flags | (enableBit << 4);
    obj->unkB4 = flags;
}
