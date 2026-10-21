/* compiler: ee-gcc2.96-stl */
#include "stl/stl_algobase.h"
#include "stl/stl_alloc.h"
#include "stl/stl_construct.h"
#include "stl/stl_uninitialized.h"
struct Elem {
 int v;
 Elem(const Elem &o):v(o.v) {}
 ~Elem() {}
 Elem &operator=(const Elem &o) { if(this!=&o) v=o.v; return *this; }
};
struct TypeInfo { const char *name; };
extern "C" TypeInfo *HSymID__tf();
extern "C" void *func_00326750(unsigned,int,const char *);
extern "C" void func_00326798(void *,int,int,const char *);
template<> Elem *__uninitialized_copy_aux(Elem *,Elem *,Elem *,__false_type) __asm__("func_005DB9A8");
struct Vec { int alloc; Elem *start,*finish,*end; };
static inline void deallocate(Elem *p,unsigned n) { if(p) func_00326798(p,n*4,4,HSymID__tf()->name); }
extern "C" void func_005DB7E0(Vec *self,Elem *position,const Elem &x) {
 if(self->finish!=self->end) {
  construct(self->finish,*(self->finish-1));
  ++self->finish;
  Elem xcopy=x;
  copy_backward(position,self->finish-2,self->finish-1);
  *position=xcopy;
 } else {
  const unsigned oldsize=self->finish-self->start;
  const unsigned len=oldsize!=0?2*oldsize:1;
  Elem *newstart=(Elem *)func_00326750(len*4,4,HSymID__tf()->name);
  Elem *newfinish=newstart;
  newfinish=uninitialized_copy(self->start,position,newstart);
  construct(newfinish,x);
  ++newfinish;
  newfinish=uninitialized_copy(position,self->finish,newfinish);
  destroy(self->start,self->finish);
  deallocate(self->start,self->end-self->start);
  self->start=newstart;
  self->finish=newfinish;
  self->end=newstart+len;
 }
}
