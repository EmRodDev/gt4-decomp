/* Initialises a 0xC-byte result block arg0 from arg1: returns 0x17 when either pointer is null, clears the block, runs func_00531CD8 (fills +0) and func_00531D40 (fills +4), and sets +8 to the +4 value plus arg1's field +0x14C (a pointer plus length, i.e. an end pointer, inferred from the addition). The first non-zero error code from the helpers is returned. */
#include "types.h"

struct Obj00531CD8 {
    char pad0[0x14C];
    s32 unk14C;
};

extern "C" s32 func_005A48D8(void *, s32, s32);
extern "C" s32 func_00531CD8(s32 *arg0, struct Obj00531CD8 *arg1);
extern "C" s32 func_00531D40(s32 arg0, s32 arg1);

extern "C" s32 func_00531D98(s32 *block, struct Obj00531CD8 *source) {
    s32 status = 0x17;

    if (block == 0) {
        return status;
    }
    func_005A48D8(block, 0, 0xC);
    status = 0x17;
    if (source == 0) {
        return status;
    }
    status = func_00531CD8(block, source);
    if (status != 0) {
        return status;
    }
    status = func_00531D40((s32)((char *)block + 4), (s32)source);
    if (status != 0) {
        return status;
    }
    *(s32 *)((char *)block + 8) =
        *(s32 *)((char *)block + 4) + source->unk14C;
    return status;
}
