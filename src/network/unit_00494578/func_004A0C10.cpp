/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned int u32;
typedef unsigned long u64;
struct Sub { char pad[0x58]; u64 f58,f60,f68,f70,f78; char pad80[8]; unsigned short f88,f8a; };
struct Spr { char pad[0x10]; unsigned char mode,x,y; char pad13[0x50-0x13]; Sub sub; };
#define REG(a) (*(volatile u64 *)(a))
extern "C" void func_004A0C10(u32 a,int b,int c) {
    Spr *s=(Spr *)spr_base();
    Sub *p=&s->sub;
    p->f68=(u64)(a>>11) | ((u64)((c>>6)&63)<<9) | ((u64)(b&15)<<15) | ((u64)(p->f8a&0x7ff)<<32) | ((u64)(p->f88&0x7ff)<<43);
    REG(0x12000000)=p->f58;
    REG(0x12000020)=p->f60;
    REG(0x12000090)=p->f68;
    REG(0x120000a0)=p->f70;
    REG(0x120000e0)=p->f78;
    if(s->mode==1) {
        REG(0x12000070)=p->f68;
        REG(0x12000080)=p->f70+((u64)s->y<<12)+s->x;
    }
    __asm__ volatile("sync");
}
