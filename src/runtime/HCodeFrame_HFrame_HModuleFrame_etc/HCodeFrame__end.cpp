/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern char D_0069E280[];
struct Vec { s32 pad0; s32 *begin; s32 *end; s32 *cap; };
struct Stk { Vec a; Vec b; s32 pad20; };
struct Src { s32 pad0; s32 m4; s32 m8; s32 mC; s32 m10; };
struct Dst { char pad[0x20]; s32 m20; s32 m24; s32 m28; Stk *m2C; };
extern "C" void func_00309378(void *, s32) throw();
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285F8(s32);
extern "C" const char **HObject__tf(void) throw();

static inline void destroy(Vec *v, s32 *it) {
    it[0] = (s32)v->begin;
    s32 *p = (s32 *)it[0];
    s32 *e = v->end;
    if (p != e) {
        s32 *q = p;
        do {
            p++;
            func_00309378(q, 2);
            q = p;
        } while (p != e);
    }
    s32 *b = v->begin;
    s32 sz = (v->cap - b);
    if (b)
        func_00326798(b, sz * 4, 4, *HObject__tf());
}

extern "C" void HCodeFrame__end(Src *src, Dst *dst) {
    s32 it[4];
    Stk *old = dst->m2C;
    if (old) {
        destroy(&old->b, it);
        {
            Vec *v = &old->a;
            it[0] = (s32)v->begin;
            s32 *p = (s32 *)it[0];
            s32 *e = v->end;
            if (p != e) {
                s32 *q = p;
                do {
                    q = p;
                    p++;
                    func_00309378(q, 2);
                } while (p != e);
            }
            s32 *b = v->begin;
            s32 sz = v->cap - v->begin;
            if (b)
                func_00326798(b, sz * 4, 4, *HObject__tf());
        }
        func_00326798(old, 0x24, 4, D_0069E280);
    }
    dst->m2C = (Stk *)src->m10;
    dst->m28 = src->mC;
    func_003285F8(dst->m24);
    dst->m24 = src->m8;
    dst->m20 = src->m4;
}
