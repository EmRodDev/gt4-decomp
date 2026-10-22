/* compiler: ee-gcc2.96-stl */
#include <stl_tree.h>
#include <stl_set.h>

typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};
struct HeapName {
    const char *name;
};

extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" HeapName *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void *func_005DEAC8(void);
extern Rep D_00659FA8;
extern char D_00699BC0[];
extern char D_00699BC8[];
extern char D_00699BD8[];
extern char D_00699BE0[];
extern char D_00699BF0[];
extern char D_00699BF8[];
extern unsigned char _ctype_[];

/* the game's string: libstdc++ v2 basic_string */
struct Str;
extern "C" Str *func_005C2630(Str *self, unsigned int pos, unsigned int n1, const char *s, unsigned int n2);
extern "C" Str *func_005CE388(Str *self, unsigned int pos1, unsigned int n1, const Str *str, unsigned int pos2, unsigned int n2);
struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    static char *data(Rep *r) { return (char *)(r + 1); }
    static char *grab(Rep *r) {
        if (r->sel) return func_005C2560(r);
        ++r->ref;
        return data(r);
    }
    s32 length() const { return rep()->len; }
    void terminate() const { data(rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0) return D_00699BC0;
        terminate();
        return data(rep());
    }
    char operator[](s32 pos) const {
        if (pos == length()) return 0;
        return data(rep())[pos];
    }
    Str(const Str &s) : p(grab(s.rep())) {}
    Str(const char *s) : p(grab(&D_00659FA8)) { func_005C2630(this, 0, (unsigned int)-1, s, func_0057F260(s)); }
    Str(const Str &s, s32 pos, s32 n) : p(grab(&D_00659FA8)) { func_005CE388(this, 0, (unsigned int)-1, &s, pos, n); }
    ~Str() {
        Rep *q = rep();
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
};

struct TypeInfo {
    const char *name;
};
template <class T> struct TypeTag;

/* the game's allocator: every block is tagged with the name of its type */
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

struct HSymID {
    unsigned int id;
    HSymID(unsigned int v) : id(v) {}
    HSymID(const HSymID &o) : id(o.id) {}
    HSymID &operator=(const HSymID &o) {
        if (this != &o) id = o.id;
        return *this;
    }
    bool operator<(const HSymID &o) const { return id < o.id; }
};
typedef _Rb_tree_node<HSymID> Node;
template <> struct TypeTag<Node> { static void *tf() { return func_005DEAC8(); } };
typedef _Rb_tree<HSymID, HSymID, _Identity<HSymID>, less<HSymID>, GameAlloc<HSymID> > Tree;
typedef set<HSymID, less<HSymID>, GameAlloc<HSymID> > Set;
extern "C" Tree::const_iterator func_005DDC38(const Tree *, const HSymID &);
extern "C" pair<Tree::iterator, bool> func_005DDAC0(Tree *, const HSymID &);
extern "C" void func_005DDA50(Tree *, Node *);
template <> inline Tree::const_iterator Tree::find(const HSymID &k) const { return func_005DDC38(this, k); }
template <> inline pair<Tree::iterator, bool> Tree::insert_unique(const HSymID &v) { return func_005DDAC0(this, v); }
template <> inline void Tree::_M_erase(Node *x) { func_005DDA50(this, x); }

extern "C" unsigned int HSymID__GetID(const Str &);

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};
struct Face {
    s32 pad;
    char *vt;
};
extern "C" Face *func_0025C2A0(Face *);
extern "C" Face *func_00206868(Face *);
extern "C" Face *func_0025C300(Face *);
extern "C" HSymID *func_00305548(Face *);
extern "C" void func_005D4AD8(const char *, ...);
extern "C" void func_0057DA20(char *, const char *, ...) throw();
extern "C" char *func_005A609C(char *, const char *);

extern "C" HSymID func_0025ADF8(Face *self, const Str &name) {
    HSymID id = HSymID__GetID(name);
    Face *root = func_0025C2A0(self);
    if (root == 0) return id;
    Set used;
    VEntry *e = (VEntry *)(root->vt + 0x1B0);
    if (e->fn((char *)root + e->delta)) {
        for (Face *p = func_00206868(root); p != 0; p = func_0025C300(p)) {
            if (p != self) used.insert(*func_00305548(p));
        }
    }
    Set::iterator it = used.find(id);
    if (it != used.end()) {
        func_005D4AD8(D_00699BC8, name.c_str());
        s32 i;
        for (i = name.length() - 1; i >= 0 && (_ctype_ + 1)[name[i]] & 4; i--)
            func_005D4AD8(D_00699BD8, name[i]);
        Str base(name, 0, i + 1);
        func_005D4AD8(D_00699BE0, base.c_str());
        char buf[512];
        func_005A609C(buf, name.c_str());
        i = 0;
        for (;;) {
            id = HSymID(HSymID__GetID(Str(buf)));
            it = used.find(id);
            if (it == used.end()) goto done;
            func_0057DA20(buf, D_00699BF0, base.c_str(), i++);
        }
    done:
        func_005D4AD8(D_00699BF8, buf);
    }
    return id;
}
