#include "types.h"

struct Q {
    s32 n0;
    s32 n4;
    s32 n8;
    s32 nC;
    char pad10[0xC];
    s32 n1C;
    s32 n20;
    s32 n24;
};

struct O {
    char pad[0x20];
    Q *q;
};

struct Req { s32 a; s32 b; s32 c; s32 d; };

extern "C" void func_005ADF20(s32 a);
extern "C" s32 func_00570E00(O *o, s32 *p);
extern "C" void *func_005A4724(void *, const void *, u32);
extern "C" void func_0057D9C0(const char *, ...);
extern "C" s32 func_005AE060(Req *r, s32 n);
extern "C" s32 func_005AE040(s32 h);
extern char D_006CC030[];

extern "C" s32 func_005704A8(s32 a0, s32 a1, O *o, void *dst, s32 max, s32 *outp, int unused0) {
    Req rq;
    s32 sp10 = 0;
    s32 r = -0x200;
    if (o == 0) return r;
    Q *q = o->q;
    func_005ADF20(0);
    if (q->nC != 0) {
        r = func_00570E00(o, &sp10);
        if (r != 0) return r;
        if (sp10 == 0) return r;
    }
    *outp = 0;
    s32 n = q->n0;
    if (n <= 0) {
        *outp = q->n4;
        return q->n0;
    }
    s32 cnt = n < max ? n : max;
    func_005A4724(dst, (char *)(q->n1C + q->n24), cnt);
    s32 left = q->n0 - cnt;
    q->n0 = left;
    if (left != 0) {
        q->n24 = q->n24 + cnt;
    } else {
        q->n24 = 0;
        func_005ADF20(0);
        s32 q20 = q->n20;
        rq.a = (s32)q;
        rq.b = q20;
        rq.c = 0x10;
        rq.d = 0;
        s32 h = func_005AE060(&rq, 1);
        if (h == 0) func_0057D9C0(D_006CC030);
        while (func_005AE040(h) >= 0) {
        }
    }
    return cnt;
}
