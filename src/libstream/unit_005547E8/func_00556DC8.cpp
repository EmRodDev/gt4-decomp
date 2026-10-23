/* compiler: ee-gcc2.96-no-strict-aliasing */
/* When both flags at +0x284 and +0x280 are set, copies the six words at +0x268 to out, sends the
   4-byte block D_0064D250 on the object's channel (+0x0) through func_00567018 and returns 1;
   else returns 0. The two flag tests are one condition (separate early returns or a nested if
   lay the second failure out differently). */
#include "types.h"

struct func_00556DC8_a0 {
    s32 channel;
    char pad4[0x264];
    s32 data[6];
    s32 unk280;
    s32 unk284;
};

extern "C" char D_00655290[];
extern "C" char D_0064D250[];
extern "C" s32 func_00567018(void *obj, s32 channel, void *buf, s32 len, s32 a4);

extern "C" s32 func_00556DC8(struct func_00556DC8_a0 *o, s32 *out) {
    s32 i;
    if (o->unk284 == 0 || o->unk280 == 0)
        return 0;
    for (i = 0; i < 6; i++)
        out[i] = o->data[i];
    func_00567018(D_00655290, o->channel, D_0064D250, 4, 1);
    return 1;
}
