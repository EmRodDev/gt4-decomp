struct N { char pad[8]; N *next; };
struct E { int f0; N *f4; };
struct O { char pad[0x3C]; unsigned n; char pad40[8]; E *tbl; char pad4C[0x10]; int f5C_; };
struct P { char pad[0x3C]; unsigned n; char pad40[8]; E *tbl; char pad4C[0xC]; int f58; int f5C; char pad60[4]; int f64; int pad68; P *f6C; };
extern "C" int func_00512350(int, N *);
extern "C" int func_00511648(P *p) {
    if (p != 0) {
        unsigned i;
        if (p->f6C != 0) func_00511648(p->f6C);
        i = 0;
        if (p->n != 0) {
            do {
                N *a = p->tbl[i].f4;
                if (a != 0) {
                    N *s = a->next;
                    for (;;) {
                        func_00512350(p->f64, a);
                        a = s;
                        if (a == 0) break;
                        s = a->next;
                    }
                }
                p->tbl[i].f0 = 0;
                p->tbl[i].f4 = 0;
                i++;
            } while (i < p->n);
        }
        p->f58 = 0;
        p->f5C = 0;
    }
    return 0;
}
