/* compiler: ee-gcc2.96-stl */
/* Resize the destination to one integer and read into that element.
 * Uses the original SGI vector resize/erase helpers (include/stl).
 * The allocator is opaque to this operation; insertion remains out of line. */
#pragma interface
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

// Only the allocator interface is needed here. Allocation is handled by the
// separately compiled vector insertion routine; this wrapper owns no vector.
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
    T *allocate(size_type n, const void *hint = 0);
    void deallocate(T *p, size_type n);
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef vector<int, GameAlloc<int> > IntVector;
template<> void IntVector::insert(int *, unsigned int, const int &)
    __asm__("func_005E73E8");
// Partial reader ABI: vtable at +0 and destination pointer at +4.
// The original translation units own both vtables.
class MReaderBase {
public:
    virtual ~MReaderBase() __asm__("func_0020FCE0");
};
class MintReader : public MReaderBase {
    int *destination;
public:
    MintReader(int *value) : destination(value) {}
    ~MintReader() {}
};
struct IntegerVectorReader {
    void *vtable;
    IntVector *destination;
};
extern "C" int func_0024DB78(MReaderBase *, void *);
extern "C" void MintReader__structor_22(IntegerVectorReader *self, void *input) {
    self->destination->resize(1);
    MintReader reader(self->destination->begin());
    func_0024DB78(&reader, input);
}
