/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_list.h>
extern "C" void free(void *) throw();
template <class T> class Alloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() throw() {}
    Alloc(const Alloc &) throw() {}
    template <class U> Alloc(const Alloc<U> &) throw() {}
    ~Alloc() throw() {}
    T *allocate(size_type n, const void * = 0);
    void deallocate(T *p, size_type) { free(p); }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};
extern "C" void func_0060BDF0(list<int, Alloc<int> > *l, const int &value) {
    list<int, Alloc<int> >::iterator first = l->begin();
    list<int, Alloc<int> >::iterator last = l->end();
    while (first != last) {
        list<int, Alloc<int> >::iterator next = first;
        ++next;
        if (*first == value) l->erase(first);
        first = next;
    }
}
