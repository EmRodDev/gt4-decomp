/* compiler: ee-gcc2.96-stl */
/* Fills *vec with the encoded bytes of an image: sizes the output buffer to width*height*3/2 (YUV 4:2:0-sized, inferred from the 3/2 factor), builds a 0x900-byte encoder object (Big), feeds it the dimensions and, when p is given, a second vector holding p's data prefixed with a 4-byte checksum from func_00579F38, then shrinks vec to the size the encoder reports (or 0 on failure). The local vector uses the STL allocator so the original's inlined vector code is reproduced. */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
extern "C" void func_00575DA0(int p) throw();
typedef unsigned char u8;
typedef unsigned int u32;
extern "C" void *func_00575E60(int heap, int size);

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

struct Vector { s32 a; u8 *begin; u8 *end; u8 *cap; };
extern "C" void *func_005A47D4(void *, const void *, u32);
extern "C" void func_005CD6E8(void *, u8 *, u32, const u8 *);
extern "C" void func_001C74B8(void *);
extern "C" void func_001C74F8(void *, s32);
extern "C" void func_001C7648(void *, void *, void *, void *);
extern "C" void func_001C7688(void *, void *, s32);
extern "C" s32 func_0046C258(void *);
extern "C" u32 func_0046F490(void *);
extern "C" s32 func_00579F38(void *, void *, s32);

inline void resize(Vector *vec, u32 n, const u8 &fill) {
    u8 *finish = vec->end;
    u32 size = finish - vec->begin;
    if (size > n) {
        u8 *resized = vec->begin + n;
        func_005A47D4(resized, finish, 0);
        vec->end -= finish - resized;
    } else
        func_005CD6E8(vec, finish, n - size, &fill);
}

struct Info {
    char pad0[4];
    s32 f4;
    char pad8[8];
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
};
struct Dims { s32 a, b, c; };
struct Span { s32 n; u8 *p; };
struct Sub { char pad[4]; u8 *start; u8 *finish; };
struct Obj { char pad[0xF8]; Sub sub; };
struct Big {
    char pad[0x85C];
    char f85C[0x80];
    char pad8DC[0x8DC - 0x85C - 0x80];
    s32 f8DC;
    char pad8E0[0x900 - 0x8E0];
    Big() { func_001C74B8(this); }
    ~Big() { func_001C74F8(this, 2); }
};
extern "C" void func_001CAF30(Vector *output, Info *imageInfo, Obj *extra, s32 setting) {
    s32 width = imageInfo->f10 * imageInfo->f18;
    s32 height = imageInfo->f14 * imageInfo->f1C;
    resize(output, (width * height * 3) / 2, 0);
    Dims dims;
    Span span;
    dims.a = width;
    dims.b = height;
    dims.c = imageInfo->f4;
    span.n = output->end - output->begin;
    span.p = output->begin;
    Big encoder;
    func_001C7648(&encoder, &dims, &span, extra ? (void *)((char *)extra + 0x144) : 0);
    encoder.f8DC = setting;
    vector<char, PlainAlloc<char> > extraVec;
#define v2 (*(Vector *)&extraVec)
    if (extra) {
        Sub *extraSource = &extra->sub;
        resize(&v2, extraSource->finish - extraSource->start + 4, 0);
        *(s32 *)v2.begin = func_00579F38(v2.begin + 4, extraSource->start, extraSource->finish - extraSource->start);
        func_001C7688(&encoder, v2.begin, v2.end - v2.begin);
    }
    if (func_0046C258(&encoder) != 0) {
        resize(output, func_0046F490(encoder.f85C), 0);
    } else {
        resize(output, 0, 0);
    }
}
