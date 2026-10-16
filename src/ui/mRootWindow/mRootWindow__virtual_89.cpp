/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);

struct TypeInfo {
    const char *name;
};
template <class T> struct TypeTag;

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
        return (T *)func_00326750(n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct Elem { int v; Elem() {} Elem(const Elem &o) : v(o.v) {} ~Elem() {} };
extern "C" void *HSymID__tf(void);
template <> struct TypeTag<Elem> { static void *tf() { return HSymID__tf(); } };
struct Vec {
 int alloc; Elem *start, *finish, *limit;
 Elem *begin() {return start;} Elem *end() {return finish;}
 Elem *destroy_range(Elem *i) {Elem *f=finish; __destroy(i,f,__VALUE_TYPE(i)); return f;}
 void erase(Elem *first,Elem *last) { Elem *i=copy(last,finish,first); Elem *f=destroy_range(i); finish=f-(last-first); }
 void clear() {erase(begin(),end());}
};


struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct VObj { int pad; char *vt; };
struct VE { short d,i; void (*fn)(void*,int); };
struct VC { short d,i; void (*fn)(void*,void*,int,void*); };
struct Obj { char pad[0xCC]; Vec v; int padDC; Str s; };
extern Rep D_00659FA8;
extern char D_00698A08[],D_00698A18[];
extern "C" void *func_002310A0(int);
extern "C" int func_00265F38(void*);
extern "C" void mPhotoMapWindow__virtual_89(void*,int);
extern "C" void func_002556B0(void*);
extern "C" void func_0030F688(void*,void*);
extern "C" void func_00306C98(void*,void*,void*);
extern "C" void func_0030F808(void*,int);
extern "C" void func_00235C80(void*,int);
extern "C" void func_002550B8(void*,int);
extern "C" int func_00265D00(void*);
extern "C" void *func_002FA120(void*);
extern "C" void func_002F9B38(void*,int);
extern "C" char *func_005C2560(Rep*);
extern "C" int func_0057F260(const char*) throw();
extern "C" void *func_005C2630(void*,int,int,const char*,int);
extern "C" int HSymID__GetID(void*);
extern "C" void func_003069F8(void*,void*,void*);
extern "C" TypeInfo *func_005C11A8();
extern "C" void func_0030BB18(void*);
extern "C" void func_00309348(void*,void*);
extern "C" void func_00309378(void*,int);
extern "C" void func_003285A8(int);
extern "C" void func_003285F8(int);
extern "C" void RebuildPropagate__structor_0(void*);
extern "C" void func_0023FB80(void*);
extern "C" void func_0023F8E8(int,const char*);
extern "C" void func_0023DDF0(void*,int);
extern "C" void func_0024D328(void*);
struct MethodHandle { int p; int pad[3]; MethodHandle(){func_002FA120(this);} ~MethodHandle(){func_002F9B38(this,2);} };
struct Value { int p; Value() {func_0030BB18(this);} };
static inline void setarg(Value *dst,int *p0,int *tv) {
func_00309348(p0,tv);
if(dst!=(Value*)p0) {int nv=*p0;if(nv)func_003285A8(nv);int ov=dst->p;if(ov)func_003285F8(ov);dst->p=nv;}
func_00309378(p0,2);
}
static inline void callmethod(VObj *o,void *ret,int n,void*args){VC*e=(VC*)(o->vt+0xA8);e->fn((char*)o+e->d,ret,n,args);}
extern "C" void mRootWindow__virtual_89(Obj *self,int arg1) {
    int h[4]; int tmp0[4];
    VObj *target=(VObj*)func_002310A0(arg1);
    if(target) *(int*)((char*)target+0x1C)=1;
    Vec *v=&self->v;
    func_00265F38(self);
    mPhotoMapWindow__virtual_89(self,arg1);
    if(v->begin()!=v->end()) {
        func_002556B0(h);
        func_0030F688(tmp0,v);
        func_00306C98(self,h,tmp0);
        func_0030F808(tmp0,2);
        func_00235C80(self,h[0]);
        v->clear();
        func_002550B8(h,2);
    }
    union {int ret[4]; int final[4];} u; Str s;
    int *pr;

    if(func_00265D00(self)) {
        func_002FA120(h);
        pr=u.ret;
        Str *ps=&s;
        const char *src=D_00698A08;
        Rep *r=&D_00659FA8;
        char*d;
        if(r->sel)d=func_005C2560(r);else {d=(char*)(r+1);r->ref++;}
        ps->p=d;
        func_005C2630(ps,0,-1,src,func_0057F260(src));
        *pr=HSymID__GetID(ps);
        func_003069F8(self,h,pr);
        Rep *q=(Rep*)(ps->p-16);
        if(--q->ref==0){int cap=q->cap+16;func_00326798(q,cap,4,func_005C11A8()->name);}
        if(h[0]) {
            func_0030BB18(pr);
            Value args[2]; int tmp[4]; int tv[4];
            tv[0]=arg1;
            setarg(args,tmp,tv);
            callmethod((VObj*)h[0],pr,1,args);
            Value *end=args+2;
            while(args!=end){--end;func_00309378(end,2);}
            func_00309378(pr,2);
        }
        func_002F9B38(h,2);
    }
    RebuildPropagate__structor_0(self);
    pr=u.final;
    func_0023FB80(pr);
    Str *ss=&self->s;
    int val=*pr;
    const char *str;
    int len=((Rep*)(ss->p-16))->len;
    if(len==0)str=D_00698A18;
    else{ss->p[len]=0;str=ss->p;}
    func_0023F8E8(val,str);
    func_0023DDF0(pr,2);
    if(target){VE*e=(VE*)(target->vt+0x1A8);e->fn((char*)target+e->d,arg1);*(int*)((char*)target+0x1C)=0;func_0024D328(target);}
}
