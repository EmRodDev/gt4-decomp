#include "types.h"

struct Q {
    s32 n0;
    char pad4[8];
    s32 wC;
    char pad10[8];
    u32 w18;
    s32 w1C;
    s32 w20;
    char pad24[8];
    s32 w2C;
};

struct O {
    char pad[0x24];
    Q *q24;
};

struct Ent { u32 ptr; u32 size; };

struct Vec {
    Ent e[8];
    u32 lim;
    s32 n;
};

struct Req { s32 a; s32 b; s32 c; s32 d; };

extern "C" void func_005ADF20(s32 a);
extern "C" void *func_005A4724(void *, const void *, u32);
extern "C" void func_0057D9C0(const char *, ...);
extern "C" s32 func_005AE060(Req *r, s32 n);
extern "C" s32 func_005AE040(s32 h);
extern char D_006CC030[];

static inline u32 smaller(u32 a, u32 b) { return a < b ? a : b; }

extern "C" s32 func_00570900(s32 a0, s32 a1, O *o, Vec *v, int unused0, int unused1) {
    Req rq;
    s32 off = 0;
    s32 r = -0x200;
    if (o == 0) return r;
    Q *q = o->q24;
    func_005ADF20(0);
    s32 st = q->wC;
    if (st != 0) {
        return ((st ^ 3) != 0) ? 0 : -0x1F5;
    }
    s32 n0 = q->n0;
    if (n0 > 0) return 0;
    if (n0 < 0) return n0;
    u32 left = smaller(q->w18, v->lim);
    s32 i = 0;
    if (v->n > 0) {
        u32 *sizes = (u32 *)((char *)v + 4);
        u32 *ptrs = (u32 *)v;
        do {
            u32 sz = *(u32 *)((char *)sizes + ((u32)i << 3));
            u32 chunk = (left < sz) ? left : sz;
            left -= chunk;
            func_005A4724((void *)(q->w1C + off), (void *)*(u32 *)((char *)ptrs + ((u32)i << 3)), chunk);
            i++;
            off += chunk;
            if (left == 0) break;
        } while (i < v->n);
    }
    func_005ADF20(0);
    s32 src = q->w1C;
    s32 dst = q->w2C;
    rq.a = src;
    rq.b = dst;
    rq.c = left;
    rq.d = 0;
    s32 h = func_005AE060(&rq, 1);
    if (h == 0) func_0057D9C0(D_006CC030);
    while (func_005AE040(h) >= 0) {
    }
    q->n0 = left;
    func_005ADF20(0);
    rq.b = q->w20;
    rq.c = 0x10;
    rq.a = (s32)q;
    rq.d = 0;
    h = func_005AE060(&rq, 1);
    if (h == 0) func_0057D9C0(D_006CC030);
    while (func_005AE040(h) >= 0) {
    }
    return left;
}
