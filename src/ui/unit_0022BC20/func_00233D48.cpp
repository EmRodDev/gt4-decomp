/* Sets (nonzero argument) or clears (zero) bit 4 (mask 0x10) of the flag word at +0xE8 of the UI object.
 * The argument is first normalised to 0/1 and shifted into place, which is why the mask/or sequence is spelled out.
 * What the bit controls is unknown (field stays unkE8). */
#include "types.h"

struct Obj00233D48 {
    char pad[0xE8];
    s32 unkE8;
};

extern "C" void func_00233D48(struct Obj00233D48 *obj, s32 enable) {
    s32 enableBit = (s32)(enable != 0);
    s32 flags = obj->unkE8;
    flags = flags & ~0x10;
    flags = flags | (enableBit << 4);
    obj->unkE8 = flags;
}
