typedef long s64;
struct Obj { char p[0x3C]; int f3c; };
struct Cls { char p[0x81CC]; };
struct Big { char p0[0x1000 * 0]; };
struct Ctx { char p[0x10000 + 0x81CC - 0x10000]; };
struct Vt { short off; short pad; int (*fn)(void *, char *, Obj *, int, int); };
struct Inst { char p[0x88]; Vt vt; };
struct Hdr { Inst *vptr; };

extern "C" void func_001CB8D8(void *, s64) throw();
extern "C" void func_001CB900(void *) throw();
extern "C" void func_001CB9B8(void *, int) throw();
extern "C" int func_001CBA80(void *, int, int, int) throw();
extern "C" int func_001CBAD0(void *, int) throw();
extern "C" void func_001CBB48(void *, int, int) throw();
extern "C" char *func_001CE460(void *, char *) throw();
struct Result { int value; };
extern "C" Result func_001CE4F0(void *, void *, int) throw();
static inline int status(const Result *const x) { return x->value; }
extern "C" unsigned long func_004359E0(char *);

#define F(p, o) (*(int *)((char *)(p) + 0x10000 + (o)))

static inline bool is_set(int v) { return v != 0; }
extern "C" int func_001CE868(void *arg0, Hdr *arg1, char *arg2, int arg3, int arg4) {
    char buf[0xD0];
    func_001CE460(arg0, buf);
    Obj *o = (Obj *)(((int)&buf[0x8F]) & ~0x3F);
    Result result = func_001CE4F0(arg0, arg1, (int)o);
    int r = result.value;
    if (status(&result))
        return r;
    int s0 = F(arg2, -0x7E34);
    func_001CB9B8(o, s0);
    if (func_001CBA80(o, s0, F(arg2, -0x7E20), F(arg2, -0x7E10)) == 0)
        return 4;
    if (is_set(arg4))
        func_001CB8D8(o, func_004359E0(arg2));
    if (is_set(arg3))
        func_001CBB48(o, F(arg2, -0x7E20), arg3);
    func_001CBAD0(o, F(arg2, -0x7E10));
    int s0b = o->f3c;
    func_001CB900(o);
    Vt *v = &arg1->vptr->vt;
    int q = v->fn((char *)arg1 + v->off, buf, o, 0x40, 0);
    if (is_set(q))
        return 1;
    F(arg2, -0x7E10) = s0b;
    return 0;
}
