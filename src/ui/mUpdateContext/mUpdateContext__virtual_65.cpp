/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { int a; short b; int c; int d; };
struct Ctx {
    char pad[0x24];
    int a[2];
    int b[2][4];
    E e[2];
    int c[2];
    short s74[2];
    short s78[2];
    char g[2][2];
    int h[2][2];
    char k[2][2];
    short s94[2];
    int n[2];
};

extern "C" void mUpdateContext__virtual_65(Ctx *s) {
    for (int i = 0; i < 2; i++) {
        s->a[i] = 0x200000;
        s->b[i][0] = 0;
        s->b[i][1] = 0;
        s->b[i][2] = 0;
        s->b[i][3] = 0;
        E *e = &s->e[i];
        e->a = 0;
        e->b = 0;
        e->c = 0;
        e->d = 0;
        s->c[i] = 0;
        s->s74[i] = 0;
        s->s78[i] = 0;
        s->g[i][0] = 0;
        s->g[i][1] = 0;
        s->h[i][0] = 0;
        s->h[i][1] = 0;
        s->k[i][0] = -1;
        s->k[i][1] = -1;
        s->s94[i] = 0;
        s->n[i] = 0;
    }
}
