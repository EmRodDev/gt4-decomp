/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
extern "C" void func_00208F00(void *, const void *);
extern "C" void func_00208F18(void *, int) throw();
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void *MDomNode__tf();
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_00326798(void *, int, int, const char *);
struct Base {
 void *p;
 Base &operator=(const Base &o) {
  if(this!=&o) {void *v=o.p;if(v)func_003285A8(v);void *old=p;if(old)func_003285F8(old);p=v;} return *this;
 }
};
struct HObject:Base {
 HObject(const HObject &o) {func_00208F00(this,&o);}
 ~HObject() {func_00208F18(this,2);}
};
template<> HObject *__uninitialized_copy_aux(HObject *,HObject *,HObject *,__false_type) __asm__("func_005D7BE0");
struct Vec {
 int alloc; HObject *start,*finish,*end;
 unsigned int size() const {return finish-start;}
 HObject *allocate(unsigned int n) {return (HObject *)func_00326750(n*4,4,*(const char **)MDomNode__tf());}
 void deallocate(HObject *p,unsigned int n) {if(p)func_00326798(p,n*4,4,*(const char **)MDomNode__tf());}
};
extern "C" void func_005D6130(Vec *v,HObject *position,const HObject &x) {
 if(v->finish!=v->end) {
  construct(v->finish,*(v->finish-1));
  ++v->finish;
  HObject x_copy=x;
  copy_backward(position,v->finish-2,v->finish-1);
  *position=x_copy;
 } else {
  const unsigned int old_size=v->size();
  const unsigned int len=old_size!=0 ? 2*old_size : 1;
  HObject *new_start=v->allocate(len);
  HObject *new_finish=new_start;
  new_finish=uninitialized_copy(v->start,position,new_start);
  construct(new_finish,x);
  ++new_finish;
  new_finish=uninitialized_copy(position,v->finish,new_finish);
  destroy(v->start,v->finish);
  v->deallocate(v->start,v->end-v->start);
  v->start=new_start;v->finish=new_finish;v->end=new_start+len;
 }
}
