typedef int s32;
typedef float f32;

struct Obj { char pad[0x18]; void *p18; };
struct V24 { f32 a, b, c, d, e, f; };
struct V16 { f32 a, b, c, d; };

extern "C" int func_00499728(Obj *);
extern "C" void func_0049CC48(void *);
extern "C" void func_0049FD50(s32, void *, void *, s32, s32, s32);
extern "C" void *func_004A5B70(s32);
extern "C" f32 func_0057D1F0(f32);
extern "C" f32 func_0057D2B8(f32) throw();

extern "C" void func_003AC140(s32 unused, Obj *obj, s32 n, f32 cx, f32 cy, f32 r0, f32 r1, f32 a0, f32 a1) {
    s32 cnt = n * 2 + 2;
    s32 q = (cnt * 3 + 3) / 4;
    V24 *p = (V24 *)func_004A5B70(q + (cnt * 2 + 3) / 4);
    V16 *t = (V16 *)((char *)p + q * 16);
    V24 *pv = p;
    V16 *tv = t;
    f32 ang = a0 * 0x1.1df468p-6f;
    f32 step = (a1 - a0) * 0x1.1df468p-6f;
    f32 fn = (f32)n;
    f32 v = 1.0f;
    f32 dv = -1.0f / fn;
    f32 da = step / fn;
    if (n >= 0) {
        s32 i = n + 1;
        do {
            f32 s = func_0057D1F0(ang);
            f32 c = func_0057D2B8(ang);
            f32 b = cy - r0 * c;
            f32 a = cx - r0 * s;
            f32 d = cx - r1 * s;
            f32 e = cy - r1 * c;
            pv->c = 0;
            pv->f = 0;
            pv->e = e;
            ang += da;
            pv->a = a;
            pv->d = d;
            pv->b = b;
            pv++;
            tv->b = v;
            tv->d = v;
            v += dv;
            tv->a = 0;
            tv->c = 0;
            tv++;
        } while (--i != 0);
    }
    func_00499728(obj);
    func_0049CC48(obj->p18);
    func_0049FD50(cnt, p, t, 0, 0, 0);
}
