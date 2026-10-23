/* compiler: ee-gcc2.96-stl */
/* HCodeFrame::end: unwind the current script stack and restore the caller.
 * SGI vector cleanup comes from include/stl/stl_vector.h; layouts agree with
 * the matched hThread::beginCodeFrame source. Vector roles remain provisional. */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *HObject__tf(void);
extern const char stackAllocationName[] __asm__("D_0069E280");

struct TypeInfo {
    const char *name;
};

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

/* A script value owns a reference-counted runtime object. Its destructor is
 * shared with the rest of the ADHOC implementation. */
struct RefCounter;
struct HObject {
    RefCounter *object;
    ~HObject() __asm__("func_00309378");
};
template <> struct TypeTag<HObject> {
    static void *tf() { return HObject__tf(); }
};

// The two value vectors are destroyed in reverse order when leaving a frame.
struct HStack {
    vector<HObject, GameAlloc<HObject> > values;
    vector<HObject, GameAlloc<HObject> > temporaries;
    int unknown20;
    static void operator delete(void *p) {
        func_00326798(p, sizeof(HStack), 4, stackAllocationName);
    }
};

// Partial ABI views of the saved frame and running thread. The remaining thread
// state is outside this operation; code/ref/data/stack are saved by beginCodeFrame.
struct HCodeFrame {
    void *vtable;
    int code;
    RefCounter *ref;
    void *data;
    HStack *stack;
};
struct hThread {
    char state[0x20];
    int code;
    RefCounter *ref;
    void *data;
    HStack *stack;
};
extern "C" void func_003285F8(RefCounter *);

// Dispose of the callee's stack and restore the caller's execution context.
extern "C" void HCodeFrame__end(HCodeFrame *frame, hThread *thread) {
    delete thread->stack;
    thread->stack = frame->stack;
    thread->data = frame->data;
    func_003285F8(thread->ref);
    thread->ref = frame->ref;
    thread->code = frame->code;
}
