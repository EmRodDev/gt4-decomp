/* compiler: ee-gcc2.96-stl */
typedef int s32;
typedef short s16;
typedef float f32;
typedef unsigned long long u64;
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
template<class T> struct VE { s16 delta,index; T fn; };
extern float D_00621158[];
extern int D_00621170[],D_00621188[];
static inline u64 replaceByte(u64 word, int shift, unsigned value) {
 return (word & ~((u64)255 << shift)) | ((u64)value << shift);
}
struct Ctx { void *p0; char *p4,*p8,*pC; int p10; char *p14,*p18,*p1C; };
extern "C" int func_00376D90(Ctx *,int) throw();
extern "C" int func_00376E68(Ctx *,int) throw();
extern "C" void func_00377098(Ctx *) throw();
extern "C" void func_0037BC20(void *,int);
extern "C" float func_00578598(void *);
static inline char *get(char *p,int i) { VE<char *(*)(void *,int)> *e=(VE<char *(*)(void *,int)> *)(F(p,char *,0)+0xD8); return e->fn(p+e->delta,i); }
static inline int val(char *p,int off) { VE<int(*)(void *)> *e=(VE<int(*)(void *)> *)(F(p,char *,0)+off); return e->fn(p+e->delta); }
static inline float flt(char *p) { VE<float(*)(void *)> *e=(VE<float(*)(void *)> *)(F(p,char *,0)+0xC8); return e->fn(p+e->delta); }
static inline void setup(char *p,char *s,const int &n) { VE<void(*)(void *,char *,int)> *e=(VE<void(*)(void *,char *,int)> *)(F(p,char *,0)+0x140); e->fn(p+e->delta,s,n); }
static inline int setupi(char *p,char *s,int n) { VE<int(*)(void *,char *,int)> *e=(VE<int(*)(void *,char *,int)> *)(F(p,char *,0)+0x140); return e->fn(p+e->delta,s,n); }
static inline void speed(char *p,int n,float a,float b) { VE<void(*)(void *,int,float,float)> *e=(VE<void(*)(void *,int,float,float)> *)(F(p,char *,0)+0x158); e->fn(p+e->delta,n,a,b); }
static inline void speed2(char *p,float a,float b) { VE<void(*)(void *,float,float)> *e=(VE<void(*)(void *,float,float)> *)(F(p,char *,0)+0x160); e->fn(p+e->delta,a,b); }
static inline void start(char *p) { VE<void(*)(void *)> *e=(VE<void(*)(void *)> *)(F(p,char *,0)+0x170); e->fn(p+e->delta); }
extern "C" int func_00377170(char *self,void *obj,int unused,int idx,int flags,char *out,int force) {
 Ctx ctx;
 int mode;
 char *rng=self+4;
 char *s=self+idx*0x19C+0x10;
 char *a=F(s,char *,0x14C);
 char *b=F(s,char *,0x148);
 ctx.p0=obj; ctx.p4=self; ctx.p8=a; ctx.pC=b; ctx.p10=idx; ctx.p14=s; ctx.p18=out; ctx.p1C=rng;
 int x=F(obj,int,0x80);
 if(force && get(self,idx)==b) F(b,int,0xE8)=3;
 if(flags&2) { if(!func_00376D90(&ctx,1)) func_00377098(&ctx); return 0; }
 if(flags&4) {
  char *p=get(self,idx);
  if(p==a) {
   float f=func_00578598(rng);
   VE<void(*)(void *,void *,int,int,int,int,float)> *e=(VE<void(*)(void *,void *,int,int,int,int,float)> *)(F(p,char *,0)+0x138);
   e->fn(p+e->delta,s,x,F(p,int,0x194),F(p,int,0x198),0,f);
   F(self+idx*0x19C,char *,0x13C)=p;
  } else if(p==b) setupi(b,s,val(b,0xB8));
 }
 int eligible=F(s,int,0x138)!=3; if(force) eligible=0;
 if(eligible) {
  if(get(self,idx)!=b) {
   if(F(s,unsigned char,0x88)) {
    setup(b,s,0);
    if(func_00578598(rng)<0.5f) F(b,u64,0x268)=replaceByte(F(b,u64,0x268),8,1);
    speed(b,4,0.5f,2.0f*func_00578598(rng)+1.0f);
    start(b);
    u64 f268=replaceByte(F(b,u64,0x268),0,1);
    F(b,float,0x188)=75.0f;
    F(b,u64,0x268)=f268; F(b,u64,0x260)=(replaceByte(F(b,u64,0x260),56,1));
    F(self+idx*0x19C,char *,0x13C)=b;
    F(out,int,0)=1; return 1;
   }
   if(F(s,unsigned char,0x9C)) {
    mode=0; if(func_00578598(rng)<0.5f) mode=5;
    setup(b,s,mode);
    float r=func_00578598(rng);
    speed2(b,1.0f,2.0f*r+1.0f);
    start(b);
    F(b,u64,0x268)=replaceByte(F(b,u64,0x268),0,1);
    if(val(b,0xB8)!=mode) func_0037BC20(b,0);
    int result=1;
    F(self+idx*0x19C,char *,0x13C)=b;
    F(out,int,0)=1; F(out,float,8)=0.5f; return result;
   }
   char *sub=s+0xA0;
   if(F(sub,unsigned char,0x10)) {
    float r=func_00578598(rng);
    int i; for(i=0;i<5;i++) if(r<=D_00621158[i]) break;
    if(i<=0)i=0; if(i>=4)i=4;
    int *table=D_00621170; if(F(sub,signed char,0x12)) table=D_00621188;
    setupi(b,s,table[i]);
    speed(b,4,0.19999999f,func_00578598(rng)*0.39999998f+0.39999998f);
    start(b);
    F(b,u64,0x268)=replaceByte(F(b,u64,0x268),0,1);
    F(self+idx*0x19C,char *,0x13C)=b;
    F(out,int,0)=1; return 1;
   }
  }
 }
 int type=val(get(self,idx),0xA0);
 float f=flt(get(self,idx));
 if(type!=3) { if(type==4) { if(func_00376E68(&ctx,1)) { F(out,float,8)=f; return 1; } } return 0; }
 if(func_00376D90(&ctx,1)) { F(out,float,8)=f; return 1; }
 func_00377098(&ctx); return 0;
}
