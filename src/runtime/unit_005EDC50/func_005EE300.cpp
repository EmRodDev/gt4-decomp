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
template<> Sym* __uninitialized_copy_aux(Sym*,Sym*,Sym*,__false_type) __asm__("func_005EDCF0");
template<> Sym* __uninitialized_fill_n_aux(Sym*,unsigned,const Sym&,__false_type) __asm__("func_005EE170");
template<> void fill(Sym*,Sym*,const Sym&) __asm__("func_005EE138");
struct Vec{int alloc;Sym*start;Sym*finish;Sym*end;
Sym*begin()const{return start;}Sym*last()const{return finish;}
unsigned size()const{return finish-start;}unsigned capacity()const{return end-start;}
};
static inline void deallocate(Sym*p,unsigned n){if(p)func_00326798(p,n*4,4,HSymID__tf()->name);}
static inline Sym* allocate_and_copy(unsigned n,Sym*first,Sym*last){
Sym*result=(Sym*)func_00326750(n*4,4,HSymID__tf()->name);
uninitialized_copy(first,last,result);return result;}
extern "C" Vec*func_005EE300(Vec*self,const Vec&x){
 if(&x!=self){
  const unsigned xlen=x.size();
  if(xlen>self->capacity()){
   Sym*tmp=allocate_and_copy(xlen,x.begin(),x.last());
   destroy(self->begin(),self->last());
   deallocate(self->start,self->end-self->start);
   self->start=tmp;
   self->end=self->start+xlen;
  }else if(self->size()>=xlen){
   Sym*i=copy(x.begin(),x.last(),self->begin());
   destroy(i,self->last());
  }else{
   copy(x.begin(),x.begin()+self->size(),self->start);
   uninitialized_copy(x.begin()+self->size(),x.last(),self->finish);
  }
  self->finish=self->start+xlen;
 }
 return self;
}
