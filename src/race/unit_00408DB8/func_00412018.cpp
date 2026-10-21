/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-frame animation state machine of a driver's shift motion (inferred: the current gear is the byte at +0x624 of the car, the target
 * gear comes from the state object, 0040CA58 supplies three shift flags a, b, c, the thresholds come from DRIVERSUPPORT::GetMotoristDynamicParameter,
 * and the code moves a 2D point). `phase` runs 0..1 through states 0..9 stored behind func_00385F70 (idle, start, travel to the gate point
 * of the target gear with func_00411EB0 / func_00411628, hold, return, finish); the lever point is chased by two damped springs (stiffness
 * 1520, damping 80) and clamped by motorist parameters, and a blend value (func_00385B98) eases towards handBlendTarget at 5 per second, 1 when
 * the shift is locked or the phase is between 0.2 and 0.8. The state numbering and the gate/lever reading are guesses from the control flow;
 * the helper functions have no recovered names and the three state channels stay generic (phase, springX, springY). */
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

static inline f32 vcallF(Iface *animation, int idx, f32 a) { Entry *e = animation->tab + idx; return ((f32 (*)(void *, f32))e->fn)((char *)animation + e->d, a); }

static inline void init(St *s, f32 *v, f32 *p) { s->acc = 0.0f; s->vel = v; s->pos = p; }
static inline void fix(St *s, f32 a, f32 v, f32 p) { s->acc = a; *s->vel = v; *s->pos = p; }
static inline void stop(St *s, f32 a, f32 v) { s->acc = a; *s->vel = v; }
static inline void integrate(St *s, f32 dt) { *s->vel += s->acc * dt; *s->pos += *s->vel * dt; s->acc = 0.0f; }
static inline void step(St *s, f32 dt, f32 d) { s->acc -= *s->vel * d; integrate(s, dt); }
static inline bool locked(Obj *animation) { return animation->f120 != 0 && func_0040D588(animation) != 0; }

