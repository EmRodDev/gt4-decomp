/* compiler: ee-gcc2.96-stl */
/* Write garage handles back in forward/reverse string-key order.
   Reproduce with knowledge/recipes/sort_callers.py. Labels below bind
   existing game functions; object lifetimes use ordinary C++. */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct ScriptHandle_005C6BF0 {
    void *value;
    ScriptHandle_005C6BF0(const ScriptHandle_005C6BF0 &) __asm__("func_00309360");
    ~ScriptHandle_005C6BF0() __asm__("func_00309378");
    ScriptHandle_005C6BF0 &operator=(const ScriptHandle_005C6BF0 &other) {
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

struct GarageHandle_005C6BF0 : ScriptHandle_005C6BF0 {
    GarageHandle_005C6BF0() __asm__("func_00148030");
    GarageHandle_005C6BF0(const ScriptHandle_005C6BF0 &) __asm__("func_0013BDC0");
    GarageHandle_005C6BF0(const GarageHandle_005C6BF0 &) __asm__("func_0013BD50");
    ~GarageHandle_005C6BF0() __asm__("func_0013BD68");
    operator void *() const { return value; }
    GarageHandle_005C6BF0 &operator=(const GarageHandle_005C6BF0 &other) {
        ScriptHandle_005C6BF0::operator=(other);
        return *this;
    }
};

struct ScriptArrayHandle_005C6BF0 : ScriptHandle_005C6BF0 {
    ScriptArrayHandle_005C6BF0(const ScriptArrayHandle_005C6BF0 &) __asm__("func_002ED5A8");
    ~ScriptArrayHandle_005C6BF0() __asm__("func_002ED5C0");
    ScriptHandle_005C6BF0 &operator[](int) __asm__("func_002EFCE0");
};

struct TypeInfoName_005C6BF0 { const char *name; };
extern "C" TypeInfoName_005C6BF0 *func_005C9BD0();
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_00326798(void *, unsigned int, int, const char *);
template<class T> struct TaggedSortAllocator_005C6BF0 {
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template<class U> struct rebind { typedef TaggedSortAllocator_005C6BF0<U> other; };
    TaggedSortAllocator_005C6BF0() {}
    TaggedSortAllocator_005C6BF0(const TaggedSortAllocator_005C6BF0 &) {}
    ~TaggedSortAllocator_005C6BF0() {}
    template<class U> TaggedSortAllocator_005C6BF0(const TaggedSortAllocator_005C6BF0<U> &) {}
    T *allocate(size_type count, const void * = 0) {
        return (T *)func_00326750(count * sizeof(T), 4, func_005C9BD0()->name);
    }
    void deallocate(T *p, size_type count) {
        if (p) func_00326798(p, count * sizeof(T), 4, func_005C9BD0()->name);
    }
    size_type max_size() const { return size_type(-1) / sizeof(T); }
    void construct(T *p, const T &value) { new(p) T(value); }
    void destroy(T *p) { p->~T(); }
};

struct GarageStringKey_005C6BF0 { GarageHandle_005C6BF0 handle; const char *key; };
typedef vector<GarageStringKey_005C6BF0, TaggedSortAllocator_005C6BF0<GarageStringKey_005C6BF0> > SortEntries_005C6BF0;
extern "C" void func_005C6BF0(ScriptArrayHandle_005C6BF0 array, SortEntries_005C6BF0 values, int ascending) {
    unsigned int count = values.size();
    for (unsigned int i = 0; i < count; ++i) {
        array[i] = values[ascending ? i : count - i - 1].handle;
    }
    /* The original ABI destroys both by-value parameters in this callee. */
}
