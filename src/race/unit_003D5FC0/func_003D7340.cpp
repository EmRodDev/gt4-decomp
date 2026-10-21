/* Indexed getter: reads the signed byte at self + index + 0xC and returns what 00344CE8 makes of it together with the int at +4.
 * The bytes starting at +0xC form a small table; their meaning is purpose unknown. */
#include "types.h"

struct Obj {
    char pad[4];
    s32 unk4;
};

extern "C" s32 func_00344CE8(s32 self, s8 index);

extern "C" s32 func_003D7340(Obj *self, s32 index) {
    char *entry = (char *)self + index;
    return func_00344CE8(self->unk4, *(s8 *)(entry + 0xC));
}
