/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned long U64;
#define Q(O) (*(U64 *)(p+(O)))
extern "C" void func_004A4550(unsigned k,int v) {
 char *p=(char *)spr_base();
 switch(k) {
 case 0: { U64 a,b,c; a=Q(0x1c0)&~(1UL<<34); b=(U64)(v&1)<<34; c=Q(0x1d8)|0x04000400UL; a|=b; Q(0x1c0)=a; Q(0x1d8)=c; return; }
 case 1: { U64 a,b,c; a=Q(0x1c0)&~(3UL<<35); b=(U64)(v&3)<<35; c=Q(0x1d8)|0x04000400UL; a|=b; Q(0x1c0)=a; Q(0x1d8)=c; return; }
 case 2: { U64 a,b,c; a=Q(0x1b8)&~0x1c0UL; b=(U64)(v&7)<<6; c=Q(0x1d8)|0x02000200UL; a|=b; Q(0x1b8)=a; Q(0x1d8)=c; return; }
 case 3: { U64 a,b,c; a=Q(0x1b8)&~0x20UL; b=(U64)(v&1)<<5; c=Q(0x1d8)|0x02000200UL; a|=b; Q(0x1b8)=a; Q(0x1d8)=c; return; }
 case 4: { U64 a,b,c; a=Q(0x1a8)&~3UL; b=v&3; c=Q(0x1d8)|0x00800080UL; a|=b; Q(0x1a8)=a; Q(0x1d8)=c; return; }
 case 5: { U64 a,b,c; a=Q(0x1a8)&~12UL; b=(U64)(v&3)<<2; c=Q(0x1d8)|0x00800080UL; a|=b; Q(0x1a8)=a; Q(0x1d8)=c; return; }
 case 6: { U64 a,b,c; a=Q(0x1b8)&~1UL; b=v&1; c=Q(0x1d8)|0x02000200UL; a|=b; Q(0x1b8)=a; Q(0x1d8)=c; return; }
 case 7: { U64 a,b,c; a=Q(0x1b8)&~28UL; b=(U64)(v&7)<<2; c=Q(0x1d8)|0x02000200UL; a|=b; Q(0x1b8)=a; Q(0x1d8)=c; return; }
 case 8: { U64 a,b,c; b=(U64)((v>>4)&0xfff)<<32; a=Q(0x1b8)&~(0xfffUL<<32); c=Q(0x1d8)|0x02000200UL; a|=b; Q(0x1b8)=a; Q(0x1d8)=c; return; }
 case 9: { U64 a,b,c; a=Q(0x1b8)&~(3UL<<19); b=(U64)(v&3)<<19; c=Q(0x1d8)|0x02000200UL; a|=b; Q(0x1b8)=a; Q(0x1d8)=c; return; }
 case 10: *(int *)(p+0x44)=v; return;
 case 11: *(char *)(p+0x158)=v; Q(0x1d8)|=1UL<<39; return;
 case 12: *(char *)(p+0x15c)=v; Q(0x1d8)|=1UL<<39; return;
 case 13: { U64 a,b,c; a=Q(0x158)&~(1UL<<15); b=(U64)(v&1)<<15; c=Q(0x1d8)|1UL<<39; a|=b; Q(0x158)=a; Q(0x1d8)=c; }
 default: return;
 }
}
