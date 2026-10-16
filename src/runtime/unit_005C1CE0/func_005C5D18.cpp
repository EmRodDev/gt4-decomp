/* compiler: ee-gcc2.96-stl */
/* Calculate callback scores, sort, and write garage handles back.
   Reproduce with knowledge/recipes/sort_callers.py. Labels below bind
   existing game functions; object lifetimes use ordinary C++. */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
#include <stl_function.h>
#include <stl_tempbuf.h>
#include <stl_heap.h>
#include <stl_algo.h>
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct ScriptHandle_005C5D18 {
    void *value;
    ScriptHandle_005C5D18(const ScriptHandle_005C5D18 &) __asm__("func_00309360");
    ~ScriptHandle_005C5D18() __asm__("func_00309378");
    ScriptHandle_005C5D18 &operator=(const ScriptHandle_005C5D18 &other) {
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

struct GarageHandle_005C5D18 : ScriptHandle_005C5D18 {
    GarageHandle_005C5D18() __asm__("func_00148030");
    GarageHandle_005C5D18(const ScriptHandle_005C5D18 &) __asm__("func_0013BDC0");
    GarageHandle_005C5D18(const GarageHandle_005C5D18 &) __asm__("func_0013BD50");
    ~GarageHandle_005C5D18() __asm__("func_0013BD68");
    operator void *() const { return value; }
    GarageHandle_005C5D18 &operator=(const GarageHandle_005C5D18 &other) {
        ScriptHandle_005C5D18::operator=(other);
        return *this;
    }
};

struct GarageScore_005C5D18;
struct ScoredHandle_005C5D18 {
    ScriptHandle_005C5D18 handle;
    float score;
    ScoredHandle_005C5D18(const ScriptHandle_005C5D18 &object, const float &number) : handle(object), score(number) {}
    operator GarageScore_005C5D18() const;
};

struct GarageScore_005C5D18 {
    GarageHandle_005C5D18 handle;
    float score;
    GarageScore_005C5D18() : handle(), score(0) {}
    GarageScore_005C5D18(const ScoredHandle_005C5D18 &other) : handle(other.handle), score(other.score) {}
    GarageScore_005C5D18(const GarageScore_005C5D18 &other) : handle(other.handle), score(other.score) {}
    GarageScore_005C5D18 &operator=(const GarageScore_005C5D18 &other) {
        handle = other.handle;
        score = other.score;
        return *this;
    }
};
inline ScoredHandle_005C5D18::operator GarageScore_005C5D18() const { return GarageScore_005C5D18(*this); }
struct ScriptArrayHandle_005C5D18 : ScriptHandle_005C5D18 {
    ScriptArrayHandle_005C5D18(const ScriptArrayHandle_005C5D18 &) __asm__("func_002ED5A8");
    ~ScriptArrayHandle_005C5D18() __asm__("func_002ED5C0");
    ScriptHandle_005C5D18 &operator[](int) __asm__("func_002EFCE0");
};

struct TypeInfoName_005C5D18 { const char *name; };
extern "C" TypeInfoName_005C5D18 *func_005C9B90();
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_00326798(void *, unsigned int, int, const char *);
extern "C" unsigned int hArray__size(void *);
extern "C" void *func_00147D80(void *);
/* The input has three 64-bit words; their meanings remain unidentified. */
struct SortCallbackInput { long long words[3]; };
/* The record selector returns a cell containing a full 64-bit database id. */
extern "C" const long long *func_00441248(void *);
extern "C" long long func_004454C0(const long long *);
extern "C" int func_00448820(long long rowId, SortCallbackInput *);
typedef int (*ScoreCallback)(const SortCallbackInput &);
template<class T> struct TaggedSortAllocator_005C5D18 {
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template<class U> struct rebind { typedef TaggedSortAllocator_005C5D18<U> other; };
    TaggedSortAllocator_005C5D18() {}
    TaggedSortAllocator_005C5D18(const TaggedSortAllocator_005C5D18 &) {}
    ~TaggedSortAllocator_005C5D18() {}
    template<class U> TaggedSortAllocator_005C5D18(const TaggedSortAllocator_005C5D18<U> &) {}
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
inline bool operator<(const GarageScore_005C5D18 &left,
                      const GarageScore_005C5D18 &right) {
    return left.score < right.score;
}
typedef GarageScore_005C5D18 SortEntry;
typedef less<SortEntry> AscendingScore_005C5D18;
typedef vector<SortEntry, TaggedSortAllocator_005C5D18<SortEntry> > SortEntries_005C5D18;

template<> SortEntry *__uninitialized_fill_n_aux<SortEntry *, size_t, SortEntry>(
    SortEntry *, size_t, const SortEntry &, __false_type) __asm__("func_005C6578");
template<> SortEntry *__uninitialized_copy_aux<const SortEntry *, SortEntry *>(
    const SortEntry *, const SortEntry *, SortEntry *, __false_type) __asm__("func_005C6800");
template<> void __introsort_loop<SortEntry *, SortEntry, ptrdiff_t, AscendingScore_005C5D18>(
    SortEntry *, SortEntry *, SortEntry *, ptrdiff_t, AscendingScore_005C5D18)
    __asm__("func_005C65E0");
template<> void __final_insertion_sort<SortEntry *, AscendingScore_005C5D18>(
    SortEntry *, SortEntry *, AscendingScore_005C5D18) __asm__("func_005C6780");

extern "C" void func_005C6428(ScriptArrayHandle_005C5D18, SortEntries_005C5D18, int);
static inline ScoredHandle_005C5D18 makeScoredHandle(
    const ScriptHandle_005C5D18 &object, const float &score) {
    return ScoredHandle_005C5D18(object, score);
}
extern "C" void func_005C5D18(ScriptArrayHandle_005C5D18 array, int ascending, ScoreCallback score) {
    SortEntries_005C5D18 values(hArray__size(array.value));
    for (unsigned int i = 0; i < values.size(); ++i) {
        SortCallbackInput input;
        /* Keep the temporary garage handle alive until the input is read. */
        func_00448820(func_004454C0(func_00441248(
            func_00147D80(GarageHandle_005C5D18(array[i])))), &input);
        values[i] = makeScoredHandle(array[i], (float)score(input));
    }
    sort(values.begin(), values.end(), AscendingScore_005C5D18());
    func_005C6428(array, values, ascending);
}
