/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct DMA { volatile unsigned int control; char p4[0x1c]; volatile unsigned int count; char p24[0xc]; volatile unsigned int address; };
extern DMA *D_00629DC8[];
extern "C" int func_004A0F68(int) throw();
struct Flag { char pad[13]; volatile unsigned char active; };
static inline Flag *get_flag(void *base, int n) {
    int offset = n * 12 + 0x60;
    return (Flag *)((char *)base + offset);
}
extern "C" void func_004ABA50(int n, unsigned int address) {
    DMA *dma = D_00629DC8[n];
    func_004A0F68(n);
    struct Record { int a, b, c; };
    struct Scratch { char pad[0x60]; Record entries[8]; };
    Scratch *base = (Scratch *)spr_base();
    Flag *flag = get_flag(base, n);
    unsigned int region = address & 0x70000000;
    flag->active = 1;
    unsigned int v = address & 0x0fffffff;
    dma->count = 0;
    if (region == 0x70000000) v |= 0x80000000;
    dma->address = v;
    dma->control = (dma->control & 0xfec0) | 0x10000105;
    __asm__ volatile("sync");
}
