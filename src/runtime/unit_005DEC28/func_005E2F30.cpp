/* compiler: ee-gcc2.96-stl */
#define __unguarded_linear_insert func_005E2F30
#define __unguarded_insertion_sort_aux func_005E1EB0
#define __insertion_sort func_005E2870
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
inline Vec4 *uninitialized_copy(const Vec4 *first, const Vec4 *last, Vec4 *result) {
    return func_005E0D50((Vec4 *)first, (Vec4 *)last, result, 0);
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

/* 44-byte sort record. */
struct Record {
    int a, b;
    Vec4 v1;
    Vec4 v2;
    int c;
};

/* 0x54-byte comparator; owns a vector<Vec4> at +0x40, so by-value copies allocate. */
struct Compare {
    int w0;
    float f4, f8, fC;
    int w10, w14;
    Vec4 v18;
    Vec4 v28;
    int w38, w3C;
    vector<Vec4, TaggedAllocator<Vec4> > points;
    int w50;
    int operator()(const Record &, const Record &) const __asm__("func_0026F060");
};
template void func_005E2F30(Record *, Record, Compare);
