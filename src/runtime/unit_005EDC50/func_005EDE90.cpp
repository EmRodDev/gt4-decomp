/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
struct Sym{int p;Sym(const Sym&o):p(o.p){}~Sym(){};Sym&operator=(const Sym&o){if(this!=&o)p=o.p;return *this;}};
struct TypeInfo{const char*name;};
extern "C" TypeInfo*HSymID__tf() throw();
extern "C" void*func_00326750(unsigned,int,const char*);
extern "C" void func_00326798(void*,int,int,const char*);
template<> Sym* __uninitialized_copy_aux(Sym*,Sym*,Sym*,__false_type) __asm__("func_005DB9A8");
template<> Sym* __uninitialized_fill_n_aux(Sym*,unsigned,const Sym&,__false_type) __asm__("func_005EE170");
template<> void fill(Sym*,Sym*,const Sym&) __asm__("func_005EE138");
struct Vec{int alloc;Sym*start;Sym*finish;Sym*end;};
static inline void deallocate(Sym*p,unsigned n){if(p)func_00326798(p,n*4,4,HSymID__tf()->name);}
extern "C" void func_005EDE90(Vec*self,Sym*position,unsigned n,const Sym&x){
 if(n!=0){
  if(unsigned(self->end-self->finish)>=n){
   Sym xcopy=x;
   const unsigned elems_after=self->finish-position;
   Sym*old_finish=self->finish;
   if(elems_after>n){
    uninitialized_copy(self->finish-n,self->finish,self->finish);
    self->finish+=n;
    copy_backward(position,old_finish-n,old_finish);
    fill(position,position+n,xcopy);
   }else{
    uninitialized_fill_n(self->finish,n-elems_after,xcopy);
    self->finish+=n-elems_after;
    uninitialized_copy(position,old_finish,self->finish);
    self->finish+=elems_after;
    fill(position,old_finish,xcopy);
   }
  }else{
   const unsigned oldsize=self->finish-self->start;
   const unsigned len=oldsize+max(oldsize,n);
   Sym*newstart=(Sym*)func_00326750(len*4,4,HSymID__tf()->name);
   Sym*newfinish=newstart;
   newfinish=uninitialized_copy(self->start,position,newstart);
   newfinish=uninitialized_fill_n(newfinish,n,x);
   newfinish=uninitialized_copy(position,self->finish,newfinish);
   destroy(self->start,self->finish);
   deallocate(self->start,self->end-self->start);
   self->start=newstart;
   self->finish=newfinish;
   self->end=newstart+len;
  }
 }
}
