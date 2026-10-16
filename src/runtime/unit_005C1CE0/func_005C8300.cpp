/* compiler: ee-gcc2.96-stl */
/* SGI STL sort_heap: handle and unsigned-short sequence key.
   Reproduce with knowledge/recipes/scored_sort.py; public headers: THIRD_PARTY.md. */
#define __introsort_loop func_005C5908
#define __unguarded_partition func_005C7098
#define __partial_sort func_005C7300
#define __insertion_sort func_005C75A0
#define sort_heap func_005C8300
#define __make_heap func_005C8588
#define __adjust_heap func_005C86C0
#define __push_heap func_005C9378
#define __unguarded_linear_insert func_005C8950
#define __unguarded_insertion_sort_aux func_005C7888
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

/* Existing game helpers: copy/destroy a handle, then retain/release an object. */
extern "C" void *func_0013BD50(void *, const void *);
extern "C" void func_0013BD68(void *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

struct RefCountedHandle_005C8300 {
    void *object;
    RefCountedHandle_005C8300(const RefCountedHandle_005C8300 &other) {
        func_0013BD50(this, &other);
    }
    ~RefCountedHandle_005C8300() { func_0013BD68(this, 2); }
    RefCountedHandle_005C8300 &operator=(const RefCountedHandle_005C8300 &other) {
        if (this != &other) {
            /* Retain first: distinct handles may refer to the same object. */
            void *incomingObject = other.object;
            if (incomingObject) func_003285A8(incomingObject);
            if (object) func_003285F8(object);
            object = incomingObject;
        }
        return *this;
    }
};

struct TypeInfo { const char *name; };
extern "C" void *func_005C1368();
extern "C" void *func_00326750(int, int, const char *);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void *func_005C5790(void *, const void *);
extern "C" bool func_005C97E0(const unsigned short *, const unsigned short *,
                             const unsigned short *, const unsigned short *);

template <class T>
class TaggedSequenceAllocator_005C8300 {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef TaggedSequenceAllocator_005C8300<U> other; };
    TaggedSequenceAllocator_005C8300() throw() {}
    TaggedSequenceAllocator_005C8300(const TaggedSequenceAllocator_005C8300 &) throw() {}
    template <class U> TaggedSequenceAllocator_005C8300(const TaggedSequenceAllocator_005C8300<U> &) throw() {}
    ~TaggedSequenceAllocator_005C8300() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return (T *)func_00326750(n * sizeof(T), 4,
                                 ((TypeInfo *)func_005C1368())->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, ((TypeInfo *)func_005C1368())->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct SequenceKey_005C8300 {
    vector<unsigned short, TaggedSequenceAllocator_005C8300<unsigned short> > values;
    SequenceKey_005C8300 &operator=(const SequenceKey_005C8300 &other) {
        if (this != &other) func_005C5790(this, &other);
        return *this;
    }
};

struct SequenceSortEntry_005C8300 {
    RefCountedHandle_005C8300 handle;
    SequenceKey_005C8300 key;
};
struct SequenceKeyLess_005C8300 {
    /* The original ABI forwards this byte; an empty comparator differs. */
    char state;
    bool operator()(const SequenceSortEntry_005C8300 &a,
                    const SequenceSortEntry_005C8300 &b) const {
        return func_005C97E0(a.key.values.begin(), a.key.values.end(), b.key.values.begin(), b.key.values.end());
    }
};
template void func_005C8300(SequenceSortEntry_005C8300 *, SequenceSortEntry_005C8300 *, SequenceKeyLess_005C8300);
