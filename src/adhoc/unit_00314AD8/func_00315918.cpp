/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Heap { const char *name; };
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_00312370(void *, void *);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
struct Rep {
    u32 len, cap, ref, selfish;
    static void operator delete(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
    void release() { if (--ref == 0) operator delete(this, sizeof(Rep) + cap); }
};
struct Str { char *p; char pad[12]; };
struct H { void *p; char pad[12]; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *);
struct Entry { short delta, idx; void *fn; };
static inline void release(Str *s) {
    Rep *r = (Rep *)s->p - 1;
    r->release();
}
static inline void init(Str *s) {
    char *v;
    if (D_00659FA8.selfish) v = func_005C2560(&D_00659FA8);
    else { ++D_00659FA8.ref; v = (char *)(&D_00659FA8 + 1); }
    s->p = v;
}
extern "C" u32 hArray__size(void *);
extern "C" int hInt__GetClassID();
extern "C" int hFloat__GetClassID();
extern "C" int hString__GetClassID();
extern "C" void func_00309360(void *, void *);
extern "C" void func_00309378(void *, int);
extern "C" int hObject__isInstanceOf(void *, int);
extern "C" char *func_00314AD8(void *);
extern "C" int func_0057DD28(char *, const char *, void *);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" double fptodp(float);
extern "C" Str *func_005C2630(Str *, u32, u32, const char *, u32);
/* virtual calls on a script object: entry +0x68 element(i), +0x58 int value, +0x60 float value */
static inline void *get(void *o, u32 i) {
    Entry *e = (Entry *)(*(char **)((char *)o + 4) + 0x68);
    return ((void *(*)(void *, u32))e->fn)((char *)o + e->delta, i);
}
static inline int intcall(void *o) {
    Entry *e = (Entry *)(*(char **)((char *)o + 4) + 0x58);
    return ((int (*)(void *))e->fn)((char *)o + e->delta);
}
static inline float floatcall(void *o) {
    Entry *e = (Entry *)(*(char **)((char *)o + 4) + 0x60);
    return ((float (*)(void *))e->fn)((char *)o + e->delta);
}
struct OH {
    void *p;
    char pad[12];
    OH(void *v) { func_00309360(this, v); }
    ~OH() { func_00309378(this, 2); }
};
/* sprintf-style formatter: up to 16 script values (int, float or string) as the argument list */
extern "C" void *func_00315918(void *out, void *format, H *args) {
    char buf[512];
    long values[16];
    u32 i = 0;
    for (; i < hArray__size(args->p) && i < 16; ++i) {
        OH h(get(args->p, i));
        OH *ph = &h;
        void *o = ph->p;
        if (hObject__isInstanceOf(o, hInt__GetClassID())) {
            long v = intcall(ph->p);
            values[i] = v;
        } else {
            o = ph->p;
            if (hObject__isInstanceOf(o, hFloat__GetClassID())) {
                union { double d; long l; } c;
                c.d = fptodp(floatcall(ph->p));
                values[i] = c.l;
            } else {
                o = ph->p;
                if (hObject__isInstanceOf(o, hString__GetClassID())) {
                    H str;
                    H *ps = &str;
                    func_00312370(ps, ph);
                    values[i] = (long)func_00314AD8(ps->p);
                    func_00312318(ps, 2);
                }
            }
        }
    }
    func_0057DD28(buf, func_00314AD8(format), values);
    char *b = buf;
    Str s;
    Str *ps = &s;
    init(ps);
    func_005C2630(ps, 0, (u32)-1, b, func_0057F260(b));
    func_00314B20(out, ps);
    release(ps);
    return out;
}
