/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_vector.h) instantiated by tools/stl_vector.py: vector<signed char, PlainAlloc40> insert_fill */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *) throw();

/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() without typeid: the game's own __tf getter */
template <class T> struct TypeTag;

template <class T>
class PlainAlloc40 {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef PlainAlloc40<U> other; };
    PlainAlloc40() throw() {}
    PlainAlloc40(const PlainAlloc40 &) throw() {}
    template <class U> PlainAlloc40(const PlainAlloc40<U> &) throw() {}
    ~PlainAlloc40() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x40, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef signed char Elem;
typedef vector<Elem, PlainAlloc40<Elem> > Vec;

typedef int s32;
typedef float f32;
typedef unsigned int u32;

struct Img {
    Vec v;
    s32 u10, u14, u18, u1C, u20;
    f32 f24;
    int bytes() const { int a=u10*u20*u14; int b=u18*u1C; return a*b; }
};

struct Src { int pad; int w,h,a,b; float scale; int pad18; Img main; char gap[16]; Img plane[3]; };
extern "C" int func_00575D00();
extern "C" void func_005CD968(void*);
static inline void setup(Img *im,int w,int h,int cols,int rows,int c,float scale){
 int old=im->bytes();
 im->f24=scale;
 im->u10=w; im->u14=h; im->u18=cols; im->u1C=rows; im->u20=c;
 unsigned int n=im->bytes();
 unsigned int avail=func_00575D00();
 if(n!=(unsigned int)old){
  func_005CD968(im);
  if(avail>=n) im->v.resize(n);
 }
}
extern "C" void func_00333C40(Src *self){
 for(int i=0;i<3;i++) setup(&self->plane[i],self->w,self->h,1,1,1,1.0f);
 setup(&self->main,self->w,self->h,1,1,3,self->scale);
}
