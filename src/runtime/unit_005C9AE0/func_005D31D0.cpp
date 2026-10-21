/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rep;
extern "C" char *strobe__toUpper(Rep *src) throw();
struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
    char *data() { return (char *)(this + 1); }
    char *grab() {
        if (sel)
            return strobe__toUpper(this);
        ++ref;
        return data();
    }
};

struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    Str(const Str &o) : p(o.rep()->grab()) {}
};

struct Pair {
    Str first;
    Str second;
    Pair(const Pair &o) : first(o.first), second(o.second) {}
};

struct LNode {
    LNode *next;
    LNode *prev;
    Pair v;
};

struct Iter {
    LNode *n;
    Iter() {}
    Iter(LNode *x) : n(x) {}
    Iter(const Iter &o) : n(o.n) {}
} __attribute__((aligned(16)));

static inline void advance(LNode *&p) { p = p->next; }
static inline bool neq(LNode *const &a, LNode *const &b) { return a != b; }

extern "C" void *func_00575E60(s32, s32);
inline void *operator new(unsigned int, void *p) { return p; }

static inline Iter insert(Iter pos, const Pair &x) {
    LNode *n = (LNode *)func_00575E60(0x10, 0x10);
    Pair *pv = &n->v;
    if (pv)
        new (pv) Pair(x);
    n->next = pos.n;
    n->prev = pos.n->prev;
    pos.n->prev->next = n;
    pos.n->prev = n;
    return Iter(n);
}

extern "C" void func_005D31D0(void *self, Iter *pos, LNode *first, LNode *last, int unused0) {
    for (; neq(first, last); advance(first)) {
        Iter r = insert(*pos, first->v);
    }
}
