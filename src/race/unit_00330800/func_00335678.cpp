/* compiler: ee-gcc2.96-stl */
extern "C" void *memmove(void *, const void *, unsigned int) throw();
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;
extern "C" void *func_00575E60(int heap, int size);
extern "C" void func_00575DA0(int) throw();

template <class T>
class PlainAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef PlainAlloc<U> other; };
    PlainAlloc() throw() {}
    PlainAlloc(const PlainAlloc &) throw() {}
    template <class U> PlainAlloc(const PlainAlloc<U> &) throw() {}
    ~PlainAlloc() throw() {}
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


typedef signed char s8; typedef float f32;
extern "C" void *func_001C74B8(void *);
extern "C" void func_001C74F8(void *,int);
extern "C" void func_001C7648(void *,void *,void *,void *);
extern "C" void func_00331608(void *) throw();
extern "C" void func_00331930(void *,int,int) throw();
extern "C" void func_00331B40(void *,s32) throw();
extern "C" void func_00335558(void *) throw();
extern "C" u32 func_0046C258(void *);
extern "C" u32 func_0046F490(void *);
extern "C" void func_00575DA0(int) throw();

extern "C" void *func_005A47D4(int,int,u32) throw();
extern "C" void func_005CD6E8(void *,int,u32,s8 *);
struct Dimensions { s32 x,y,w,h; };
struct Body { vector<unsigned char, PlainAlloc<unsigned char> > v; Dimensions d; s32 type; Body(const Body &r):v(r.v) { d.x=r.d.x; d.y=r.d.y; d.w=r.d.w; d.h=r.d.h; type=r.type; } };
struct Record { Body body; f32 scale; };
struct Big { char body[0x900]; };
struct Dims { s32 x, y; unsigned char *p; };
struct Span { s32 n; unsigned char *p; };
struct Buffer { s32 alloc; unsigned char *start; unsigned char *finish; unsigned char *eos; };
struct Owner {
    char pad0[0x18];
    s32 flag;
    Record rec;
    char pad44[0x108 - 0x44];
    Buffer buf;
    char pad118[4];
    s32 x11C;
    char pad120[0x144 - 0x120];
    char x144[1];
};

static inline bool hasFlag(Owner *o) { return o->flag != 0; }

/* vector<unsigned char>::resize(n, x) */
static inline void resize(Buffer *v, u32 n, const unsigned char &x)
{
    unsigned char *finish = v->finish;
    u32 size = finish - v->start;
    if (n < size) {
        unsigned char *p = v->start + n;
        func_005A47D4((int)p, (int)finish, 0);
        v->finish -= finish - p;
    } else {
        func_005CD6E8(v, (int)finish, n - size, (s8 *)&x);
    }
}

extern "C" void func_00335678(Owner *self) {
    func_00335558(self);
    Record rec(self->rec);
    Dims dims;
    Span span;
    Big big;
    Buffer *buf;
    s32 w, h;

    func_00331608(&rec);
    if (hasFlag(self)) {
        func_00331B40(&rec, rec.body.d.x);
        func_00331930(&rec, 0, 0);
    }
    buf = &self->buf;
    w = rec.body.d.x * rec.body.d.w;
    h = rec.body.d.y * rec.body.d.h;
    resize(buf, w * h * 3 / 2, 0);
    dims.x = w;
    dims.y = h;
    dims.p = rec.body.v.begin();
    span.n = buf->finish - buf->start;
    span.p = buf->start;
    func_001C74B8(&big);
    func_001C7648(&big, &dims, &span, self->x144);
    *(s32 *)(big.body + 0x8DC) = self->x11C;
    if (func_0046C258(&big) != 0)
        resize(buf, func_0046F490(&big.body[0x85C]), 0);
    else
        resize(buf, 0, 0);
    func_001C74F8(&big, 2);
}
