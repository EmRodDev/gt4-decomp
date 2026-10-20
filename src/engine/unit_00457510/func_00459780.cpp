#include "types.h"

/* Constructor of a suspension-geometry helper: samples the car's suspension curves, solves the
   roll centre angle and resets the four wheel states. */

struct WheelMode { s32 a, b, c, mode; };
struct Geometry {
    const void *vtable;
    void *car;
    f32 roll;
    f32 angle;
    WheelMode wheel[4];
    s32 f50;
    f32 f54;
};

extern char D_00688698[];
extern "C" f32 func_00364BB0(void *car, s32 i, f32, f32 x);
extern "C" f32 func_00364D20(void *car, s32 i);
extern "C" f32 func_00364C60(void *car, s32 i, f32, f32);
extern "C" u8 func_00364A78(void *car);
extern "C" float func_0059D2A0(float x);

static inline f32 root(f32 x) { f32 r; __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x)); return r; }

/* Declared returning int (as the original prototype did) although nothing is returned: a void
   return type changes the code of the closing switch. */
extern "C" int func_00459780(Geometry *self, void *car) {
    self->f54 = 0.0f;
    self->vtable = D_00688698;
    f32 s = self->f54;
    self->car = car;
    f32 a = -func_00364BB0(car, 0, s, s);
    f32 b = -func_00364BB0(self->car, 2, s, s);
    f32 c = func_00364D20(self->car, 0);
    f32 d = func_00364D20(self->car, 2);
    f32 e = func_00364C60(self->car, 0, s, s);
    f32 f = func_00364C60(self->car, 2, s, s);
    f32 dx = b - a;
    f32 dy = d - c;
    f32 dz = f - e;
    f32 sn, cs;
    if (dx == s) {
        if (dz == s) {
            sn = s;
            cs = 1.0f;
        } else {
            sn = dy / dz;
            cs = root(1.0f - sn * sn);
        }
    } else {
        f32 zz = dz * dz;
        f32 one = 1.0f;
        f32 m = dx * root(zz - dy * dy + dx * dx);
        f32 inv = one / (zz + dx * dx);
        f32 r1 = (m + dy * dz) * inv;
        f32 r2 = -(m - dy * dz) * inv;
        f32 t1 = (dz * r1 - dy) / dx;
        f32 t2 = (dz * r2 - dy) / dx;
        if (t1 < s || (one < t1 && s < t2)) {
            sn = r2;
            cs = t2;
        } else {
            sn = r1;
            cs = t1;
        }
    }
    f32 g = func_0059D2A0(sn);
    f32 h = 1.0f / cs;
    self->f50 = 0;
    self->angle = -(g * 57.29578f);
    f32 k = sn * h;
    f32 q = -e - a * k;
    f32 p = f + b * k;
    self->roll = ((c + a * h) * p + (d + b * h) * q) / (q + p);
    for (int i = 0; i < 4; i++) {
        WheelMode *w = &self->wheel[i];
        w->a = 0;
        w->b = 0;
        w->c = 0;
    }
    switch (func_00364A78(car)) {
    case 1:
        self->wheel[0].mode = 0;
        self->wheel[1].mode = 0;
        self->wheel[2].mode = 1;
        self->wheel[3].mode = 1;
        break;
    case 2:
        self->wheel[0].mode = 0;
        self->wheel[1].mode = 0;
        self->wheel[2].mode = 1;
        self->wheel[3].mode = 2;
        break;
    case 3:
        self->wheel[0].mode = 0;
        self->wheel[1].mode = 1;
        self->wheel[2].mode = 2;
        self->wheel[3].mode = 2;
        break;
    case 0:
    default:
        self->wheel[0].mode = 0;
        self->wheel[1].mode = 1;
        self->wheel[2].mode = 2;
        self->wheel[3].mode = 3;
        break;
    }
}
