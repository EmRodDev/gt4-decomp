struct E { int x, a, b; char pad[0x38]; };
struct S { char pad[0x84]; E *ents; char pad2[0x14]; unsigned short n; };
extern "C" unsigned func_00525FE0(S *s, int v) {
    unsigned short i;
    for (i = 0; i < (unsigned)s->n; i++) {
        E *e = (E *)(i * 0x44 + (unsigned)s->ents);
        if (v == e->a) return i;
        if (v == e->b) return i;
    }
    return 0xFFFE;
}
