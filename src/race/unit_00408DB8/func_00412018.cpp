/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Entry { short d; short i; void *fn; };
struct Iface { Entry *tab; };
struct Car { char pad[0x624]; u8 f624; };
struct Obj {
    s32 f0;
    char pad4[4];
    s32 f8;
    s32 *fC;
    s32 f10;
    Iface *f14;
    Car *f18;
    char pad1C[0x110 - 0x1C];
    f32 dt;
    char pad114[0x120 - 0x114];
    s32 f120;
};

struct St { f32 acc; f32 *vel; f32 *pos; };

extern "C" f32 func_003857A8(s32);
extern "C" f32 func_003857C0(s32);
extern "C" f32 *func_00385B48(s32);
extern "C" f32 *func_00385B58(s32);
extern "C" f32 *func_00385B68(s32);
extern "C" f32 *func_00385B78(s32);
extern "C" f32 *func_00385B88(s32);
extern "C" f32 *func_00385B98(s32);
extern "C" s32 func_00385ED0(s32);
extern "C" s32 func_00385F00(s32 *);
extern "C" s32 *func_00385F70(s32 *);
extern "C" void func_00385FD0(s32 *, s32);
extern "C" void func_00385FE0(s32 *, s32);
extern "C" f32 *func_00386228(s32);
extern "C" f32 *func_00386238(s32);
extern "C" f32 *func_00386248(s32);
extern "C" f32 *func_00386258(s32);
extern "C" f32 *func_00386268(s32);
extern "C" f32 *func_00386368(s32);
extern "C" f32 *func_00386378(s32);
extern "C" s32 func_00386610(s32);
extern "C" s32 func_00386620(s32);
extern "C" s32 func_00386630(s32);
extern "C" s32 func_00386640(s32);
extern "C" void func_0040CA58(Car *, s32 *, s32 *, s32 *, s32 *) throw();
extern "C" s32 func_0040D588(Obj *) throw();
extern "C" s32 func_0040D5C8(Obj *) throw();
extern "C" void func_00411EB0(s32, s32, s32, s32, s32, f32 *, f32 *) throw();
extern "C" s32 func_00411628(s32, s32, s32, s32, s32, f32, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *) throw();
extern "C" f32 func_004145C8(f32, f32);
extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter(void);
extern "C" f32 func_0044F910(void *);
extern "C" f32 func_0044FC70(void *);
extern "C" f32 func_0044FC88(void *);

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 clampf(f32 v, f32 lo, f32 hi) { return minf(maxf(v, lo), hi); }
static inline f32 clampr(f32 v, const f32 &lo, const f32 &hi) { return minf(maxf(v, lo), hi); }
static inline f32 absf(f32 x) { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

struct Line {
    f32 a, b;
    Line(f32 x0, f32 y0, f32 x1, f32 y1) { f32 r = 1.0f / (x1 - x0); a = (y1 - y0) * r; b = (y0 * x1 - y1 * x0) * r; }
    f32 at(f32 x) const { return a * x + b; }
};

static inline f32 vcallF(Iface *o, int idx, f32 a) { Entry *e = o->tab + idx; return ((f32 (*)(void *, f32))e->fn)((char *)o + e->d, a); }

static inline void init(St *s, f32 *v, f32 *p) { s->acc = 0.0f; s->vel = v; s->pos = p; }
static inline void fix(St *s, f32 a, f32 v, f32 p) { s->acc = a; *s->vel = v; *s->pos = p; }
static inline void stop(St *s, f32 a, f32 v) { s->acc = a; *s->vel = v; }
static inline void integrate(St *s, f32 dt) { *s->vel += s->acc * dt; *s->pos += *s->vel * dt; s->acc = 0.0f; }
static inline void step(St *s, f32 dt, f32 d) { s->acc -= *s->vel * d; integrate(s, dt); }
static inline bool locked(Obj *o) { return o->f120 != 0 && func_0040D588(o) != 0; }

extern "C" void func_00412018(Obj *o) {
    s32 a, b, c;
    St s1, s2, s3;
    f32 tx, ty;
    u8 cur = o->f18->f624;
    s32 tgt = func_00385ED0(*o->fC);
    a = 0;
    b = 0;
    c = 0;
    f32 v2 = vcallF(o->f14, 2, 0.0f);
    s32 fwd = 1;
    if (!(vcallF(o->f14, 18, 0.0f) < v2)) fwd = 0;
    func_0040CA58(o->f18, &a, &b, &c, 0);
    s32 flag = 0;
    func_00385FE0(o->fC, cur);
    init(&s1, func_00386228(o->f8), func_00385B48(o->f0));
    init(&s2, func_00386258(o->f8), func_00385B78(o->f0));
    init(&s3, func_00386268(o->f8), func_00385B88(o->f0));
    tx = 0.0f;
    ty = 0.0f;
    if ((a != 0) | (b != 0) | c) {
        if (func_0040D5C8(o)) {
            if (!locked(o)) flag = func_00386610(o->f10) == 1;
        }
    }

    switch (func_00385F00(o->fC)) {
    case 0:
        fix(&s1, 0.0f, 0.0f, 0.0f);
        if (cur != tgt) {
            f32 x0, y0, x1, y1;
            {
                s32 k0 = func_00386610(o->f10);
                s32 k1 = func_00386620(o->f10);
                s32 k2 = func_00386630(o->f10);
                s32 k3 = func_00386640(o->f10);
                func_00411EB0(k0, k1, k2, k3, cur, &x0, &y0);
            }
            {
                s32 k0 = func_00386610(o->f10);
                s32 k1 = func_00386620(o->f10);
                s32 k2 = func_00386630(o->f10);
                s32 k3 = func_00386640(o->f10);
                func_00411EB0(k0, k1, k2, k3, tgt, &x1, &y1);
            }
            s32 m = func_00386610(o->f10);
            if (m == 1 || m == 4) {
                if (x0 != x1 || y0 != y1) *func_00385F70(o->fC) = 2;
            }
        } else if (flag) {
            *func_00385F70(o->fC) = 1;
        }
        if (func_00385F00(o->fC) == 0) break;
    case 1:
    case 2:
        {
            f32 p = *s1.pos;
            if (0.5f < p) {
                fix(&s1, 0.0f, 0.0f, clampf(1.0f - p, 0.0f, 1.0f));
            } else {
                stop(&s1, 0.0f, 0.0f);
            }
        }
        if (*func_00385F70(o->fC) == 1) {
            *func_00385F70(o->fC) = 3;
        } else {
            *func_00385F70(o->fC) = 4;
        }
    case 3:
    case 4:
        if (cur == tgt && !flag) {
            *func_00385F70(o->fC) = 8;
            break;
        }
        if (*func_00385F70(o->fC) == 3) {
            *s1.vel = func_004145C8(*s1.pos * 2.0f, 1.0f);
        } else {
            *s1.vel = func_004145C8(*s1.pos * 2.0f, 2.5f);
        }
        if (*s1.pos < 0.5f) break;
        fix(&s1, 0.0f, 0.0f, 0.5f);
        if (cur != tgt) {
            *func_00385F70(o->fC) = 6;
        } else {
            *func_00385F70(o->fC) = 5;
        }
        break;
    case 5:
        if (cur == tgt && !flag) {
            *func_00385F70(o->fC) = 8;
            break;
        }
        {
            f32 x, y, vx, vy, timer;
            f32 x0 = *func_00385B58(o->f0);
            f32 y0 = *func_00385B68(o->f0);
            x = x0;
            y = y0;
            vx = 0.0f;
            vy = 0.0f;
            timer = 0.0f;
            s32 k0 = func_00386610(o->f10);
            s32 k1 = func_00386620(o->f10);
            s32 k2 = func_00386630(o->f10);
            s32 k3 = func_00386640(o->f10);
            func_00411628(k0, k1, k2, k3, cur, o->dt, &x, &y, &vx, &vy, &timer, &tx, &ty);
        }
        if (cur == tgt) break;
        *func_00385F70(o->fC) = 6;
    case 6:
        {
            func_00385B58(o->f0);
            func_00385B68(o->f0);
            s32 k0 = func_00386610(o->f10);
            s32 k1 = func_00386620(o->f10);
            s32 k2 = func_00386630(o->f10);
            s32 k3 = func_00386640(o->f10);
            s32 n = o->f18->f624;
            f32 dt = o->dt;
            f32 *x = func_00385B58(o->f0);
            f32 *y = func_00385B68(o->f0);
            f32 *vx = func_00386238(o->f8);
            f32 *vy = func_00386248(o->f8);
            f32 *timer = func_00386378(o->f8);
            if (func_00411628(k0, k1, k2, k3, n, dt, x, y, vx, vy, timer, &tx, &ty)) {
                func_00385FD0(o->fC, cur);
                *func_00385F70(o->fC) = 7;
                *func_00386368(o->f8) = 0.0f;
            }
        }
        break;
    case 8:
        {
            f32 p = *s1.pos;
            if (p < 0.5f) {
                fix(&s1, 0.0f, 0.0f, clampf(1.0f - p, 0.0f, 1.0f));
            } else {
                stop(&s1, 0.0f, 0.0f);
            }
        }
        *func_00385F70(o->fC) = 9;
    case 7:
    case 9:
        {
            f32 a;
            if (fwd) {
                a = absf(func_003857A8(o->f0));
            } else {
                a = absf(func_003857C0(o->f0));
            }
            Line l(0.0f, 0.5f, 3.14159265f, 0.8f);
            f32 lo = 0.5f;
            f32 hi = 0.8f;
            f32 k = clampr(l.at(a), lo, hi);
            *s1.vel = func_004145C8(*s1.pos * 2.0f - 1.0f, k);
        }
        if (cur != tgt) {
            *func_00385F70(o->fC) = 2;
            break;
        }
        if (flag) {
            *func_00385F70(o->fC) = 1;
            break;
        }
        if (*func_00385F70(o->fC) == 7) {
            *func_00386368(o->f8) += o->dt;
            if (*func_00386368(o->f8) < func_0044F910(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter())) break;
            *func_00385F70(o->fC) = 8;
            break;
        }
        if (*func_00385F70(o->fC) != 9) break;
        if (*s1.pos < 1.0f) break;
        *func_00385F70(o->fC) = 0;
        s1.acc = 0.0f;
        *s1.vel = 0.0f;
        *s1.pos = 0.0f;
        break;
    }

    integrate(&s1, o->dt);
    s2.acc += (tx - *s2.pos) * 1520.0f;
    step(&s2, o->dt, 80.0f);
    s3.acc += (ty - *s3.pos) * 1520.0f;
    step(&s3, o->dt, 80.0f);
    {
        f32 lo = -func_0044FC70(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        f32 hi = func_0044FC70(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        if (hi < *s2.pos) fix(&s2, 0.0f, 0.0f, hi);
        else if (*s2.pos < lo) fix(&s2, 0.0f, 0.0f, lo);
    }
    {
        f32 lo = -func_0044FC88(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        f32 hi = func_0044FC88(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        if (hi < *s3.pos) fix(&s3, 0.0f, 0.0f, hi);
        else if (*s3.pos < lo) fix(&s3, 0.0f, 0.0f, lo);
    }
    f32 want = 0.0f;
    if (locked(o)) {
        want = 1.0f;
    } else if (0.0f <= *s1.pos && *s1.pos <= 0.2f) {
        want = *s1.pos * 5.0f;
    } else if (*s1.pos <= 0.8f) {
        want = 1.0f;
    } else if (*s1.pos <= 1.0f) {
        want = 1.0f - (*s1.pos - 0.8f) * 5.0f;
    }
    if (*func_00385B98(o->f0) < want) {
        *func_00385B98(o->f0) += o->dt * 5.0f;
        if (want < *func_00385B98(o->f0)) *func_00385B98(o->f0) = want;
    } else if (want < *func_00385B98(o->f0)) {
        *func_00385B98(o->f0) -= o->dt * 5.0f;
        if (*func_00385B98(o->f0) < want) *func_00385B98(o->f0) = want;
    }
}
