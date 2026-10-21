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
struct Set { char pad[0x1C]; Node *list; };
struct Pred { Set *set; Obj *obj; };

static inline s32 check(Pred *pr, Val *v) {
    Obj *o = pr->obj;
    Entry *e = (Entry *)(o->vt + 0x10);
    s32 hit = e->fn((char *)o + e->delta, v);
    if (hit) {
        Node *l = pr->set->list;
        bool c = false;
        if (l->next != l)
            c = (u32)l->prev->v.p != 0;
        if (c) {
            Target *t = v->p;
            Entry2 *g = (Entry2 *)(t->vt + 0x190);
            g->fn((char *)t + g->delta);
        }
    }
    return hit;
}

extern "C" void func_005DD518(List *self, Pred *pr) {
    Iter first (self->head->next);
    Iter last (self->head);
    while (first != last) {
        Iter next = first;
        ++next;
        if (check(pr, &*first))
            erase(first);
        first.n = next.n;
    }
}
