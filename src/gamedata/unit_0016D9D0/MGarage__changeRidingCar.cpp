/* compiler: ee-gcc2.96-no-strict-aliasing */
struct H { void *p; char pad[12]; };
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Heap { const char *name; };
struct Ctx { char pad[76]; void *vt; };
struct Entry { short delta,idx; int (*fn)(void *); };
extern Rep D_00659FA8;
extern char D_006614F8[];
extern "C" void func_0016D848(void *,void *) throw();
extern "C" void func_0016D7F0(void *,int) throw();
extern "C" void func_00179280(void *,int);
extern "C" void func_001792D8(void *,void *);
extern "C" void func_0017CA80(void *,int,int);
extern "C" const char *GT4MC__getFileResultString(int);
extern "C" void func_001CC060(void *,int);
extern "C" int func_001CC528(void *,void *);
extern "C" void func_001CDA10(void *);
extern "C" int func_001CEAA8(void *,void *,void *,int);
extern "C" int func_001CED68(void *,void *,void *,int);
extern "C" void func_00312318(void *,int);
extern "C" void func_00314B20(void *,void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" Heap *func_005C11A8();
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" int func_0057F260(const char *) throw();
static inline void assign(H *d,H *s) {
 if(d!=s) { void *v=s->p; if(v)func_003285A8(v); if(d->p)func_003285F8(d->p); d->p=v; }
}
static inline void init(Str *s,const char *text) {
 Rep *r=&D_00659FA8; char *q;
 if(r->sel) q=func_005C2560(r); else { q=(char *)(r+1); r->ref=r->ref+1; }
 s->p=q;
 func_005C2630(s,0,-1,text,func_0057F260(text));
}
static inline void release(Str *s) {
 Rep *r=(Rep *)(s->p-16); if(--r->ref==0) { int n=r->cap+16; func_00326798(r,n,4,func_005C11A8()->name); }
}
static inline void result(H *out,H *h,Str *s,int n) {
 init(s,GT4MC__getFileResultString(n)); func_00314B20(h,s); assign(out,h); func_00312318(h,2); release(s);
}
static inline void *field(void *p,int off) { return *(void **)((char *)p+off); }
extern "C" void MGarage__changeRidingCar(H *out,void *src,int argc,void **argv) {
 union { struct { void *p; char pad[28]; } initial; H stream; H ret; } u;
 Str same;
 union { H ret; Str str; } a;
 H temp;
 Ctx ctx;
 union { H ret; Str str; } b;
 func_0016D848(&u.initial,src);
 void *garage=field(u.initial.p,16);
 func_0016D7F0(&u.initial,2);
 if(argc>0) {
  void *obj=*argv; Entry *e=(Entry *)((char *)field(obj,4)+0x58);
  int id=e->fn((char *)obj+e->delta);
  if(id==*(int *)((char *)garage+0x81c8)) {
   Str *s=&same; init(s,GT4MC__getFileResultString(0)); func_00314B20(&u.ret,s); assign(out,&u.ret); func_00312318(&u.ret,2); release(s);
  } else {
   int made=0; void *arg=argv+1;
   if(argc<2) {func_0017CA80(&temp,17,0); arg=&temp; made=1;}
   func_001792D8(&u.stream,arg);
   if(made)func_00179280(&temp,2);
   func_001CDA10(&ctx);
   if(!func_001CC528(&ctx,field(u.stream.p,28))) {
    Str *s=&b.str; init(s,GT4MC__getFileResultString(3)); H *h=&a.ret; func_00314B20(h,s); assign(out,h); func_00312318(h,2); release(s);
    ctx.vt=D_006614F8; func_001CC060(&ctx,0); func_00179280(&u.stream,2);
   } else {
    int n=func_001CEAA8(&ctx,field(u.stream.p,28),garage,0);
    if(!n)n=func_001CED68(&ctx,field(u.stream.p,28),garage,id);
    Str *s=&a.str; init(s,GT4MC__getFileResultString(n)); H *h=&b.ret; func_00314B20(h,s); assign(out,h); func_00312318(h,2); release(s);
    ctx.vt=D_006614F8; func_001CC060(&ctx,0); func_00179280(&u.stream,2);
   }
  }
 }
}
