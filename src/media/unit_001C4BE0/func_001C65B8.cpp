/* compiler: ee-gcc2.96-stl */
/* Fetches entry 'index' from the table built by Body (a container read through func_001D1038/001D1340): returns -1 on any failure, a bad flag (bit 2 of the 16-bit flags at +0x48 of the entry) or when the payload does not fit 'capacity'; otherwise it copies the payload (func_005A4724) into the buffer at self+0xBD0 and returns its length. If self+0x1DD8 is set it delegates to func_001C6A10 instead. The class names D_006xxxxx are the original's vtable symbols used as type names; the container type is not determined. */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
extern "C" void free(void *) throw();
extern "C" void func_001CC060(void *, s32);
extern "C" void func_001D11D0(void *, s32);
extern "C" void *func_001D16E0(void *, s32);
extern "C" s32 func_001C6A10(void *, s32, s32);
extern "C" s32 func_001CC528(void *, void *);
extern "C" s32 func_001D0CC0(void *, void *, s32, s32);
extern "C" s32 func_001D1038(void *, void *, s32, s32);
extern "C" void *func_001D1340(void *, s32, void *);
extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern char D_00660CD8[];

template <class T>
class PlainAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef PlainAlloc<U> other; };
    PlainAlloc() throw() {}
    PlainAlloc(const PlainAlloc &) throw() {}
    template <class U> PlainAlloc(const PlainAlloc<U> &) throw() {}
    ~PlainAlloc() throw() {}
    T *allocate(size_type n, const void * = 0);
    void deallocate(T *p, size_type n) { free(p); }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
};

struct func_001CBFE0 {
    char data[0x4C];
    func_001CBFE0();
    ~func_001CBFE0() __asm__("func_001CC060");
    virtual void update();
};
struct D_006614F8 : func_001CBFE0 {
    virtual void update();
};
struct D_00661B70 : D_006614F8 {
    char *p50;
    D_00661B70() : p50(0) { func_001D11D0(this, 0); }
    virtual void update();
};
struct D_006611F0 : D_006614F8 {
    vector<char, PlainAlloc<char> > list;
    int x60;
    D_006611F0() : x60(0) {}
    virtual void update();
};
struct D_00661758 : D_006611F0 {
    char pad[0x150 - 0x64];
    vector<char, PlainAlloc<char> > list2;
    virtual void update();
};

struct Body {
    char *vt;
    char pad[0xC90 - 4];
    s32 count;
    Body(s32 v) { func_001D16E0(this, v); count = 0; }
    ~Body() { vt = D_00660CD8; }
};
struct G { char pad[0x39E28]; s32 f39E28; };
extern G *D_00622F4C;
struct Ctx { char pad[0xBD0]; char *fBD0; char pad2[0x1DD8 - 0xBD4]; s32 f1DD8; };

extern "C" s32 func_001C65B8(Ctx *self, s32 index, s32 capacity) {
    if (self->f1DD8) return func_001C6A10(self, index, capacity);
    Body body(D_00622F4C->f39E28);
    char *entryTable = (char *)&body + 0x10;
    D_00661B70 headerParser;
    headerParser.p50 = entryTable;
    if (__builtin_expect(func_001D1038(&headerParser, &body, 0, 0), 0)) return -1;
    s32 length = -1;
    if (index < body.count) {
        D_00661758 entry;
        if (func_001D1340(entryTable, index, entry.data + 0x24)) {
            if (!func_001CC528(&entry, &body)) return -1;
            unsigned entryFlags = *(unsigned short *)(entry.data + 0x48);
            if ((entryFlags >> 2) & 1) return -1;
            if (__builtin_expect(func_001D0CC0(&entry, &body, 0, 0), 0)) return -1;
            length = entry.list2.end() - entry.list2.begin();
            if (length < capacity) func_005A4724(self->fBD0, entry.list2.begin(), length);
            else length = -1;
        }
    }
    return length;
}
