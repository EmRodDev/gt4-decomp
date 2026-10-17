/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
/* the game's allocator carries one word of state (the heap id), so the vector's pointers start at +4 */
template <class T>
class HeapAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef HeapAlloc<U> other; };
    int heap;
    HeapAlloc() throw() {}
    HeapAlloc(const HeapAlloc &o) throw() : heap(o.heap) {}
    template <class U> HeapAlloc(const HeapAlloc<U> &o) throw() : heap(o.heap) {}
    ~HeapAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) { return 0; }
    void deallocate(T *p, size_type n) {}
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};
extern "C" void func_002030A0(void *);
extern "C" void func_00203118(void *, int);
struct Vec4 {
    float v[4];
    Vec4() { func_002030A0(this); }
    ~Vec4() { func_00203118(this, 2); }
};
typedef vector<Vec4, HeapAlloc<Vec4> > Vec;
template <> void Vec::insert(Vec4 *, unsigned int, const Vec4 &) __asm__("func_005E4BF8");
struct Holder { int pad; Vec *vec; };
extern "C" void func_005E5188(Holder *self, unsigned int n) {
    self->vec->resize(n);
}
