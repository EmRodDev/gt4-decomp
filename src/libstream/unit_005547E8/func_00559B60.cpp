/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Dst { int mode; int pad4; int count; int extra; int vol; };
extern char D_00655340[];
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void func_00559B60(Dst *d, char *s) {
    func_00576100(D_00655340);
    if (*(int *)(s + 0x7C) != 0) d->mode = 3;
    else d->mode = 4;
    int *p = (int *)(s + 0x10);
    int none = -1;
    for (int i = 5; i >= 0; i--, p++) {
        int off = p[0];
        p[8] = 0;
        if (off != none) p[8] = off + (int)s;
    }
    *(char **)((char *)d + 0x14) = s;
    d->count = 0;
    int n = *(int *)(s + 0x34);
    if (n) d->count = n + 2;
    d->extra = 0;
    int e = *(int *)(s + 0x38);
    if (e) d->extra = e;
    d->vol = 0x7F;
    func_00576140(D_00655340);
}
