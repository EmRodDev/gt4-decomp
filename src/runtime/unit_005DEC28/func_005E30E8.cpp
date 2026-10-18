/* compiler: ee-gcc2.96-stl */
#define __adjust_heap func_005E2B48
#define __push_heap func_005E30E8
#include <stl_algobase.h>
#include <stl_iterator.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <limits.h>
#include <stdlib.h>
#include <stl_tempbuf.h>
#include <stl_alloc.h>
#include <stl_vector.h>
#include <stl_algo.h>

struct TypeInfo { const char *name; };
extern "C" void *MRegion__tf();
extern "C" void *func_00326750(int, int, const char *);
extern "C" void func_00326798(void *, int, int, const char *);

/* 16-byte float quadruple with the game's guarded assignment. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
    Vec4 &operator=(const Vec4 &o) {
        if (this != &o) { x = o.x; y = o.y; z = o.z; w = o.w; }
        return *this;
    }
};
extern "C" Vec4 *func_005E0D50(Vec4 *, Vec4 *, Vec4 *, int);
/* Mirrors SGI uninitialized_copy -> __uninitialized_copy(.., __VALUE_TYPE(result)): the
   by-reference value_type() probe makes the compiler keep `result` in memory. */
inline Vec4 *uninitialized_copy_aux(const Vec4 *first, const Vec4 *last, Vec4 *result, Vec4 *) {
    return func_005E0D50((Vec4 *)first, (Vec4 *)last, result, 0);
}
inline Vec4 *uninitialized_copy(const Vec4 *first, const Vec4 *last, Vec4 *result) {
    return uninitialized_copy_aux(first, last, result, __VALUE_TYPE(result));
}

template <class T>
class TaggedAllocator {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef TaggedAllocator<U> other; };
    TaggedAllocator() throw() {}
    TaggedAllocator(const TaggedAllocator &) throw() {}
    template <class U> TaggedAllocator(const TaggedAllocator<U> &) throw() {}
    ~TaggedAllocator() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return (T *)func_00326750(n * sizeof(T), 4, ((TypeInfo *)MRegion__tf())->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, ((TypeInfo *)MRegion__tf())->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

/* Elements have a verified 0x2C-byte layout; the scalar fields are not identified. */
struct Record {
    int unknown00;
    int unknown04;
    Vec4 unknown08;
    Vec4 unknown18;
    int unknown28;
};

/* 0x54-byte comparison state; the Vec4 vector at +0x40 is observed in the assembly. */
struct Compare {
    int unknown00;
    float unknown04, unknown08, unknown0C;
    int unknown10, unknown14;
    Vec4 unknown18;
    Vec4 unknown28;
    int unknown38, unknown3C;
    vector<Vec4, TaggedAllocator<Vec4> > unknown40;
    int unknown50;
    int operator()(const Record &, const Record &) const __asm__("func_0026F060");
};
template void func_005E30E8(Record *, int, int, Record, Compare);
