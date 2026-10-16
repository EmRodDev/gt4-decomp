/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cfg { char p[0x10]; int *a10; int a14; };
struct W { int a0; char p[0xc]; int *a10; int a14; char p1[0xf8]; float k; };
extern "C" int func_00402270(int, int) throw();
extern "C" float *func_00385B48(int);
extern "C" float *func_00385BA8(int);
extern "C" float *func_00385DC8(int);
static inline float fmaxs(float a, const float &b) { float r; __asm__("max.s %0,%1,%2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float fmins(float a, const float &b) { float r; __asm__("min.s %0,%1,%2" : "=f"(r) : "f"(a), "f"(b)); return r; }
struct Lin { float m, c; float eval(float x) const { return m*x+c; } };
struct Rng { float lo, hi; };
struct Rng2 { float hi, lo; };

extern "C" void func_00406C30(W *w)
{
    int t = func_00402270(w->a14, *w->a10);
    switch (t) {
    case 3: {
        float lim = 0x1.999998p-4f;
        if (*func_00385B48(w->a0) >= lim && *func_00385B48(w->a0) <= 0.9f) {
            *func_00385DC8(w->a0) -= w->k;
            if (*func_00385DC8(w->a0) < lim) *func_00385DC8(w->a0) = lim;
        } else {
            lim = 1.0f;
            *func_00385DC8(w->a0) += w->k;
            if (*func_00385DC8(w->a0) > lim) *func_00385DC8(w->a0) = lim;
        }
        break;
    }
    case 4: {
        float x = *func_00385BA8(w->a0);
        Lin l;
        Rng r;
        float *p;
        if (x > 0.0f) {
            l.m = -0.9549296f; l.c = 1.7499997f;
            p = func_00385DC8(w->a0);
            r.hi = 1.0f; r.lo = 0.25f;
            *p = fmins(fmaxs(l.eval(x), r.lo), r.hi);
        } else {
            l.m = 0.9549296f; l.c = 1.7499997f;
            p = func_00385DC8(w->a0);
            r.lo = 1.0f; r.hi = 0.25f;
            *p = fmins(fmaxs(l.eval(x), r.hi), r.lo);
        }
        break;
    }
    }
}
