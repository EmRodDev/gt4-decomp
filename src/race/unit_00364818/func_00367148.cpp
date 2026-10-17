/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"

struct Tab { s16 n; f32 *x; f32 *y; };
struct Curve { f32 m0; char pad4[0x1C]; Tab x; char pad2C[0x40]; Tab y; f32 base; f32 threshold; f32 slope; };
struct Special { f32 scale, lo, loValue, hi, hiValue; };
struct Flag { u8 x; char pad1[0x1E]; u8 y; char pad20[8]; };
struct FlagSet { Flag a[4]; Flag b[4]; Flag c[4]; };

struct Wheel {
    f32 angle;
    char pad4[0x1C];
    f32 f20;
    char pad24[4];
    f32 f28;
    f32 f2C;
    char pad30[4];
    f32 f34;
    f32 f38;
    char pad3C[4];
    f32 f40;
    char pad44[4];
    f32 f48;
    char pad4C[0x3D];
    u8 kind;
    char pad8A[0x29];
    u8 timer;
    f32 outB4;
    f32 outB8;
    f32 outBC;
    char padC0[0x2C];
};

struct Rec { u8 m0; u8 n; };

struct Car {
    char pad0[4];
    void *m4;
    char pad8[8];
    void *m10;
    char pad14[0x150];
    Wheel wheel[4];
    char pad514[0x38];
    f32 f54C;
    char pad550[0x18C];
    char sub6DC[1];
};

extern "C" void func_003438C8(void *, f32);
extern "C" u8 DynamicsConductor__getCourseType(void *);
extern "C" Rec *func_00359510(void *);
extern "C" f32 func_00359830(Tab *, f32);
extern "C" f32 func_0057D1F0(f32);
extern "C" f32 func_0057D2B8(f32) throw();

extern FlagSet D_006224B0;
extern Curve D_00843A20[4];
extern Curve D_00843C30[4];
extern Curve D_00843E40[4];
extern Special D_00844050;

static inline Wheel *wheelAt(Car *c, s32 i) { return (Wheel *)((char *)c + i * 0xEC + 0x164); }

static inline f32 root(f32 x) { f32 r; __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x)); return r; }

extern "C" void func_00367148(Car *self) {
    s32 i;
    f32 total = 0.0f;
    Rec *rec = func_00359510(self->m10);

    for (i = 0; i < rec->n; i++) {
        Wheel *w = wheelAt(self, i);
        if (w->f48 != 0.0f) w->timer = 6;
        else if (w->timer) w->timer--;
        if (w->timer == 0) {
            w->outB4 = 0.0f;
            w->outB8 = 1.0f;
            w->outBC = 0.0f;
        } else {
            s32 g = 0;
            s32 kind;
            f32 speed, a, b, d, ang;
            switch (w->kind) {
            case 2:
            case 3:
            case 4:
            case 5:
            case 13:
            case 14:
                g = 1;
                break;
            case 6:
            case 20:
            case 21:
            case 22:
                g = 2;
                break;
            }
            speed = wheelAt(self, i)->f34;
            if (speed < 0.0f) speed = -speed;
            ang = w->angle;
            f32 t = func_0057D1F0(ang) * w->f2C;
            a = t + func_0057D2B8(ang) * w->f28;
            if (a < 0.0f) a = -a;
            f32 ang2 = w->angle;
            b = w->f38;
            f32 t2 = func_0057D1F0(ang2) * w->f28;
            d = t2 - func_0057D2B8(ang2) * w->f2C;
            f32 f20 = w->f20;
            f32 lat = d - f20;
            if (d < 0.0f) lat = -lat;
            kind = w->kind;
            u8 k = kind;
            if (k != 1 && k != 10 && k != 11 && k != 21) {
                s32 flag = 0;
                f32 x, y;
                x = !D_006224B0.a[g].x ? speed : a;
                x = func_00359830(&D_00843A20[g].x, x);
                y = !D_006224B0.a[g].y ? b : lat;
                y = func_00359830(&D_00843A20[g].y, y);
                f32 va = root(y * y + x * x);
                x = w->f40 - D_00843A20[g].threshold;
                if (x > 0.0f) va += x * D_00843A20[g].slope;
                if (va != 0.0f) va += D_00843A20[g].base;
                if (w->outB4 == D_00843A20[g].base) {
                    if (va != D_00843A20[g].base) flag = 1;
                }
                w->outB4 = va;
                x = !D_006224B0.b[g].x ? speed : a;
                x = func_00359830(&D_00843C30[g].x, x);
                y = !D_006224B0.b[g].y ? b : lat;
                y = func_00359830(&D_00843C30[g].y, y);
                f32 vb = D_00843C30[g].base + root(y * y + x * x);
                x = w->f40 - D_00843C30[g].threshold;
                if (x > 0.0f) vb += x * D_00843C30[g].slope;
                if (flag && (i & 1)) vb *= 0.75f;
                w->outB8 = vb;
                kind = w->kind;
            } else {
                Special *sp = &D_00844050;
                f32 r = w->f48 / 0x1.323ffep+11f - 0.25f;
                if (r < 0.0f) r = 0.0f;
                else if (r > 1.0f) r = 1.0f;
                f32 t = r;
                r = f20;
                if (r < 0.0f) r = -r;
                f32 s = (r - 0x1.638e36p+0f) * 0x1.26e97ap-3f;
                if (s < 0.0f) s = 0.0f;
                else if (s > 1.0f) s = 1.0f;
                w->outB4 = s * t * sp->scale;
                f32 out;
                if (r <= sp->lo) {
                    out = sp->loValue;
                } else if (r >= sp->hi) {
                    out = sp->hiValue;
                } else {
                    out = sp->loValue + ((r - sp->lo) * (sp->hiValue - sp->loValue)) / (sp->hi - sp->lo);
                }
                w->outB8 = out;
            }
            if (kind == 12) g = 1;
            f32 x = !D_006224B0.c[g].x ? speed : a;
            x = func_00359830(&D_00843E40[g].x, x);
            f32 y = !D_006224B0.c[g].y ? b : lat;
            y = func_00359830(&D_00843E40[g].y, y);
            f32 vc = root(y * y + x * x);
            x = w->f40 - D_00843E40[g].threshold;
            if (x > 0.0f) vc += x * D_00843E40[g].slope;
            if (w->kind == 8) vc = 0.0f;
            if (vc != 0.0f) vc += D_00843E40[g].base;
            if (vc > 1.0f) vc = 1.0f;
            w->outBC = vc;
            if (g) total += vc;
        }
    }
    if (DynamicsConductor__getCourseType(self->m4) == 0) total *= 4.0f;
    return func_003438C8(self->sub6DC, total * 0x1.0624dcp-11f * self->f54C);
}
