/* Sets the two output fields at +0x592 (flag byte) and +0x594 (weight) from the mode byte at owner+0x1077 and the value at +0x53C
 * (speed-like; inferred from func_0036C690 handing it to the gear-for-speed helper). Mode 1: weight 1.0 once the value reaches
 * the owner threshold at +0x107C; mode 2: weight from func_003F2798; mode 6: weight 2/13 above the same threshold. Meaning of
 * the modes is unknown. */
#include "types.h"

struct func_003F2798_p;

extern "C" f32 func_003F2798(struct func_003F2798_p *p, f32 x);

extern "C" void func_003F27E8(char *self) {
    char *owner = *(char **)(self + 0x10);
    s32 mode = *(u8 *)(owner + 0x1077);
    char *state = self + 0x104;

    *(s32 *)(state + 0x594) = 0;
    *(s32 *)(state + 0x598) = 0;
    *(u8 *)(state + 0x592) = 0;
    *(u8 *)(state + 0x593) = 0;

    switch (mode) {
    case 1:
        if (*(f32 *)(owner + 0x107C) <= *(f32 *)(state + 0x53C)) {
            f32 weight = 1.0f;
            *(u8 *)(state + 0x592) = (u8)mode;
            *(f32 *)(state + 0x594) = weight;
        }
        break;
    case 2: {
        f32 weightFromCurve = func_003F2798((struct func_003F2798_p *)self, *(f32 *)(state + 0x53C));
        *(f32 *)(state + 0x594) = weightFromCurve;
        break;
    }
    case 6:
        if (*(f32 *)(owner + 0x107C) <= *(f32 *)(state + 0x53C)) {
            f32 weight = 0x1.3B13B0p-3f;
            *(u8 *)(state + 0x592) = 1;
            *(f32 *)(state + 0x594) = weight;
        }
        break;
    }
}
