/* Indexed lookup: reads the signed byte stored at self + index + 0xC and passes it, with the handle at +4, to func_003450A8
 * together with a constant 0.0f. Same shape as func_003D7360, func_003D7380 and func_003D7670, which differ only in the callee. */
#include "types.h"

struct Obj003D7648 {
    char pad[4];
    s32 unk4;
};

extern "C" s32 func_003450A8(s32 handle, s8 entry, f32 extra);

extern "C" s32 func_003D7648(Obj003D7648 *self, s32 index) {
    char *entryBase = (char *)self + index;
    return func_003450A8(self->unk4, *(s8 *)(entryBase + 0xC), 0.0f);
}
