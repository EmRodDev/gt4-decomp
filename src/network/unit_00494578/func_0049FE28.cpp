/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
/* Flush pending graphics registers into the packet chain. Two quadwords are
 * reserved for the DMA/VIF header and GIF A+D tag; the register writer returns
 * the number of payload quadwords. Scratchpad fields remain provisional. */
typedef unsigned int u32;
typedef unsigned long long u64;
struct Quad { u32 low, high; u64 registers; };
struct Scratch {
    char unknown0[0x1D8];
    u64 dirty;
    char unknown1E0[0x1F8 - 0x1E0];
    Quad *cursor;
    char unknown1FC[0x2C0 - 0x1FC];
    u64 outputFlags;
};
extern "C" int func_004AB350(Scratch *, Quad *);
#define WRITE_GIF_TAG(dst, value, registerValue) do { \
    Quad *q = (dst); u64 data = (value); u64 reg = (registerValue); \
    q->registers = reg; *(u64 *)q = data; \
} while (0)
extern "C" void func_0049FE28() {
    Scratch *state = (Scratch *)spr_base();
    if (!(state->outputFlags & 0xFFFF0000ULL)) {
        state->dirty = 0;
        return;
    }
    Quad *packet = state->cursor;
    int count = func_004AB350(state, packet + 2);
    if (count) {
        packet->low = (count + 1) | 0x10000000;
        ((u32 *)packet)[2] = 0x11000000;
        ((u32 *)packet)[3] = (count + 1) | 0x50000000;
        packet->high = 0;
        /* Packed A+D, one register, EOP set. Narrow the count before widening
         * so its sign cannot extend into the GIF control bits. */
        WRITE_GIF_TAG(packet + 1, (u64)(u32)(count | 0x8000) | 0x1000000000000000ULL, 0xE);
        state->cursor = packet + count + 2;
    }
}
