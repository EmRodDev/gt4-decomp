/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_vector.h) instantiated by tools/stl_vector.py: vector<Str, GameAlloc> insert_aux */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);

/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() without typeid: the game's own __tf getter */
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

struct Rep { int len, cap, ref, sel; };
struct Heap { const char *name; };
extern "C" char *func_005C2560(Rep *) throw();
extern "C" Heap *func_005C11A8() throw();
struct Str {
    char *p;
    Str(const Str &o) {
        int q=*(int *)&o.p;
        Rep *r=(Rep *)(q-16);
        if(r->sel) q=(int)func_005C2560(r);
        else r->ref=r->ref+1;
        *(int *)&p=q;
    }
    ~Str() {
        Rep *r=(Rep *)(*(int *)&p-16);
        if(--r->ref==0) {
            int size=r->cap+16;
            func_00326798(r,size,4,func_005C11A8()->name);
        }
    }
    Str &operator=(const Str &o) {
        if (&o != this) {
            this->~Str();
            int q=*(int *)&o.p;
            Rep *r=(Rep *)(q-16);
            int d=q;
            if (r->sel) d=(int)func_005C2560(r);
            else r->ref=r->ref+1;
            *(int *)&p=d;
        }
        return *this;
    }
};
typedef Str Elem;
extern "C" void *func_005DC030(void) throw();
template <> struct TypeTag<Elem> { static void *tf() { return func_005DC030(); } };
typedef vector<Elem, GameAlloc<Elem> > Vec;

template void Vec::_M_insert_aux(Vec::iterator, const Elem &);

template <> Str *__uninitialized_copy_aux(Str *, Str *, Str *, __false_type) __asm__("func_005DC3F8");
/* func_005DC070 */
