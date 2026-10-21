/* compiler: ee-gcc2.96-stl */
#include "stl/stl_algobase.h"
#include "stl/stl_alloc.h"
#include "stl/stl_construct.h"
#include "stl/stl_uninitialized.h"
struct RefObject;
extern "C" void func_003285A8(RefObject*),func_003285F8(RefObject*);
struct Value{RefObject*p;Value(const Value&) __asm__("func_0021B5B8");~Value() __asm__("func_0021B5D0");Value&operator=(const Value&other){if(this!=&other){RefObject*next=other.p;if(next)func_003285A8(next);if(p)func_003285F8(p);p=next;}return *this;}};
struct TypeInfo{const char*name;};
extern "C" TypeInfo*MModelSet__tf() throw();
extern "C" void*func_00326750(unsigned,int,const char*);
extern "C" void func_00326798(void*,int,int,const char*);
template<> Value* __uninitialized_copy_aux(Value*,Value*,Value*,__false_type) __asm__("func_005CA130");
struct Vec{int alloc;Value*start;Value*finish;Value*end;};
static inline void deallocate(Value*p,unsigned n){if(p)func_00326798(p,n*4,4,MModelSet__tf()->name);}
extern "C" void func_005C9C10(Vec*self,Value*position,const Value&x){
 if(self->finish!=self->end){
  construct(self->finish,*(self->finish-1));
  ++self->finish;
  Value xcopy=x;
  copy_backward(position,self->finish-2,self->finish-1);
  *position=xcopy;
 }else{
  const unsigned oldsize=self->finish-self->start;
  const unsigned len=oldsize!=0?2*oldsize:1;
  Value*newstart=(Value*)func_00326750(len*4,4,MModelSet__tf()->name);
  Value*newfinish=newstart;
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
