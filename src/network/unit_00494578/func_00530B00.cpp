/* compiler: ee-gcc2.96-exceptions-as2004 */
typedef unsigned long U64 __attribute__((aligned(4)));
struct Block {int a[19];};
struct Handle {int a,b,c,d;};
struct Output {int a,b;Block block;unsigned short h1,h2;unsigned packed;char text[16];int v;Handle handle;int tail,len;void *buf;int data;};
struct Source {int a,b;unsigned short h1;short p1;unsigned short h2;short p2;unsigned packed;Block block;int v;U64 handle;int tail;};
struct Hook {int flags,id;void (*call)(Output*);int data;};
struct VTable {char p[0x7c];int (*make)(Handle*,U64);};
extern Hook D_0064B488;
extern VTable *D_0064B4B0;
extern char D_006C34B0[];
extern "C" int func_00538F98(unsigned char*,unsigned short*);
extern "C" int func_0057DA20(void*,const char*,...);
extern "C" void *func_005A4724(void*,const void*,unsigned);
extern "C" void *func_005A48D8(void*,int,unsigned);
static inline void *clear_source(Source *s, int v, unsigned n) { return func_005A48D8(s, v, n); }
extern "C" int func_00530B00(int a,int b,int c,unsigned char *packet){
 unsigned char buf[0x130];Output out;
 func_005A48D8(&out,0,0x90);
 if(D_0064B488.call){
  unsigned char *p=packet+2;
  while(p-packet<*(unsigned short*)packet){
   unsigned short type,len;
   unsigned char *old=p;p+=2;func_00538F98(old,&type);
   old=p;p+=2;func_00538F98(old,&len);
   switch(type){
   case 0x8001:{
    Source src;
    clear_source(&src, 0, 0x70);
    int n=0x70;if(len<0x70U)n=len;
    func_005A4724(&src,p,n);p+=n;
    if(n<(int)len)p+=len-n;
    out.a=src.a;out.b=src.b;out.block=src.block;
    out.packed=src.packed;out.h1=src.h1;out.h2=src.h2;
    func_0057DA20(out.text,D_006C34B0,(int)(src.packed>>24),(int)((src.packed>>16)&255),(int)(src.packed&65535));
    out.v=src.v;
    D_0064B4B0->make(&out.handle,src.handle);
    out.tail=src.tail;break;
   }
   case 0x8002:
    func_005A4724(buf,p,len);out.len=len;out.buf=buf;p+=len;break;
   }
  }
  if((D_0064B488.flags&1) && out.b!=D_0064B488.id)return *(unsigned short*)packet;
  if((D_0064B488.flags&2) && out.a!=1)return *(unsigned short*)packet;
  out.data=D_0064B488.data;D_0064B488.call(&out);
 }
 return *(unsigned short*)packet;
}
