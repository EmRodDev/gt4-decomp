/* compiler: ee-gcc2.96-stl */
/* Saves a game-data block with progress feedback: the local Loc object reports progress (steps 0.0, 0.5, 1.0 through a virtual call). It first runs func_001CE868 on the global state (D_00622F4C+0xBC30) with a counter+1, then asks the global object for its data size (vtable +0x10), copies the data (vtable +0x28) into a 0x40-aligned vector at +8, encrypts it with func_001D4D10 and writes it with func_001CCEC8 while a second progress object (Loc2, 0.5..1.0) tracks the write. Returns the write comparison (r == 0) or the early error. Reading it as save/encrypt is inferred from the call order (copy, encrypt, write). */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;
extern "C" void func_00575DA0(int p) throw();
extern "C" void *func_00575E60(int heap, int size);

template <class T>
class PlainAlloc40 {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef PlainAlloc40<U> other; };
    PlainAlloc40() throw() {}
    PlainAlloc40(const PlainAlloc40 &) throw() {}
    template <class U> PlainAlloc40(const PlainAlloc40<U> &) throw() {}
    ~PlainAlloc40() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x40, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        func_00575DA0((int)p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};


struct Ent { short off; short pad; void (*fn)(void *, float); };
struct VT { char p[0x10]; Ent e; };
extern VT D_00661718;
extern VT D_00661738;
extern VT D_0065CE00;
struct LocBase {
    VT *vptr;
    LocBase() { vptr = &D_0065CE00; }
    ~LocBase() { vptr = &D_0065CE00; }
};
struct Loc : LocBase {
    int f4;
    Loc(int a) { vptr = &D_00661718; f4 = a; }
    ~Loc() { vptr = &D_00661718; }
    void step(float f) { Ent *e = &vptr->e; e->fn((char *)this + e->off, f); }
};
struct Loc2 : LocBase {
    Loc *owner;
    float a;
    float b;
    Loc2(Loc *o, float x, float y) { vptr = &D_00661738; owner = o; a = x; b = y; }
    ~Loc2() { vptr = &D_00661738; }
};
struct VEntB { short off; short pad; s32 (*fn)(void *, void *); };
struct VEntC { short off; short pad; s32 (*fn)(void *); };
struct Gv { char *vtbl; };
extern char *D_00622F4C;
struct Result { int value; };
static inline int status(const Result *const x) { return x->value; }
extern "C" Result func_001CE868(void *, void *, void *, s32, s32);
extern "C" s32 func_001CCEC8(void *, void *, void *, s32, void *) throw();
extern "C" void func_001D4D10(void *, float, s32, float, u32, s32);

extern "C" s32 func_001CE020(void *context, void *channel, s32 arg2, s32 progressId) {
    Loc progress(progressId);
    progress.step(0.0f);
    char *state = D_00622F4C + 0xBC30;
    progress.step(0.5f);
    s32 cnt = *(s32 *)(state + 0x81E0) + 1;
    Result prepared = func_001CE868(context, channel, state, cnt != 0 ? cnt : 1, 1);
    if (status(&prepared)) return prepared.value;
    Gv *globalObj = (Gv *)D_00622F4C;
    VEntC *sizeSlot = (VEntC *)(globalObj->vtbl + 0x10);
    s32 dataSize = sizeSlot->fn((char *)globalObj + sizeSlot->off);
    vector<char, PlainAlloc40<char> > blob((size_t)((dataSize + 0x47) & ~0x3F));
    Gv *globalObj2 = (Gv *)D_00622F4C;
    VEntB *copySlot = (VEntB *)(globalObj2->vtbl + 0x28);
    char *blobData = blob.begin();
    copySlot->fn((char *)globalObj2 + copySlot->off, blobData + 8);
    func_001D4D10(blobData, 0x1.161910p-3f, dataSize, 0x1.4f49cep-1f, 0, 0);
    Loc2 writeProgress(&progress, 0.5f, 1.0f);
    s32 writeResult = func_001CCEC8(context, channel, blob.begin(), blob.size(), &writeProgress);
    *(s32 *)(state + 0x81E0) = cnt;
    progress.step(1.0f);
    return writeResult == 0;
}
