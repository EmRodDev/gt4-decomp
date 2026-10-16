/* compiler: ee-gcc2.96-stl */
/* Write garage handles back in forward/reverse float-key order.
   Reproduce with knowledge/recipes/sort_callers.py. Labels below bind
   existing game functions; object lifetimes use ordinary C++. */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct ScriptHandle_005C6428 {
    void *value;
    ScriptHandle_005C6428(const ScriptHandle_005C6428 &) __asm__("func_00309360");
    ~ScriptHandle_005C6428() __asm__("func_00309378");
    ScriptHandle_005C6428 &operator=(const ScriptHandle_005C6428 &other) {
        if (this != &other) {
            /* Retain first: two handles can reference the same object. */
            void *incomingObject = other.value;
            if (incomingObject) func_003285A8(incomingObject);
            if (value) func_003285F8(value);
            value = incomingObject;
        }
        return *this;
    }
};

struct GarageHandle_005C6428 : ScriptHandle_005C6428 {
    GarageHandle_005C6428() __asm__("func_00148030");
    GarageHandle_005C6428(const ScriptHandle_005C6428 &) __asm__("func_0013BDC0");
    GarageHandle_005C6428(const GarageHandle_005C6428 &) __asm__("func_0013BD50");
    ~GarageHandle_005C6428() __asm__("func_0013BD68");
    operator void *() const { return value; }
    GarageHandle_005C6428 &operator=(const GarageHandle_005C6428 &other) {
        ScriptHandle_005C6428::operator=(other);
        return *this;
    }
};

struct ScriptArrayHandle_005C6428 : ScriptHandle_005C6428 {
    ScriptArrayHandle_005C6428(const ScriptArrayHandle_005C6428 &) __asm__("func_002ED5A8");
    ~ScriptArrayHandle_005C6428() __asm__("func_002ED5C0");
    ScriptHandle_005C6428 &operator[](int) __asm__("func_002EFCE0");
};

struct TypeInfoName_005C6428 { const char *name; };
extern "C" TypeInfoName_005C6428 *func_005C9B90();
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_00326798(void *, unsigned int, int, const char *);
template<class T> struct TaggedSortAllocator_005C6428 {
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template<class U> struct rebind { typedef TaggedSortAllocator_005C6428<U> other; };
    TaggedSortAllocator_005C6428() {}
    TaggedSortAllocator_005C6428(const TaggedSortAllocator_005C6428 &) {}
    ~TaggedSortAllocator_005C6428() {}
    template<class U> TaggedSortAllocator_005C6428(const TaggedSortAllocator_005C6428<U> &) {}
    T *allocate(size_type count, const void * = 0) {
        return (T *)func_00326750(count * sizeof(T), 4, func_005C9B90()->name);
    }
    void deallocate(T *p, size_type count) {
        if (p) func_00326798(p, count * sizeof(T), 4, func_005C9B90()->name);
    }
    size_type max_size() const { return size_type(-1) / sizeof(T); }
    void construct(T *p, const T &value) { new(p) T(value); }
    void destroy(T *p) { p->~T(); }
};

struct GarageScore_005C6428 { GarageHandle_005C6428 handle; float score; };
typedef vector<GarageScore_005C6428, TaggedSortAllocator_005C6428<GarageScore_005C6428> > SortEntries_005C6428;
extern "C" void func_005C6428(ScriptArrayHandle_005C6428 array, SortEntries_005C6428 values, int ascending) {
    unsigned int count = values.size();
    for (unsigned int i = 0; i < count; ++i) {
        array[i] = values[ascending ? i : count - i - 1].handle;
    }
    /* The original ABI destroys both by-value parameters in this callee. */
}
