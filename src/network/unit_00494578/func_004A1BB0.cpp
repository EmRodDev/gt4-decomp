/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned char u8;
struct Spr {
 u8 b0, b1, b2, b3, b4, b5, b6, b7;
 char p0[0x38];
 u32 w40;
 char p1[0x194];
 u64 d1d8;
 char p2[8];
 u64 d1e8;
 char p3[8];
 u32 *cur;
 char p4[0xc];
 u32 *w208;
 u32 *w20c;
 char p5[0xb0];
 u8 b2c0, b2c1, b2c2;
 char p6[0xd5d];
 u32 words[5];
};
extern "C" u32 *func_004A1BB0(void) {
 Spr *c=(Spr *)spr_base();
 u32 *p=c->cur;
 u32 *start=p;
 p+=4;
 start[1]=(u32)p;
 p[0]=0x20000000;
 c->w208=p+1;
 p+=4;
 start[0]=(u32)p;
 p[0]=0x10000001;
 p[2]=0x03000000;
 p[3]=0x020001b3;
 p[4]=0x01000404;
 p[5]=0x05000000;
 p[6]=0x20000000;
 p[1]=0;
 p[7]=0xc0c0c0c0;
 p+=8;
 c->cur=p;
 c->d1d8=0x3ff1fff1fffUL;
 c->d1e8=0x3ff00001fffUL;
 c->w40=0xc0c0c0c0;
 c->w20c=start;
 c->b0=1;
 c->b3=0;
 c->b7=0;
 c->b2c1=0;
 c->b2c2=1;
 c->words[0]=0;
 c->words[1]=0;
 c->words[2]=0;
 c->words[3]=0;
 c->words[4]=0;
 return start;
}
