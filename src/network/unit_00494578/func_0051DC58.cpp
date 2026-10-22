struct C { int f0; char pad4[4]; int f8; };
struct O { int f0; char pad4[4]; unsigned f8; char pad[0x6C]; C *f78[2]; int f80; };
extern "C" int func_0051DDC0(void *);
extern "C" int func_0051DC58(O *o) {
    int kc = 2;
    if (o == 0) return 0;
    if (o->f8 < kc) {
        return 0;
    }
    int r = func_0051DDC0((void *)o->f80);
    if (r != 0) {
        unsigned i = 0;
        C **p = o->f78;
        do {
            C *c = *p;
            p++;
            if (c != 0) {
                if (o->f0 != c->f8) return 0;
                r = func_0051DDC0(c);
                if (r == 0) return r;
            }
            i++;
        } while (i < kc);
        return 1;
    }
    return r;
}
