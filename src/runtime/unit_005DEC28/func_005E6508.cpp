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
struct Elem8 { int a, b; Elem8() {} };
typedef vector<Elem8, HeapAlloc<Elem8> > Vec;
template <> void Vec::insert(Elem8 *, unsigned int, const Elem8 &) __asm__("func_005E66B8");
struct Holder { int pad; Vec *vec; };
extern "C" void func_005E6508(Holder *self, unsigned int n) {
    self->vec->resize(n);
}
