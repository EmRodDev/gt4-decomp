/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct Dma { unsigned int control; char pad[0xc]; unsigned int address; char pad1[0xc]; int count; };
extern volatile Dma *D_00629DC8[];
struct Entry { char pad[0xd]; volatile unsigned char flag; };
extern "C" int func_004A0F68(int) throw();
static inline Entry *get_flag(void *base, int n) {
 int offset = n * 12 + 0x60;
 return (Entry *)((char *)base + offset);
}
extern "C" void func_004A1140(int channel, unsigned int address, int count) {
 volatile Dma *d = D_00629DC8[channel];
 func_004A0F68(channel);
 char *s = (char *)spr_base();
 Entry *p = get_flag(s, channel);
 unsigned int segment = address & 0x70000000;
 p->flag = 1;
 unsigned int a = address & 0x0fffffff;
 d->count = count;
 if (segment == 0x70000000) a |= 0x80000000;
 d->address = a;
 d->control = (d->control & ~0x10f) | 0x101;
 __asm__ volatile("sync" ::: "memory");
}
