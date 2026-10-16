/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"

struct State { char pad[0x16]; signed char x16, x17, x18; };
struct Dma { volatile unsigned int chcr; char pad[0x1c]; volatile unsigned int qwc; };

#define VIF1_STAT  (*(volatile unsigned int *)0x10003c00)
#define VIF1_FBRST (*(volatile unsigned int *)0x10003c10)
#define VIF1_CODE  (*(volatile unsigned int *)0x10003c80)

int func_004AB548(void) {
    volatile struct State *s = (volatile struct State *)((char *)spr_base() + 0x50);
    struct Dma *d;
    unsigned int v, flags;

    v = (VIF1_STAT >> 11) & 1;
    if (v == 0) {
        VIF1_FBRST = 8;
        __asm__ volatile("sync");
        __asm__ volatile("ei");
        return 1;
    }
    flags = VIF1_CODE;
    if (flags & 0x40000) {
        --s->x18;
        if (s->x18 >= 0) VIF1_FBRST = 8;
        __asm__ volatile("sync");
        __asm__ volatile("ei");
        return 1;
    }
    if (!(flags & 0x10000) || (--s->x16, s->x16 >= 0)) {
        VIF1_FBRST = 8;
    }
    if (flags & 0x20000) {
        ++s->x17;
        if (s->x17 == 0) {
            d = (struct Dma *)0x1000a000;
            v = d->chcr;
            d->qwc = 0;
            d->chcr = v | 0x100;
            __asm__ volatile("sync");
        }
    }
    __asm__ volatile("sync");
    __asm__ volatile("ei");
    return 1;
}
