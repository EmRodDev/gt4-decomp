/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct Vec { void *alloc; char *start; char *end; };
struct Self { s32 f0; s32 f4; char f8; char pad9[0x3FF]; Vec v; };
struct HO { char pad[0x30]; Str s; };
struct Handle { HO *o; char pad[0xC]; };

extern Rep D_00659FA8;
extern "C" void *func_00208F00(void *, const void *);
extern "C" void func_00208F18(void *, int);
extern "C" const char *func_0026CB70(void *) throw();
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, u32, u32, const char *, u32);

static inline void release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

static inline char *vec_back(Vec *v) { return v->end - 4; }
static inline void vec_pop_back(Vec *v) {
    char *e = v->end - 4;
    v->end = e;
    func_00208F18(e, 2);
}

extern "C" void func_0026D108(Self *self) {
    const char *name = func_0026CB70(self);
    if (name != 0) {
        Handle h;
        Str t;
        func_00208F00(&h, vec_back(&self->v));
        HO *o = h.o;
        Str *ps = &t;
        {
            Rep *r = &D_00659FA8;
            char *p;
            if (r->sel != 0) {
                p = func_005C2560(r);
            } else {
                p = (char *)(r + 1);
                r->ref++;
            }
            ps->p = p;
        }
        func_005C2630(ps, 0, (u32)-1, name, func_0057F260(name));
        Str *dst = &o->s;
        if (ps != dst) {
            release(dst);
            char *src = ps->p;
            Rep *r = (Rep *)src - 1;
            char *p;
            if (r->sel != 0) {
                p = func_005C2560(r);
            } else {
                p = src;
                r->ref++;
            }
            dst->p = p;
        }
        release(ps);
        func_00208F18(&h, 2);
    }
    self->f8 = 0;
    self->f4 = 0;
    self->f0 = 0;
    vec_pop_back(&self->v);
}
