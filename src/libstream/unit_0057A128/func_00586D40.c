/* compiler: ee-gcc2.9-991111 */
typedef struct N { char pad[8]; struct N *f8; struct N *fC; } N;

int func_00586D40(N *a, N *b) {
    N *t = a->fC;
    N *p;
    N *c;
    if (t == b) {
        b->f8 = a;
        a->fC = b->fC;
        return 1;
    }
    p = t;
    c = p->fC;
    if (c != 0) {
        N *next;
        do {
        if (c == b) {
            c->f8 = a;
            p->fC = c->fC;
            c->fC = 0;
            return 1;
        }
        p = c;
        next = c->fC;
        c = next;
        } while (next != 0);
    }
    return 0;
}
