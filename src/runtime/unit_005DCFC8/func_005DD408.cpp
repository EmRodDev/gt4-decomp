/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Entry { short delta, index; s32 (*fn)(void *, void *); };
struct Entry2 { short delta, index; s32 (*fn)(void *); };
struct Target { s32 pad0; char *vt; };
struct Val {
    Target *p;
    ~Val() __asm__("func_0028E378");
};
struct Node {
    Node *next;
    Node *prev;
    Val v;
};
struct Heap { const char *name; };
extern "C" Heap *func_005DD7F0(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

struct Iter {
    Node *n;
    Iter() {}
    Iter(Node *x) : n(x) {}
    Iter(const Iter &o) : n(o.n) {}
    Iter &operator=(const Iter &o) { n = o.n; return *this; }
    Val &operator*() const { return n->v; }
    Iter &operator++() { n = n->next; return *this; }
    bool operator!=(const Iter &o) const { return n != o.n; }
} __attribute__((aligned(16)));

static inline Iter erase(Iter pos) {
    Node *p = pos.n;
    Node *next = p->next;
    Node *prev = p->prev;
    prev->next = next;
    next->prev = prev;
    pos.n->v.~Val();
    Node *q = pos.n;
    func_00326798(q, 0xC, 4, func_005DD7F0()->name);
    return Iter(next);
}

struct List { s32 pad0; Node *head; };
struct Obj { char *vt; };
struct Fn {
    Obj *o;
    s32 operator()(Val *v) const {
        Entry *e = (Entry *)(o->vt + 0x10);
        return e->fn((char *)o + e->delta, v);
    }
};

extern "C" void func_005DD408(List *self, Fn fn) {
    Iter first (self->head->next);
    Iter last (self->head);
    while (first != last) {
        Iter next = first;
        ++next;
        if (fn(&*first))
            erase(first);
        first.n = next.n;
    }
}
