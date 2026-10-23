/* compiler: ee-gcc2.96-stl */
/* Resize the destination to one color and parse into that element.
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

// The color constructor initializes all four floating-point channels to white.
// Keep its shared out-of-line lifetime operations, as in the original UI unit.
struct MColor {
    float red, green, blue, alpha;
    MColor() __asm__("func_002030A0");
    MColor(const MColor &) __asm__("func_002030C0");
    ~MColor() __asm__("func_00203118");
    MColor &operator=(const MColor &) __asm__("func_002030E8");
};
typedef vector<MColor, GameAlloc<MColor> > ColorVector;
// The old compiler ignores asm labels on this template specialization.
// Bridge its ordinary member interface to the recovered out-of-line body.
extern "C" void func_005E4BF8(ColorVector *, MColor *, unsigned int, const MColor *);
template<> inline void ColorVector::insert(MColor *position, unsigned int count,
                                          const MColor &value) {
    func_005E4BF8(this, position, count, &value);
}
class MReaderBase {
public:
    virtual ~MReaderBase() __asm__("func_0020FCE0");
};
class MColorReader : public MReaderBase {
    MColor *destination;
public:
    MColorReader(MColor *) __asm__("func_00203188");
    ~MColorReader() __asm__("func_002031A0");
};
struct ColorVectorReader {
    void *vtable;
    ColorVector *destination;
};
extern "C" int func_0024DB78(MReaderBase *, void *);
extern "C" void func_005E52A8(ColorVectorReader *self, void *input) {
    self->destination->resize(1);
    MColorReader reader(self->destination->begin());
    func_0024DB78(&reader, input);
}
