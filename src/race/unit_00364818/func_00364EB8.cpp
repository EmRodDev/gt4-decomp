#include "types.h"

struct Inner {
    char pad[0x1704];
    f32 unk1704;
    char pad2[0x170A - 0x1704 - 4];
    u16 unk170A;
};

extern "C" f32 func_00364EB8(void **arg0, s32 *arg1) {
    void * volatile *p = arg0;
    volatile s32 *out = arg1;
    *out = (s32)((Inner *)*p)->unk170A;
    return ((Inner *)*p)->unk1704;
}
