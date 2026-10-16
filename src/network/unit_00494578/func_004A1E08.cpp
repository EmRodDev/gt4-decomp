/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct Packet { unsigned w0,w4,w8,wc; };
struct Spr { char pad[0x1d8]; unsigned long current,next; char gap[0x10]; Packet *cursor; unsigned x1fc,x200,mask; unsigned *link; Packet *list,*tag; char gap214[0xae]; unsigned char active,dirty; };
static inline unsigned addr(Spr *s,unsigned v){unsigned a=0;if(v)a=(v&0x0fffffff)|s->mask;return a;}
extern "C" void func_004A1E08() {
 Spr *s=(Spr*)spr_base();
 Packet *p=s->cursor;
 p->w0=0x60000000; p->w8=0; p->wc=0; p->w4=0;
 p++;
 *s->link=(unsigned)p&0x0fffffff;
 p->w0=0x60000000;
 p++;
 s->cursor=p;
 unsigned long n=s->next;
 s->current=n;
 *(unsigned long*)((char*)s->tag+8)=n;
 s->dirty=0;
 if(s->active) {
  Packet *q=s->list;
  s->link=(unsigned*)addr(s,q->wc);
  *(unsigned*)addr(s,q->w8)=(unsigned)s->cursor&0x0fffffff;
 }
}
