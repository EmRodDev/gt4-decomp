/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
extern "C" void func_00309360(void *, const void *);
extern "C" void func_00309378(void *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void *HObject__tf() throw();
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_00326798(void *, int, int, const char *);
struct HObject {
 void *p;
 HObject(const HObject &o) {func_00309360(this, &o);}
 ~HObject() {func_00309378(this, 2);}
 HObject &operator=(const HObject &o) {
  if (this != &o) { void *v=o.p; if(v)func_003285A8(v); void *old=p; if(old)func_003285F8(old); p=v; } return *this;
 }
};
template<> HObject *__uninitialized_copy_aux(HObject *,HObject *,HObject *,__false_type) __asm__("func_005D8870");
template<> HObject *__uninitialized_fill_n_aux(HObject *,unsigned int,const HObject &,__false_type) throw() __asm__("func_005D84B0");
template<> void fill(HObject *,HObject *,const HObject &) __asm__("func_005D87E8");
static inline const unsigned int &maxn(const unsigned int &a, const unsigned int &b) {return a < b ? b : a;}
struct Vec {
 int alloc; HObject *start,*finish,*end;
 unsigned int size() const {return finish-start;}
 HObject *allocate(unsigned int n) {return (HObject *)func_00326750(n*4,4,*(const char **)HObject__tf());}
 void deallocate(HObject *p,unsigned int n) {if(p)func_00326798(p,n*4,4,*(const char **)HObject__tf());}
};
extern "C" void func_005D8510(Vec *v,HObject *position,unsigned int n,const HObject &x) {
 if(n!=0) {
  if((unsigned int)(v->end-v->finish)>=n) {
   HObject x_copy=x;
   const unsigned int elems_after=v->finish-position;
   HObject *old_finish=v->finish;
   if(elems_after>n) {
    uninitialized_copy(v->finish-n,v->finish,v->finish);
    v->finish+=n;
    copy_backward(position,old_finish-n,old_finish);
    fill(position,position+n,x_copy);
   } else {
    uninitialized_fill_n(v->finish,n-elems_after,x_copy);
    v->finish+=n-elems_after;
    uninitialized_copy(position,old_finish,v->finish);
    v->finish+=elems_after;
    fill(position,old_finish,x_copy);
   }
  } else {
   const unsigned int old_size=v->size();
   const unsigned int len=old_size+maxn(old_size,n);
   HObject *new_start=v->allocate(len);
   HObject *new_finish=new_start;
   new_finish=uninitialized_copy(v->start,position,new_start);
   new_finish=uninitialized_fill_n(new_finish,n,x);
   new_finish=uninitialized_copy(position,v->finish,new_finish);
   destroy(v->start,v->finish);
   v->deallocate(v->start,v->end-v->start);
   v->start=new_start; v->finish=new_finish; v->end=new_start+len;
  }
 }
}
