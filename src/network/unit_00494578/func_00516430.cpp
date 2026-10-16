struct H { char pad[0x104]; unsigned f104; };
struct E { char pad[8]; int base, n; };
struct G { char pad[0x118]; H *h; };
extern G D_00854038;
extern "C" E *func_0051B8A8(H *, unsigned);
extern "C" int func_00516430(void) {
    G *g = &D_00854038;
    H *h = g->h;
    if (h == 0) return -1;
    {
        E *e = func_0051B8A8(h, h->f104);
        if (e == 0) return -1;
        {
            for (int i = 0; i < e->n; i++) {
                int idx = i + e->base;
                if (*((signed char *)g + idx + 0xE638) != 2) return idx;
            }
        }
    }
    return -1;
}
