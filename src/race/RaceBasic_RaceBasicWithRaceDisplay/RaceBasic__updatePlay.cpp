/* compiler: ee-gcc2.96-no-strict-aliasing */
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
struct VE { short d,i; int (*f)(void *); };
static inline int get(char *p,int off) { VE *e=(VE *)(F(p,char *,0x64)+off); return e->f(p+e->d); }
static inline int vcall_int(char *p,int off,int a) { VE *e=(VE *)(F(p,char *,0x64)+off); return ((int (*)(void *,int))e->f)(p+e->d,a); }
static inline void set(char *p,int off,int a) { VE *e=(VE *)(F(p,char *,0x64)+off); ((void (*)(void *,int))e->f)(p+e->d,a); }
static inline void setf(char *p,int off,float a) { VE *e=(VE *)(F(p,char *,0x64)+off); ((void (*)(void *,float))e->f)(p+e->d,a); }
static inline void other(char *p,int off,int a) { VE *e=(VE *)(F(p,char *,0)+off); ((void (*)(void *,int))e->f)(p+e->d,a); }
extern "C" {
void RacePS2Base__updatePlay(char *,float);
int func_0034C190(int,int);
int func_0035BC70(int);
int func_0035BCE8(int);
int func_0035BE10(int);
int func_0035BEB0(int);
void func_0035BFC0(int);
void func_003BABF8(char *);
void func_003BAC20(char *);
void func_003BAC40(char *,int);
int func_003BACE0(char *,int);
int func_003C12A8(int);
void func_003D3080(char *);
void func_003D30D0(char *);
void func_003D3120(char *);
float func_003D8B00(char *);
int func_003D8B78(char *);
void func_003D8DB8(char *,int);
void func_003D9390(char *,int);
void func_003DD540(char *,int,int,int);
void func_003DD5C8(char *);
void func_003DD5D8(char *,int);
extern char *DisplayRText__rtext_ptrs_;
extern int D_00621320;
}
#define P(off) F(p,char *,off)
static inline int active(char *p) { int a=0; if(P(0xE40C)) a=F(P(0xE40C),int,0xDC)!=0; return a; }
static inline void store48(char *q,int a) { F(q,int,0x48)=a; }
static inline void storeFC(char *q,int a) { F(q,int,0xFC)=a; }
static inline int modeflag(int a) { int flag=0; if(a==1 || a==3) flag=1; return flag; }
static inline int flagval(char *q) { if(!F(q,int,0x7C) && F(q,int,0x18)) return F(q,int,0x78); return 1; }
extern "C" void RaceBasic__updatePlay(char *p,float dt) {
 RacePS2Base__updatePlay(p,dt);
 if(P(0xE41C)) {
  int a=F(p,int,0x6C); int b=get(p,0x230);
  char *q=P(0xE41C); VE *e=(VE *)(F(q,char *,12)+0x20);
  ((void (*)(void *,int,int))e->f)(q+e->d,a,b);
 }
 if(P(0xE424)) {
  F(P(0xE424),int,0x7C)=0;
  store48(P(0xE424),active(p));
  func_003D8DB8(P(0xE424),get(p,0x230));
  func_003D9390(P(0xE424),vcall_int(p,0xD0,0));
  if(func_003D8B78(P(0xE424))) {
   setf(p,0xF0,func_003D8B00(P(0xE424)));
   set(p,0x470,flagval(P(0xE424)));
  } else set(p,0x470,1);
 }
 if(P(0xE40C)) {
  int c=func_0034C190(F(p,int,0x70),get(p,0x310));
  int flags=func_0035BC70(c);
  if(flags&1) {
   int a=(flags>>1)&1; int b=(flags>>3)&1;
   int d=func_003C12A8(F(p,int,0x6C));
   storeFC(P(0xE40C),modeflag(F(p,int,0xCC8)));
   func_003DD540(P(0xE40C),a,b,d);
   if(!a) {func_003D3080(p+0x3628);func_003D30D0(p+0x3628);}
   if(!b) func_003D3120(p+0x3628);
  }
  if(F(P(0xE40C),int,0xDC) && func_0035BCE8(c)) func_003DD5C8(P(0xE40C));
  func_003DD5D8(P(0xE40C),get(p,0x230));
 }
 if(P(0xE414)) {
  int c=func_0034C190(F(p,int,0x70),get(p,0x310));
  if(func_0035BE10(c)) func_003BABF8(P(0xE414));
  if(F(P(0xE414),unsigned char,8) && !func_0035BEB0(c)) func_003BAC20(P(0xE414));
  func_003BAC40(P(0xE414),get(p,0x230));
  if(func_003BACE0(P(0xE414),1)) func_0035BFC0(c);
 }
 char *q=P(0xE420);
 if(q) {
  if(P(0xE40C) && F(P(0xE40C),int,0xDC)) other(q,0xB0,F(DisplayRText__rtext_ptrs_,int,0x17C));
  else if(P(0xE414) && F(P(0xE414),unsigned char,8)) other(q,0xB0,F(DisplayRText__rtext_ptrs_,int,0x180));
  else other(q,0xB0,0);
  int val=get(p,0x420); other(P(0xE420),0xC0,val);
 }
 VE *e=(VE *)(F(p,char *,0x64)+0x4A8); ((void (*)(void *))e->f)(p+e->d);
 char *last=P(0xE420);
 if(last) { VE *e=(VE *)(F(last,char *,0)+0x90); ((int (*)(void *,int))e->f)(last+e->d,D_00621320^1); }
}
