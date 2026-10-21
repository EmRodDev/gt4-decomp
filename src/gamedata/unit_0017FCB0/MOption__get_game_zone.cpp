/* Script property accessor MOption game_zone: with arguments (argCount > 0) it acts as the setter, converting the string in args[0] to a number with func_00435E20 and storing it in the option block at +0x11C8; otherwise it acts as the getter and converts the stored value back to a name with func_00435E08, returning it as a new script string through *out (retain new, release old). The string/number table lookups are named only by position in the source; the semantics of the stored value are inferred from the accessor name. */
#include "types.h"

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

struct HObj {
    char pad[0x10];
    char *f10;
};

struct HStr {
    HObj *p;
    char pad[0xC];
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

extern Rep D_00659FA8;
extern char D_006915D0[];

extern "C" void func_0017FAD0(void *, int);
extern "C" void *func_0017FB28(void *, void *);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" const char *func_00435E08(void *);
extern "C" void func_00435E20(void *, const char *);
extern "C" s32 func_0057F260(const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006915D0;
    t->p[len] = 0;
    return t->p;
}

static inline void vcall18(Str *ret, VObj *o) {
    VEntryV *e = (VEntryV *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

extern "C" void MOption__get_game_zone(void **out, void *object, s32 argCount, VObj **args) {
    HStr optionHandle;
    if (argCount > 0) {
        Str t;
        HObj *hp;
        func_0017FB28(&optionHandle, object);
        hp = optionHandle.p;
        vcall18(&t, args[0]);
        const char *n = c_str(&t);
        func_00435E20(hp->f10 + 0x11C8, n);
        str_release(&t);
        func_0017FAD0(&optionHandle, 2);
        return;
    }
    {
        Str result;
        Str s;
        func_0017FB28(&optionHandle, object);
        Str *ps = &s;
        const char *src = func_00435E08(optionHandle.p->f10 + 0x11C8);
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        Str *pr = &result;
        func_00314B20(pr, ps);
        if ((void *)out != (void *)pr) {
            void *p = pr->p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*out != 0) {
                func_003285F8(*out);
            }
            *out = p;
        }
        func_00312318(pr, 2);
        str_release(ps);
        func_0017FAD0(&optionHandle, 2);
    }
}
