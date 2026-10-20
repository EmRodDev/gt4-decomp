/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

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
};

struct Reader {
    union { void *vtbl; s32 word; } u;
    void *dst;
    char pad8[8];
};

struct Obj {
    char pad0[0xB0];
    f32 padLeft;
    f32 padRight;
    f32 padTop;
    f32 padBottom;
};

extern Rep D_00659FA8;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 MfloatReader__structor_0(void *self, void *node);
extern "C" s32 func_0020FD38(void *node, Str *name, Reader *r);
extern "C" void MReaderBase__structor_0(Reader *r, s32 flags);




#define STR_BUILD(SRC) \
    { \
        const char *src = SRC; \
        Rep *r = &D_00659FA8; \
        char *d; \
        if (r->sel != 0) { \
            d = func_005C2560(r); \
        } else { \
            d = (char *)(r + 1); \
            r->ref++; \
        } \
        ps->p = d; \
        func_005C2630(ps, 0, -1, src, func_0057F260(src)); \
    }

#define STR_RELEASE() \
    { \
        Rep *q = (Rep *)(ps->p - 0x10); \
        if (--q->ref == 0) { \
            s32 cap = q->cap + 0x10; \
            func_00326798(q, cap, 4, func_005C11A8()->name); \
        } \
    }


extern char MboolReader__vtable[], MfloatReader__vtable[], MstringReader__vtable[];
extern "C" void func_00233D48(void *, s32) throw();
extern "C" void func_00233D78(void *, s32) throw();
extern "C" void func_00233DB8(void *, s32) throw();
extern "C" void func_00233DE8(void *, s32) throw();
extern "C" void func_00233E18(void *, s32) throw();
extern "C" bool MboolReader__structor_5(char *self, void *node) {
    union { s32 i; char pad[16]; } v;
    Str s;
    Reader r3;
    Reader r1;
    s32 spare[4];
    Reader r2;
    Str *ps;
    if (MfloatReader__structor_0(self, node)) return true;
    ps = &s;
    {
        s32 ok;
        Reader *pr;
        STR_BUILD("preload")
        pr = &r1;
        pr->u.vtbl = MboolReader__vtable;
        pr->dst = &v.i;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = MboolReader__vtable;
        MReaderBase__structor_0(pr, 0);
        STR_RELEASE()
        if (ok) {
            func_00233D48(self, v.i);
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        STR_BUILD("noload")
        pr = &r2;
        pr->u.vtbl = MboolReader__vtable;
        pr->dst = &v.i;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = MboolReader__vtable;
        MReaderBase__structor_0(pr, 0);
        STR_RELEASE()
        if (ok) {
            func_00233D78(self, v.i);
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        STR_BUILD("navigate_clip_angle")
        void *dst = self + 0xE4;
        pr = &r3;
        pr->u.vtbl = MfloatReader__vtable;
        pr->dst = dst;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = MfloatReader__vtable;
        MReaderBase__structor_0(pr, 0);
        STR_RELEASE()
        if (ok) {
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        STR_BUILD("navigate_start_front")
        pr = &r3;
        pr->u.vtbl = MboolReader__vtable;
        pr->dst = &v.i;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = MboolReader__vtable;
        MReaderBase__structor_0(pr, 0);
        STR_RELEASE()
        if (ok) {
            func_00233DB8(self, v.i);
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        STR_BUILD("navigate_wraparound")
        pr = &r3;
        pr->u.vtbl = MboolReader__vtable;
        pr->dst = &v.i;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = MboolReader__vtable;
        MReaderBase__structor_0(pr, 0);
        STR_RELEASE()
        if (ok) {
            func_00233DE8(self, v.i);
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        STR_BUILD("navigate_slant_move")
        pr = &r3;
        pr->u.vtbl = MboolReader__vtable;
        pr->dst = &v.i;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = MboolReader__vtable;
        MReaderBase__structor_0(pr, 0);
        STR_RELEASE()
        if (ok) {
            func_00233E18(self, v.i);
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        STR_BUILD("navigate_sound")
        pr = &r3;
        pr->u.vtbl = MstringReader__vtable;
        pr->dst = self + 0xDC;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = MstringReader__vtable;
        MReaderBase__structor_0(pr, 0);
        STR_RELEASE()
        if (ok) {
            return true;
        }
    }
    {
        s32 ok;
        Reader *pr;
        STR_BUILD("bgm")
        void *dst = self + 0xE0;
        pr = &r3;
        pr->u.vtbl = MstringReader__vtable;
        pr->dst = dst;
        ok = func_0020FD38(node, ps, pr);
        pr->u.vtbl = MstringReader__vtable;
        MReaderBase__structor_0(pr, 0);
        STR_RELEASE()
        return ok != 0;
    }
}
