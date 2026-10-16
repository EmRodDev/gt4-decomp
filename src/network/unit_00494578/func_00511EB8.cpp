struct N { char pad[8]; N *next; };
struct T { unsigned size; N *list; };
struct O { char pad[0x3C]; unsigned n; char pad2[8]; T *tbl; };
struct A { char pad[0x18]; O *o; int pad1c; int f20; N *f24; };
extern "C" int func_00511EB8(A *a, unsigned *pidx) {
    O *o = a->o;
    unsigned base = 0;
    unsigned count = o->n;
    unsigned i = 0;
    unsigned size = 0;
    for (; i < count; i++) {
        size = o->tbl[i].size;
        if (*pidx < base + size) break;
        base += size;
    }
    if (*pidx >= base + size) {
        a->f24 = 0;
        return 4;
    }
    N *n = o->tbl[i].list;
    while (n) {
        if (base == *pidx) break;
        n = n->next;
        base++;
    }
    if (n == 0) return 7;
    a->f20 = i;
    a->f24 = n;
    return 0;
}
