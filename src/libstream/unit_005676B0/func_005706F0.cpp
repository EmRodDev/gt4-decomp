#include "types.h"

struct Q {
    s32 n0;
    char pad4[8];
    s32 wC;
    char pad10[8];
    s32 w18;
    s32 w1C;
    s32 w20;
    char pad24[8];
    s32 w2C;
};

struct O {
    char pad[0x24];
    Q *q24;
};

struct Req { s32 a; s32 b; s32 c; s32 d; };

extern "C" void func_005ADF20(s32 a);
extern "C" void *func_005A4724(void *, const void *, u32);
extern "C" void func_0057D9C0(const char *, ...);
extern "C" s32 func_005AE060(Req *r, s32 n);
extern "C" s32 func_005AE040(s32 h);
extern char D_006CC030[];

extern "C" s32 func_005706F0(s32 a0, s32 a1, O *o, const void *src, s32 max, int unused0, int unused1) {
    Req rq;
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
    s32 cap = q->w18;
    s32 n = max;
    if (cap < max) n = cap;
    func_005A4724((void *)q->w1C, src, n);
    func_005ADF20(0);
    s32 b1C = q->w1C;
    s32 b2C = q->w2C;
    rq.a = b1C;
    rq.b = b2C;
    rq.c = n;
    rq.d = 0;
    s32 h = func_005AE060(&rq, 1);
    if (h == 0) func_0057D9C0(D_006CC030);
    while (func_005AE040(h) >= 0) {
    }
    q->n0 = n;
    func_005ADF20(0);
    s32 b20 = q->w20;
    rq.b = b20;
    rq.c = 0x10;
    rq.a = (s32)q;
    rq.d = 0;
    h = func_005AE060(&rq, 1);
    if (h == 0) func_0057D9C0(D_006CC030);
    while (func_005AE040(h) >= 0) {
    }
    return n;
}
