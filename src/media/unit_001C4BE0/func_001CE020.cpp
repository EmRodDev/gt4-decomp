/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;
extern "C" void func_00575DA0(int p) throw();
extern "C" void *func_00575E60(int heap, int size);

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
        func_00575DA0((int)p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};


struct Ent { short off; short pad; void (*fn)(void *, float); };
struct VT { char p[0x10]; Ent e; };
extern VT D_00661718;
extern VT D_00661738;
extern VT D_0065CE00;
struct LocBase {
    VT *vptr;
    LocBase() { vptr = &D_0065CE00; }
    ~LocBase() { vptr = &D_0065CE00; }
};
struct Loc : LocBase {
    int f4;
    Loc(int a) { vptr = &D_00661718; f4 = a; }
    ~Loc() { vptr = &D_00661718; }
    void step(float f) { Ent *e = &vptr->e; e->fn((char *)this + e->off, f); }
};
struct Loc2 : LocBase {
    Loc *owner;
    float a;
    float b;
    Loc2(Loc *o, float x, float y) { vptr = &D_00661738; owner = o; a = x; b = y; }
    ~Loc2() { vptr = &D_00661738; }
};
struct VEntB { short off; short pad; s32 (*fn)(void *, void *); };
struct VEntC { short off; short pad; s32 (*fn)(void *); };
struct Gv { char *vtbl; };
extern char *D_00622F4C;
struct Result { int value; };
static inline int status(const Result *const x) { return x->value; }
extern "C" Result func_001CE868(void *, void *, void *, s32, s32);
extern "C" s32 func_001CCEC8(void *, void *, void *, s32, void *) throw();
extern "C" void func_001D4D10(void *, float, s32, float, u32, s32);

extern "C" s32 func_001CE020(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    Loc l(arg3);
    l.step(0.0f);
    char *g = D_00622F4C + 0xBC30;
    l.step(0.5f);
    s32 cnt = *(s32 *)(g + 0x81E0) + 1;
    Result res = func_001CE868(arg0, arg1, g, cnt != 0 ? cnt : 1, 1);
    if (status(&res)) return res.value;
    Gv *gv = (Gv *)D_00622F4C;
    VEntC *e3 = (VEntC *)(gv->vtbl + 0x10);
    s32 size = e3->fn((char *)gv + e3->off);
    vector<char, PlainAlloc40<char> > v((size_t)((size + 0x47) & ~0x3F));
    Gv *gv2 = (Gv *)D_00622F4C;
    VEntB *e4 = (VEntB *)(gv2->vtbl + 0x28);
    char *data = v.begin();
    e4->fn((char *)gv2 + e4->off, data + 8);
    func_001D4D10(data, 0x1.161910p-3f, size, 0x1.4f49cep-1f, 0, 0);
    Loc2 o(&l, 0.5f, 1.0f);
    s32 r = func_001CCEC8(arg0, arg1, v.begin(), v.size(), &o);
    *(s32 *)(g + 0x81E0) = cnt;
    l.step(1.0f);
    return r == 0;
}
