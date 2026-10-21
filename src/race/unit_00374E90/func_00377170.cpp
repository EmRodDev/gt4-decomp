/* compiler: ee-gcc2.96-stl */
/* Decides what the target object of slot idx does next and starts it; sibling of func_00376238 (same slot stride 0x19C,
 * same target pair at +0x148/+0x14C, same float rng at self+4; inferred from those offsets). flags bit 1 hands over to
 * the helpers func_00376D90/func_00377098; bit 2 re-initialises the current target; otherwise, when the slot is eligible
 * (field +0x138 not 3 and force clear), one of three random set-ups is used depending on the data bytes +0x88, +0x9C and
 * +0xB0: a fixed pattern, a coin-flip kind (0 or 5), or a kind drawn from the cumulative table D_00621158 (D_00621170 or
 * D_00621188 by a second flag). With nothing chosen it falls back to the current target's type (virtual +0xA0): type 3
 * or 4 continue through func_00376D90 / func_00376E68. Returns 1 when something was started, writing 1 to out[0] and
 * sometimes a float to out[2]. What kind numbers 0, 3, 4 and 5 mean in game terms is purpose unknown. */
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
 int kindChoice;
 char *rng=self+4;
 char *slot=self+idx*0x19C+0x10;
 char *otherTarget=F(slot,char *,0x14C);
 char *target=F(slot,char *,0x148);
 ctx.p0=obj; ctx.p4=self; ctx.p8=otherTarget; ctx.pC=target; ctx.p10=idx; ctx.p14=slot; ctx.p18=out; ctx.p1C=rng;
 int objField80=F(obj,int,0x80);
 if(force && get(self,idx)==target) F(target,int,0xE8)=3;
 if(flags&2) { if(!func_00376D90(&ctx,1)) func_00377098(&ctx); return 0; }
 if(flags&4) {
  char *currentTarget=get(self,idx);
  if(currentTarget==otherTarget) {
   float randomValue=func_00578598(rng);
   VE<void(*)(void *,void *,int,int,int,int,float)> *e=(VE<void(*)(void *,void *,int,int,int,int,float)> *)(F(currentTarget,char *,0)+0x138);
   e->fn(currentTarget+e->delta,slot,objField80,F(currentTarget,int,0x194),F(currentTarget,int,0x198),0,randomValue);
   F(self+idx*0x19C,char *,0x13C)=currentTarget;
  } else if(currentTarget==target) setupi(target,slot,val(target,0xB8));
 }
 int eligible=F(slot,int,0x138)!=3; if(force) eligible=0;
 if(eligible) {
  if(get(self,idx)!=target) {
   if(F(slot,unsigned char,0x88)) {
    setup(target,slot,0);
    if(func_00578598(rng)<0.5f) F(target,u64,0x268)=replaceByte(F(target,u64,0x268),8,1);
    speed(target,4,0.5f,2.0f*func_00578598(rng)+1.0f);
    start(target);
    u64 f268=replaceByte(F(target,u64,0x268),0,1);
    F(target,float,0x188)=75.0f;
    F(target,u64,0x268)=f268; F(target,u64,0x260)=(replaceByte(F(target,u64,0x260),56,1));
    F(self+idx*0x19C,char *,0x13C)=target;
    F(out,int,0)=1; return 1;
   }
   if(F(slot,unsigned char,0x9C)) {
    kindChoice=0; if(func_00578598(rng)<0.5f) kindChoice=5;
    setup(target,slot,kindChoice);
    float roll=func_00578598(rng);
    speed2(target,1.0f,2.0f*roll+1.0f);
    start(target);
    F(target,u64,0x268)=replaceByte(F(target,u64,0x268),0,1);
    if(val(target,0xB8)!=kindChoice) func_0037BC20(target,0);
    int result=1;
    F(self+idx*0x19C,char *,0x13C)=target;
    F(out,int,0)=1; F(out,float,8)=0.5f; return result;
   }
   char *subRecord=slot+0xA0;
   if(F(subRecord,unsigned char,0x10)) {
    float roll=func_00578598(rng);
    int bucket; for(bucket=0;bucket<5;bucket++) if(roll<=D_00621158[bucket]) break;
    if(bucket<=0)bucket=0; if(bucket>=4)bucket=4;
    int *kindTable=D_00621170; if(F(subRecord,signed char,0x12)) kindTable=D_00621188;
    setupi(target,slot,kindTable[bucket]);
    speed(target,4,0.19999999f,func_00578598(rng)*0.39999998f+0.39999998f);
    start(target);
    F(target,u64,0x268)=replaceByte(F(target,u64,0x268),0,1);
    F(self+idx*0x19C,char *,0x13C)=target;
    F(out,int,0)=1; return 1;
   }
  }
 }
 int currentType=val(get(self,idx),0xA0);
 float randomValue=flt(get(self,idx));
 if(currentType!=3) { if(currentType==4) { if(func_00376E68(&ctx,1)) { F(out,float,8)=randomValue; return 1; } } return 0; }
 if(func_00376D90(&ctx,1)) { F(out,float,8)=randomValue; return 1; }
 func_00377098(&ctx); return 0;
}
