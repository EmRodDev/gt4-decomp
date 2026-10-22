/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-slot camera update: 6 slots of 0x19C bytes start at self + 0x10. The two "activate" blocks
 * store the slot's target at slot + 0x13C through a running slot pointer and pass the int at
 * self + idx * 0x19C + 0x194 through a separate offset, as in the sibling func_00376F20. */
struct Tgt { char *vt; };
struct Obj { char *vt; };
struct Entry { short delta, index; Tgt *(*fn)(void *, int); };
struct IntEnt { short delta, index; int (*fn)(void *); };
struct VoidEnt { short delta, index; void (*fn)(void *, char *, int); };
struct Out { int a, b; float c; };
extern "C" void func_003FC4F0(char *, int);
extern "C" int func_003FD620(char *, char *, char *, int, int *);
extern "C" void func_00377898(Obj *, char *, char *, int, unsigned, Out *);
extern "C" void func_00377968(Obj *, char *, char *, int, unsigned, Out *);
extern "C" void func_00377170(Obj *, char *, char *, int, unsigned, Out *, int);
extern "C" void func_00378F28(Tgt *, char *, char *, char *, char *);
static inline Tgt *get(Obj *self, int idx) {
    Entry *e = (Entry *)(self->vt + 0xD8);
    return e->fn((char *)self + e->delta, idx);
}
static inline int query(Tgt *t, int off) {
    IntEnt *e = (IntEnt *)(t->vt + off);
    return e->fn((char *)t + e->delta);
}
extern "C" void func_00374E90(Obj *self, char *ctx, char *other, int idx, unsigned flags, Out *out) {
    int buf[4];
    int state = 1;
    char *base = (char *)self + idx * 0x19C;
    char *p = base + 0x10;
    char *fp = base + 0xE0;
    int n = *(int *)(p + 0x18C);
    if (n >= 0) {
        flags |= 2;
        func_003FC4F0(p, n);
        out->b = 1;
    }
    switch (func_003FD620(ctx, other, p, 0, buf)) {
    case 1: func_00377898(self, ctx, other, idx, flags, out); break;
    case 2: func_00377968(self, ctx, other, idx, flags, out); break;
    case 4:
        state = 2;
        func_00377170(self, ctx, other, idx, flags, out, 1);
        break;
    case 5: {
        Tgt *t = *(Tgt **)(p + 0x17C);
        VoidEnt *e = (VoidEnt *)(t->vt + 0x138);
        e->fn((char *)t + e->delta, ctx, buf[0]);
        *(Tgt **)(p + 0x12C) = t;
        break;
    }
    default: {
        Tgt *t = get(self, idx);
        int hit = t == *(Tgt **)(p + 0x158);
        if (t == *(Tgt **)(p + 0x14C)) {
            hit = 1;
            out->c = 0.5f;
        }
        if (hit) flags |= 2;
        break;
    }
    }
    if (flags & 2) {
        Tgt *t = *(Tgt **)(p + 0x148);
        char *slot = (char *)self;
        slot += idx * 0x19C;
        *(Tgt **)(slot + 0x13C) = t;
        int off = idx * 0x19C + 0x194;
        VoidEnt *e = (VoidEnt *)(t->vt + 0x140);
        e->fn((char *)t + e->delta, p, *(int *)((char *)self + off));
        out->a = 1;
    }
    char *tail = (char *)self + 0x9C0;
    func_00378F28(get(self, idx), ctx, fp, p, tail);
    if ((query(get(self, idx), 0xA0) ^ 3) == 0 && state != 2) {
        Tgt *t = *(Tgt **)(p + 0x148);
        char *slot = (char *)self;
        slot += idx * 0x19C;
        *(Tgt **)(slot + 0x13C) = t;
        int off = idx * 0x19C + 0x194;
        VoidEnt *e = (VoidEnt *)(t->vt + 0x140);
        e->fn((char *)t + e->delta, p, *(int *)((char *)self + off));
        func_00378F28(t, ctx, fp, p, tail);
        out->a = 1;
    }
    Tgt *last = *(Tgt **)(p + 0x148);
    Tgt *cur = get(self, idx);
    if (cur == last) {
        int value = query(cur, 0xB8);
        *(int *)(idx * 0x19C + (char *)self + 0x194) = value;
    }
}
