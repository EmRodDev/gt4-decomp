struct V { int f0; char p4[4]; int f8; };
struct Obj { char p[0x3C]; int f3C, f40; unsigned int f44; char p48[4]; void *f4C, *f50, *f54; char p58[0xC]; V *f64; };
struct T { int f0, f4; unsigned int f8; void *fC, *f10, *f14; };
struct U { int f0, f4; };
extern "C" int func_00511050(Obj *o, T *t, U *u) {
    int ret = 1;
    if (o != 0) {
        if (t != 0) {
            void *e = o->f50;
            void *d = o->f4C;
            void *f = o->f54;
            t->f0 = o->f3C;
            t->f4 = o->f40;
            t->f10 = e;
            t->fC = d;
            t->f14 = f;
            t->f8 = o->f44;
        }
        if (u != 0) {
            V *v = o->f64;
            u->f4 = v->f8;
            u->f0 = v->f0;
        }
        ret = 0;
    }
    return ret;
}
