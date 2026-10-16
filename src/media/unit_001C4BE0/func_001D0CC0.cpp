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


struct Result { int value; };
static inline int status(const Result *const x) { return x->value; }
struct Ent { short off; short pad; void (*fn)(void *, float); };
struct VT { char p[0x10]; Ent e; };
extern VT D_00661718;
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
typedef vector<char, PlainAlloc40<char> > Buf;
struct Self { char p[0x150]; Buf buf; };
extern "C" Result func_001CD410(Self *, int, Buf *) throw();
extern "C" int func_001D4E60(char *, int, int, int, float, float);

extern "C" int func_001D0CC0(Self *self, int arg1, int unused, int arg3) {
    Loc l(arg3);
    l.step(0.0f);
    l.step(0.98f);
    Buf v;
    Result res = func_001CD410(self, arg1, &v);
    if (status(&res)) return res.value;
    char *p = v.begin();
    int n = func_001D4E60(p, v.size(), 0, 0, 0x1.5c9eecp-1f, 0x1.9db22cp-2f);
    if (n < 0) return 2;
    l.step(1.0f);
    copy(p + 8, p + 8 + n, v.begin());
    v.resize(n);
    v.swap(self->buf);
    l.step(1.0f);
    return 0;
}
