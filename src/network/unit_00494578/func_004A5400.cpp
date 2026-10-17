#include "spr.h"

struct Spr {
    unsigned char dirty;
};

/* Marks the scratchpad matrix copy stale and starts the VU0 microprogram at 0x930. */
extern "C" void func_004A5400(void) {
    Spr *s = (Spr *)spr_base();
    s->dirty = 1;
    __asm__ volatile("vcallms 0x930");
}
