#include "types.h"

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct Str {
    char *p;
    char pad[0xC];
};
struct S00659988 { const char *name; };

struct VEntry18 { s16 delta; s16 index; void (*fn)(Str *, void *); };
struct VEntry58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct Obj { char pad0[4]; char *vtbl; };

extern StringRep D_00659FA8;
extern char D_006959D8[];

extern "C" char *func_005C2560(StringRep *r);
extern "C" Str *func_005C2630(Str *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void *func_001DC650(s32 *, void *);
extern "C" void func_001DC5F8(s32 *, s32);
extern "C" void func_002ED5C0(void *, s32);
extern "C" s32 func_005CD320(Str *, const char *, u32, u32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline void construct(Str *str, const char *s) {
    str->p = grab(&D_00659FA8);
    func_005C2630(str, 0, (u32)-1, s, func_0057F260(s));
}

static inline void str_release(Str *s) {
    StringRep *q = (StringRep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->res + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *t) {
    s32 len = *(s32 *)(t->p - 0x10);
    if (len == 0) return D_006959D8;
    t->p[len] = 0;
    return t->p;
}

static inline void vcall_18(Str *ret, Obj *o) {
    VEntry18 *e = (VEntry18 *)(o->vtbl + 0x18);
    e->fn(ret, (char *)o + e->delta);
}

static inline s32 vcall_58(Obj *o) {
    VEntry58 *e = (VEntry58 *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}


extern "C" Str *func_001F24D0(s32 *ret, s32 ctx, s32 id);
extern char D_00695A20[];

extern "C" void MNetwork__getAnnounce(s32 *ret, void *ctx, s32 argc, Obj **args) {
    s32 h0[4];
    Str s;
    s32 mode;

    func_001DC650(h0, ctx);
    mode = 0;
    if (argc > 0) {
        s32 eq;
        vcall_18(&s, args[0]);
        eq = func_005CD320(&s, D_00695A20, 0, func_0057F260(D_00695A20)) == 0;
        str_release(&s);
        mode = eq != 0;
    }
    s32 *pv = (s32 *)&s;
    func_001F24D0(pv, h0[0], mode);
    if (ret != pv) {
        s32 newVal = *pv;
        s32 oldVal;
        if (newVal != 0)
            func_003285A8(newVal);
        oldVal = *ret;
        if (oldVal != 0)
            func_003285F8(oldVal);
        *ret = newVal;
    }
    func_002ED5C0(pv, 2);
    func_001DC5F8(h0, 2);
}
