/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef char u8;
typedef unsigned int u32;

struct Arg {
    char pad0[4];
    u8 *u4;
    char pad8[8];
    s32 u10;
    s32 u14;
    s32 u18;
    s32 u1C;
    s32 u20;
};

extern "C" void free(void *) throw();
extern "C" void *func_00575E60(s32, s32);
extern "C" void *func_005A4724(void *, const void *, u32);

template <class T>
class Alloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() throw() {}
    Alloc(const Alloc &) throw() {}
    template <class U> Alloc(const Alloc<U> &) throw() {}
    ~Alloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x10, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef vector<u8, Alloc<u8> > Vec;

extern "C" void func_00330FD8(void*,int,int,int,int) throw();
extern "C" void func_003331C8(void*,int,int,int,int,void*,void*);
extern "C" void func_00331388(Arg *p,int x,int y) {
 if(p->u18==1) {
  if(p->u1C==p->u18) {
   int w=p->u10;
   int h=p->u14;
   int width=w/x;
   int size=p->u20;
   int stride=w*size;
   int n=size*width*x;
   p->u10=width;
   p->u14=h/y;
   p->u18=x;
   p->u1C=y;
   {
    Vec v((Vec::size_type)n);
    for(int i=0;i<h;i++) {
     func_003331C8(p->u4+i*stride,size,p->u10,x,size,&v,(void*)func_005A4724);
    }
   }
   func_00330FD8(p->u4,p->u10*p->u20,x,h,1);
  }
 }
}
