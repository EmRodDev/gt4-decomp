#include "types.h"
extern "C" unsigned func_00567B38(void *, int);
extern u8 D_006CBAD0[];
extern u8 D_006CBCD0[];
extern "C" void func_0056DA68(u16 *out, int n, void *rng) {
    int saved = n;
    for (n = 0; n < saved; n++) {
        out[n] = 0x1800 + n * 0xa00;
    }
    unsigned index = func_00567B38(rng,6);
    if (saved > 0) {
        u8 *q = D_006CBAD0 + index * saved;
        u16 *p = out;
        n = saved;
        do {
            u8 x = *q;
            q++;
            n--;
            *p += (int)(x << 24) >> 19;
            p++;
        } while (n);
    }
    index = func_00567B38(rng,6);
    if (saved > 0) {
        u8 *q = D_006CBCD0 + index * saved;
        u16 *p = out;
        n = saved;
        do {
            u8 x = *q;
            q++;
            n--;
            *p += (int)(x << 24) >> 20;
            p++;
        } while (n);
    }
}
