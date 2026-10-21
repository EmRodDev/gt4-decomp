/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long U64;
struct Entry { unsigned ptr; unsigned short value; unsigned char bits, op; };
struct VEntry { short delta, index; void (*fn)(void *); };
struct Stream {
 U64 value; int bits; unsigned *in, *end; unsigned char *window; int pos, unused;
 unsigned char *out, *outend; void *arena, *next; Entry *lit, *dist; int litbits, distbits, header; VEntry *vt;
};
extern "C" int func_00572D98(Stream *, int *, int, int, void *, void *, Entry **, int *, int) throw();
extern "C" void func_00573360(Stream *) throw();
extern unsigned char D_00655858[];
extern char D_00655758[], D_00655798[], D_006557D8[], D_00655818[];
#define SAVE s->value=value; s->bits=bits; s->in=in; s->end=end; s->pos=pos; s->out=out; s->outend=outend;
#define LOAD value=s->value; bits=s->bits; in=s->in; end=s->end; window=s->window; pos=s->pos; out=s->out; outend=s->outend;
#define CALL(N) { VEntry *e=s->vt+(N); e->fn((char *)s+e->delta); }
#define REFILL { if(bits<0) { bits+=32; if(in==end) { SAVE CALL(2) LOAD } value|=(U64)*in++ << bits; } }
#define DROP(N) { int drop_count=(N); value>>=drop_count; bits-=drop_count; REFILL }
extern "C" void func_00573898(Stream *s) {
 int lengths[316];
 U64 value; int bits; unsigned *in,*end; unsigned char *window,*out,*outend; int pos;
 int flags; Entry *table; int last, mask, nd, nl;
 int i, count;
 s->pos=0; LOAD REFILL
 if(s->header) {
  int n=(int)(value&65535); DROP(16)
  if(n==0x8b1f) {
   DROP(8)
   flags=(int)(value&255); DROP(8)
   for(int k=6;k--;) { DROP(8) }
   if(flags&8) { int c; do { c=(int)(value&255); DROP(8) } while(c); }
  } else { DROP(16) DROP(16) DROP(16) }
 }
 do {
  last=(int)(value&1); DROP(1)
  int type=(int)(value&3); DROP(2)
  if(type==2) {
   nl=(int)((value&31)+257); DROP(5)
   nd=(int)((value&31)+1); DROP(5)
   int nc=(int)((value&15)+4); DROP(4)
   s->next=s->arena;
   for(i=0;i<nc;i++) { lengths[D_00655858[i]]=(int)(value&7); DROP(3) }
   for(;i<19;i++) lengths[D_00655858[i]]=0;
   func_00572D98(s,lengths,19,19,0,0,&s->lit,&s->litbits,7);
   table=s->lit;
   mask=(1<<s->litbits)-1;
   int prev=0;
   count=nl+nd;
   i=0;
   while(i<count) {
    Entry *e=table+((int)value&mask);
    int n=e->bits; DROP(n)
    n=e->value;
    if(n<16) { lengths[i++]=prev=n; }
    else if(n==16) {
     n=(int)((value&3)+3); DROP(2)
     while(n--) lengths[i++]=prev;
    } else if(n==17) {
     n=(int)((value&7)+3); DROP(3)
     while(n--) lengths[i++]=0;
     prev=0;
    } else {
     n=(int)((value&127)+11); DROP(7)
     while(n--) lengths[i++]=0;
     prev=0;
    }
   }
   s->next=s->arena;
   func_00572D98(s,lengths,nl,257,D_00655758,D_00655798,&s->lit,&s->litbits,9);
   func_00572D98(s,lengths+nl,nd,0,D_006557D8,D_00655818,&s->dist,&s->distbits,6);
   SAVE func_00573360(s); LOAD
  } else if(type==0) {
   DROP(bits&7)
   count=(int)(value&65535); DROP(16) DROP(16)
   while(count--) {
    int c=(int)(value&255);
    *out++=c;
    if(window) { window[pos]=c; pos=(pos+1)&32767; }
    if(out==outend) { SAVE CALL(3) LOAD }
    DROP(8)
   }
  } else if(type==1) {
   s->next=s->arena;
   for(i=0;i<144;i++) lengths[i]=8;
   for(;i<256;i++) lengths[i]=9;
   for(;i<280;i++) lengths[i]=7;
   for(;i<288;i++) lengths[i]=8;
   int distances[32];
   for(i=0;i<30;i++) distances[i]=5;
   func_00572D98(s,lengths,288,257,D_00655758,D_00655798,&s->lit,&s->litbits,7);
   func_00572D98(s,distances,30,0,D_006557D8,D_00655818,&s->dist,&s->distbits,5);
   SAVE func_00573360(s); LOAD
  }
 } while(!last);
 SAVE CALL(3)
}
