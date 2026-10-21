/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_list.h>
struct TypeInfo{const char*name;};
extern "C" TypeInfo*func_005F1BC0();
extern "C" void *func_00326750(unsigned,int,const char*);
extern "C" void func_00326798(void*,int,int,const char*);
extern "C" void func_003285A8(void*);
extern "C" void func_003285F8(void*);
extern "C" void func_00318520(void*,const void*);
extern "C" void func_00318538(void*,int);
extern "C" void func_0030BB18(void*);
extern "C" void func_00309360(void*,void*);
extern "C" void func_00309378(void*,int);
extern "C" int hThread__execute(void*,unsigned);
struct Counter{char pad[0x20];int n;};
struct Thread{char pad[0x2c];Counter *owner;void *result;};
struct Handle{Thread*p;
Handle(){}
Handle(const Handle&h){func_00318520(this,&h);}
~Handle(){func_00318538(this,2);}
Handle&operator=(const Handle&h){if(this!=&h){Thread*q=h.p;if(q)func_003285A8(q);if(p)func_003285F8(p);p=q;}return *this;}
};

template <class T>
class GameAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef GameAlloc<U> other; };
    GameAlloc() throw() {}
    GameAlloc(const GameAlloc &) throw() {}
    template <class U> GameAlloc(const GameAlloc<U> &) throw() {}
    ~GameAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return (T*)func_00326750(n*sizeof(T),4,func_005F1BC0()->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p,n*sizeof(T),4,func_005F1BC0()->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef list<Handle,GameAlloc<Handle> > List;
struct Queue{List list; unsigned size()const{return list.size();}};
struct Context{char pad[16];Handle current;Queue queue;};
struct Result{void*p;char pad[12];};
static inline void assignResult(Result*a,void**b){if((void*)a!=(void*)b){void*q=*b;if(q)func_003285A8(q);if(a->p)func_003285F8(a->p);a->p=q;}}
extern "C" Result *func_00323110(Result*out,Context*self){
Result ret;func_0030BB18(&ret);
Handle *current=&self->current;
int running=1;
do{
*current=self->queue.list.front();
self->queue.list.pop_front();
int r=hThread__execute(current->p,0);
if(r==1)goto finished;
if(r==0)goto check;
if(r!=2)goto next;
self->queue.list.push_back(*current);
goto next;
finished:
--current->p->owner->n;
check:
if(self->queue.size()==0){running=0;assignResult(&ret,&current->p->result);}
next:;
}while(running);
func_00309360(out,&ret);func_00309378(&ret,2);return out;
}
