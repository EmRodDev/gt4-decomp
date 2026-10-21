/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; Str() {} Str(const Str&); };
struct Obj { char pad[4]; };
typedef Str (Obj::*PM)();
struct Handle { Obj *p; char pad[12]; };
struct TI { const char *name; };
extern "C" void func_001237E0(void *,int);
extern "C" void func_00123838(void *,void *);
extern "C" void func_00312318(void *,int);
extern "C" void func_00314B20(void *,void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" TI *func_005C11A8() throw();
extern "C" void func_00326798(void *,int,int,const char *);
static inline Obj *hget(Handle *h) { return h->p; }
static inline void release(Str *s) {
 Rep *q=(Rep *)(s->p-16);
 if (--q->ref == 0) {
  int size=q->cap+16;
  func_00326798(q,size,4,func_005C11A8()->name);
 }
}
inline void *operator new(unsigned int,void *p) throw() { return p; }
extern "C" void func_005C30B0(void **arg0,void *arg1,int arg2,int arg3,PM pmf) {
 Handle h;
 Str s;
 Handle o;
 Handle *po=&o;
 Str *ps=&s;
 func_00123838(po,arg1);
 new (ps) Str((hget(po)->*pmf)());
 Handle *ph=&h;
 func_00314B20(ph,ps);
 if ((void *)arg0 != (void *)ph) {
  void *v=ph->p;
  if(v) func_003285A8(v);
  if(*arg0) func_003285F8(*arg0);
  *arg0=v;
 }
 func_00312318(ph,2);
 release(ps);
 func_001237E0(po,2);
}
