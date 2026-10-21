/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
extern "C" void *func_00326750(unsigned int,int,const char *);
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" void *func_005D4D48();
struct Elem { int w[11]; ~Elem() {} };
template<> Elem *__uninitialized_copy_aux(Elem *,Elem *,Elem *,__false_type) __asm__("func_005D3CE8");
struct Vec {
 int alloc; Elem *start,*finish,*end;
 unsigned int size() const {return finish-start;}
 Elem *allocate(unsigned int n) {return (Elem *)func_00326750(n*sizeof(Elem),4,*(const char **)func_005D4D48());}
 void deallocate(Elem *p,unsigned int n) {if(p)func_00326798(p,n*sizeof(Elem),4,*(const char **)func_005D4D48());}
};
extern "C" void func_005D34A8(Vec *v,Elem *position,const Elem &x) {
 if(v->finish!=v->end) {
  construct(v->finish,*(v->finish-1));
  ++v->finish;
  Elem x_copy=x;
  copy_backward(position,v->finish-2,v->finish-1);
  *position=x_copy;
 } else {
  const unsigned int old_size=v->size();
  const unsigned int len=old_size!=0 ? 2*old_size : 1;
  Elem *new_start=v->allocate(len);
  Elem *new_finish=new_start;
  new_finish=uninitialized_copy(v->start,position,new_start);
  construct(new_finish,x);
  ++new_finish;
  new_finish=uninitialized_copy(position,v->finish,new_finish);
  destroy(v->start,v->finish);
  v->deallocate(v->start,v->end-v->start);
  v->start=new_start;v->finish=new_finish;v->end=new_start+len;
 }
}
