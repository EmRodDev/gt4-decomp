/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct VEntryI {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VEntryV {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

extern char D_006959D8[];
extern char D_00695AE0[];
extern char D_006959E0[];

extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, void *) throw();
extern "C" s32 func_001F15A0(void *);
extern "C" s32 func_001F2BB0(void *, const char *, s32);
extern "C" void func_001F84E0(void *, const char *);
extern "C" void func_00227110(void *, void *);
extern "C" void func_00227128(void *, int);
extern "C" void func_00227BE0(void *, const char *);
extern "C" void func_0023B1D8(void *, int);
extern "C" void func_0023B478(void *);
extern "C" void func_0023CA78(void *, const char *, const char *);
extern "C" void func_002ED5C0(void *, int);
extern "C" void func_002ED618(void *, void *);
extern "C" s32 hArray__size(void *);
extern "C" VObj **HArray__operator_index(void *, s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" void func_0057DA20(void *, const char *, ...);
extern "C" struct S00659988 *func_005C11A8(void);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006959D8;
    t->p[len] = 0;
    return t->p;
}

static inline s32 vcall58(VObj *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

static inline void vcall18(Str *ret, VObj *o) {
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline const char *name_of(Str *h, VObj *o) {
    vcall18(h, o);
    return c_str(h);
}

extern "C" void MNetwork__imSend(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
    Str sp0;
    Str h;
    char buf[0x80];
    func_001DC650(&sp0, arg1);
    char *obj;
    if (arg2 >= 3) {
        obj = sp0.p;
        if (*(s32 *)(obj + 0x1CC) < 0) {
            *(s32 *)(obj + 0x1CC) = vcall58(arg3[2]);
            Str *p1 = &h;
            void *o1 = sp0.p;
            func_001F84E0(o1, name_of(p1, arg3[1]));
            str_release(p1);
            obj = sp0.p;
        }
    } else {
        obj = sp0.p;
    }
    Str *ph = &h;
    s32 r = func_001F2BB0(obj, name_of(ph, arg3[0]), *(s32 *)((char *)sp0.p + 0x1CC));
    str_release(ph);
    func_002FE278(ph, r != 0);
    if ((void *)arg0 != (void *)ph) {
        void *p = ph->p;
        if (p != 0) {
            func_003285A8(p);
        }
        if (*arg0 != 0) {
            func_003285F8(*arg0);
        }
        *arg0 = p;
    }
    func_002FC870(ph, 2);
    if (r != 0) {
        s32 v = func_001F15A0(sp0.p);
        func_0057DA20(buf, D_00695AE0, v, name_of(ph, arg3[0]));
        str_release(ph);
        func_00227110(ph, (char *)sp0.p + 0x1C4);
        func_00227BE0(ph->p, buf);
        func_00227128(ph, 2);
    }
    func_001DC5F8(&sp0, 2);
}
