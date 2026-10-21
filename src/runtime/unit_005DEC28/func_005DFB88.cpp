/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
typedef int s32;
typedef float f32;
struct Vec4 {
    f32 x,y,z,w;
    Vec4(const Vec4 &o):x(o.x),y(o.y),z(o.z),w(o.w) {}
    Vec4 &operator=(const Vec4 &o) {
        if (this != &o) { x=o.x; y=o.y; z=o.z; w=o.w; }
        return *this;
    }
};
struct Elem { s32 a,b; Vec4 p,q; s32 c; };
typedef unsigned int size_t;
struct Heap { const char *name; };
extern "C" Heap *func_005DBC80() throw();
extern "C" void *func_00326750(unsigned int,int,const char *);
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" Elem *func_005E0DE0(Elem *,Elem *,Elem *,int);
static inline Elem *copy_range(Elem *first,Elem *last,Elem *result) {
    return func_005E0DE0(first,last,result,(int)value_type(result));
}
static inline void destroy_aux(Elem *first,Elem *last,Elem *) {
    for(;first!=last;++first) {}
}
static inline void destroy_range(Elem *first,Elem *last) {
    destroy_aux(first,last,value_type(first));
}
static inline void dealloc(Elem *p,int n) {
    if(p) func_00326798(p,n*44,4,func_005DBC80()->name);
}
static inline void construct(Elem *p,const Elem &value) { new(p) Elem(value); }
struct Vector { int alloc; Elem *begin,*end,*cap; };
extern "C" void func_005DFB88(Vector *v,Elem *pos,const Elem &x) {
    if(v->end!=v->cap) {
        construct(v->end,*(v->end-1));
        ++v->end;
        Elem xcopy=x;
        copy_backward(pos,v->end-2,v->end-1);
        *pos=xcopy;
    } else {
        unsigned int oldsize=v->end-v->begin;
        unsigned int len=oldsize!=0?2*oldsize:1;
        Elem *start=(Elem *)func_00326750(len*44,4,func_005DBC80()->name);
        Elem *finish=start;
        finish=copy_range(v->begin,pos,start);
        construct(finish,x);
        ++finish;
        Elem *new_end=copy_range(pos,v->end,finish);
        destroy_range(v->begin,v->end);
        dealloc(v->begin,v->cap-v->begin);
        v->begin=start;
        v->end=new_end;
        v->cap=start+len;
    }
}
