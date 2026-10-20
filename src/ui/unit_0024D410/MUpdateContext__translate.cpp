/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
union U { Str s; void *h[4]; };
struct Heap { const char *name; };
struct VEntry { short delta, index; void (*fn)(void *,void *); };
struct Obj { int word; char *vt; };
extern Rep D_00659FA8;
extern char D_00699620[], D_00699628[];
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_005C2630(void *,unsigned int,unsigned int,const char *,unsigned int);
extern "C" void func_00314B20(void *,void *);
extern "C" void func_00312318(void *,int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
static inline Rep *rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *data(Rep *r) { return (char *)(r+1); }
static inline int length(Str *s) { return rep(s)->len; }
static inline void terminate(Str *s) { data(rep(s))[length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (length(s)==0) return D_00699620;
    terminate(s);
    return data(rep(s));
}
static inline void release(Str *s) {
    Rep *r=rep(s);
    if (--r->ref == 0) {
        int size = r->cap+16;
        func_00326798(r,size,4,func_005C11A8()->name);
    }
}
static inline void empty(Str *s) {
 Rep *r=&D_00659FA8; char *p;
 if(r->sel) p=func_005C2560(r);
 else { r->ref=r->ref+1; p=(char *)(r+1); }
 s->p=p;
}
static inline void vcall(void *ret,Obj *o) {
 VEntry *e=(VEntry *)(o->vt+0x18); e->fn(ret,(char *)o+e->delta);
}
extern char D_00699648[];
extern "C" void func_00232C78(void *,void *);
extern "C" void func_00232C20(void *,int);
extern "C" void func_00255110(void *,void *);
extern "C" void func_002550B8(void *,int);
extern "C" char *func_0025C110(void *);
extern "C" void *hModule__getName(void *);
extern "C" const char *func_00229D40(void *,void *,void *);
extern "C" const char *func_00486028(void *,const char *,const char *);
extern "C" void func_005DB110(const char *,const char *,int,const char *);
static inline void assign(void **dst,void **src) {
 if(dst!=src) { void *v=*src; if(v)func_003285A8(v); if(*dst)func_003285F8(*dst); *dst=v; }
}
extern "C" void MUpdateContext__translate(void **dst,int unused,int count,Obj **args) {
 struct Work { U u; Str a,b; char reserved[16]; Str d; char reserved2[16]; Str f; } w;
 if(count==2) {
  func_00232C78(&w.u,args);
  Obj **key=args+1;
  char *context=func_0025C110(w.u.h[0]);
  void *name=hModule__getName(w.u.h[0]);
  vcall(&w.a,*key);
  const char *value=func_00229D40(context,name,&w.a); release(&w.a);
  if(value) {
   empty(&w.b); func_005C2630(&w.b,0,-1,value,func_0057F260(value));
   func_00314B20(&w.a,&w.b); assign(dst,(void **)&w.a); func_00312318(&w.a,2); release(&w.b);
  } else {
   vcall(&w.a,*key); func_005DB110(D_00699628,D_00699648,0xA7,c_str(&w.a)); release(&w.a); assign(dst,(void **)key);
  }
  func_00232C20(&w.u,2);
 } else if(count>=3) {
  func_00255110(&w.u,args); char *context=func_0025C110(w.u.h[0]); func_002550B8(&w.u,2); char *dict = context + 0xB0;
  vcall(&w.u,args[1]); const char *key=c_str(&w.u.s);
  Obj **fallback=args+2;
  vcall(&w.d,*fallback); const char *value=func_00486028(dict,key,c_str(&w.d)); release(&w.d); release(&w.u.s);
  if(value) {
   empty(&w.f); func_005C2630(&w.f,0,-1,value,func_0057F260(value));
   func_00314B20(&w.u,&w.f); assign(dst,w.u.h); func_00312318(&w.u,2); release(&w.f);
  } else {
   vcall(&w.u,*fallback); func_005DB110(D_00699628,D_00699648,0xB5,c_str(&w.u.s)); release(&w.u.s); assign(dst,(void **)fallback);
  }
 }
}