extern "C" void func_00412018(Obj *animation) {
    s32 a, b, c;
    St phase, springX, springY;
    f32 targetX, targetY;
    u8 currentGear = animation->f18->f624;
    s32 targetGear = func_00385ED0(*animation->fC);
    a = 0;
    b = 0;
    c = 0;
    f32 v2 = vcallF(animation->f14, 2, 0.0f);
    s32 fwd = 1;
    if (!(vcallF(animation->f14, 18, 0.0f) < v2)) fwd = 0;
    func_0040CA58(animation->f18, &a, &b, &c, 0);
    s32 shiftRequested = 0;
    func_00385FE0(animation->fC, currentGear);
    init(&phase, func_00386228(animation->f8), func_00385B48(animation->f0));
    init(&springX, func_00386258(animation->f8), func_00385B78(animation->f0));
    init(&springY, func_00386268(animation->f8), func_00385B88(animation->f0));
    targetX = 0.0f;
    targetY = 0.0f;
    if ((a != 0) | (b != 0) | c) {
        if (func_0040D5C8(animation)) {
            if (!locked(animation)) shiftRequested = func_00386610(animation->f10) == 1;
        }
    }

    switch (func_00385F00(animation->fC)) {
    case 0:
        fix(&phase, 0.0f, 0.0f, 0.0f);
        if (currentGear != targetGear) {
            f32 x0, y0, x1, y1;
            {
                s32 k0 = func_00386610(animation->f10);
                s32 k1 = func_00386620(animation->f10);
                s32 k2 = func_00386630(animation->f10);
                s32 k3 = func_00386640(animation->f10);
                func_00411EB0(k0, k1, k2, k3, currentGear, &x0, &y0);
            }
            {
                s32 k0 = func_00386610(animation->f10);
                s32 k1 = func_00386620(animation->f10);
                s32 k2 = func_00386630(animation->f10);
                s32 k3 = func_00386640(animation->f10);
                func_00411EB0(k0, k1, k2, k3, targetGear, &x1, &y1);
            }
            s32 m = func_00386610(animation->f10);
            if (m == 1 || m == 4) {
                if (x0 != x1 || y0 != y1) *func_00385F70(animation->fC) = 2;
            }
        } else if (shiftRequested) {
            *func_00385F70(animation->fC) = 1;
        }
        if (func_00385F00(animation->fC) == 0) break;
    case 1:
    case 2:
        {
            f32 p = *phase.pos;
            if (0.5f < p) {
                fix(&phase, 0.0f, 0.0f, clampf(1.0f - p, 0.0f, 1.0f));
            } else {
                stop(&phase, 0.0f, 0.0f);
            }
        }
        if (*func_00385F70(animation->fC) == 1) {
            *func_00385F70(animation->fC) = 3;
        } else {
            *func_00385F70(animation->fC) = 4;
        }
    case 3:
    case 4:
        if (currentGear == targetGear && !shiftRequested) {
            *func_00385F70(animation->fC) = 8;
            break;
        }
        if (*func_00385F70(animation->fC) == 3) {
            *phase.vel = func_004145C8(*phase.pos * 2.0f, 1.0f);
        } else {
            *phase.vel = func_004145C8(*phase.pos * 2.0f, 2.5f);
        }
        if (*phase.pos < 0.5f) break;
        fix(&phase, 0.0f, 0.0f, 0.5f);
        if (currentGear != targetGear) {
            *func_00385F70(animation->fC) = 6;
        } else {
            *func_00385F70(animation->fC) = 5;
        }
        break;
    case 5:
        if (currentGear == targetGear && !shiftRequested) {
            *func_00385F70(animation->fC) = 8;
            break;
        }
        {
            f32 x, y, vx, vy, timer;
            f32 x0 = *func_00385B58(animation->f0);
            f32 y0 = *func_00385B68(animation->f0);
            x = x0;
            y = y0;
            vx = 0.0f;
            vy = 0.0f;
            timer = 0.0f;
            s32 k0 = func_00386610(animation->f10);
            s32 k1 = func_00386620(animation->f10);
            s32 k2 = func_00386630(animation->f10);
            s32 k3 = func_00386640(animation->f10);
            func_00411628(k0, k1, k2, k3, currentGear, animation->dt, &x, &y, &vx, &vy, &timer, &targetX, &targetY);
        }
        if (currentGear == targetGear) break;
        *func_00385F70(animation->fC) = 6;
    case 6:
        {
            func_00385B58(animation->f0);
            func_00385B68(animation->f0);
            s32 k0 = func_00386610(animation->f10);
            s32 k1 = func_00386620(animation->f10);
            s32 k2 = func_00386630(animation->f10);
            s32 k3 = func_00386640(animation->f10);
            s32 n = animation->f18->f624;
            f32 dt = animation->dt;
            f32 *x = func_00385B58(animation->f0);
            f32 *y = func_00385B68(animation->f0);
            f32 *vx = func_00386238(animation->f8);
            f32 *vy = func_00386248(animation->f8);
            f32 *timer = func_00386378(animation->f8);
            if (func_00411628(k0, k1, k2, k3, n, dt, x, y, vx, vy, timer, &targetX, &targetY)) {
                func_00385FD0(animation->fC, currentGear);
                *func_00385F70(animation->fC) = 7;
                *func_00386368(animation->f8) = 0.0f;
            }
        }
        break;
    case 8:
        {
            f32 p = *phase.pos;
            if (p < 0.5f) {
                fix(&phase, 0.0f, 0.0f, clampf(1.0f - p, 0.0f, 1.0f));
            } else {
                stop(&phase, 0.0f, 0.0f);
            }
        }
        *func_00385F70(animation->fC) = 9;
    case 7:
    case 9:
        {
            f32 a;
            if (fwd) {
                a = absf(func_003857A8(animation->f0));
            } else {
                a = absf(func_003857C0(animation->f0));
            }
            Line l(0.0f, 0.5f, 3.14159265f, 0.8f);
            f32 lo = 0.5f;
            f32 hi = 0.8f;
            f32 k = clampr(l.at(a), lo, hi);
            *phase.vel = func_004145C8(*phase.pos * 2.0f - 1.0f, k);
        }
        if (currentGear != targetGear) {
            *func_00385F70(animation->fC) = 2;
            break;
        }
        if (shiftRequested) {
            *func_00385F70(animation->fC) = 1;
            break;
        }
        if (*func_00385F70(animation->fC) == 7) {
            *func_00386368(animation->f8) += animation->dt;
            if (*func_00386368(animation->f8) < func_0044F910(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter())) break;
            *func_00385F70(animation->fC) = 8;
            break;
        }
        if (*func_00385F70(animation->fC) != 9) break;
        if (*phase.pos < 1.0f) break;
        *func_00385F70(animation->fC) = 0;
        phase.acc = 0.0f;
        *phase.vel = 0.0f;
        *phase.pos = 0.0f;
        break;
    }

    integrate(&phase, animation->dt);
    springX.acc += (targetX - *springX.pos) * 1520.0f;
    step(&springX, animation->dt, 80.0f);
    springY.acc += (targetY - *springY.pos) * 1520.0f;
    step(&springY, animation->dt, 80.0f);
    {
        f32 lo = -func_0044FC70(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        f32 hi = func_0044FC70(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        if (hi < *springX.pos) fix(&springX, 0.0f, 0.0f, hi);
        else if (*springX.pos < lo) fix(&springX, 0.0f, 0.0f, lo);
    }
    {
        f32 lo = -func_0044FC88(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        f32 hi = func_0044FC88(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
        if (hi < *springY.pos) fix(&springY, 0.0f, 0.0f, hi);
        else if (*springY.pos < lo) fix(&springY, 0.0f, 0.0f, lo);
    }
    f32 handBlendTarget = 0.0f;
    if (locked(animation)) {
        handBlendTarget = 1.0f;
    } else if (0.0f <= *phase.pos && *phase.pos <= 0.2f) {
        handBlendTarget = *phase.pos * 5.0f;
    } else if (*phase.pos <= 0.8f) {
        handBlendTarget = 1.0f;
    } else if (*phase.pos <= 1.0f) {
        handBlendTarget = 1.0f - (*phase.pos - 0.8f) * 5.0f;
    }
    if (*func_00385B98(animation->f0) < handBlendTarget) {
        *func_00385B98(animation->f0) += animation->dt * 5.0f;
        if (handBlendTarget < *func_00385B98(animation->f0)) *func_00385B98(animation->f0) = handBlendTarget;
    } else if (handBlendTarget < *func_00385B98(animation->f0)) {
        *func_00385B98(animation->f0) -= animation->dt * 5.0f;
        if (*func_00385B98(animation->f0) < handBlendTarget) *func_00385B98(animation->f0) = handBlendTarget;
    }
}
