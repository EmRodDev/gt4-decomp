/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

struct Engine {             /* at Eng + 0x134 */
    char pad0[0xCC];
    u16 maxRpm;             /* 0x200 */
    u16 minRpm;             /* 0x202 */
};
struct Gear {               /* at Eng + 0x234 */
    u8 type;
    char pad1[0x40 - 0x1];
    float ratio[20];        /* 0x40 */
    float scale[14];        /* 0x90 */
    float fC8;
};
struct Eng {
    char pad0[0x134];
    Engine engine;          /* 0x134 */
    char pad204[0x234 - 0x204];
    Gear gear;              /* 0x234 */
};
struct Wheel {
    char pad0[0x20];
    float f20;
    char pad24[0xEC - 0x24];
};
struct Sub {                /* at Car + 0x104 */
    char pad0[0x60];
    Wheel wheel[4];         /* 0x60 */
    char pad410[0x442 - 0x410];
    u8 u442;
    char pad443[0x448 - 0x443];
    float dt;               /* 0x448 */
    char pad44C[0x466 - 0x44C];
    s8 b466;
    u8 u467;
    char pad468[0x48C - 0x468];
    float f48C;
    char pad490[0x494 - 0x490];
    float f494;
    char pad498[0x4FC - 0x498];
    float rpm;              /* 0x4FC */
    char pad500[0x50C - 0x500];
    float f50C;
    float f510;
    float f514;
    float f518;
    char pad51C[0x520 - 0x51C];
    u8 gearNo;              /* 0x520 */
    char pad521;
    u8 mode;                /* 0x522 */
    char pad523[0x526 - 0x523];
    u8 u526;
    char pad527[0x52C - 0x527];
    float wheelRpm[4];      /* 0x52C */
    float f53C;
};
struct Car {
    char pad0[0x10];
    Eng *eng;               /* 0x10 */
    char pad14[0x104 - 0x14];
    Sub sub;                /* 0x104 */
};
struct WheelSet {           /* at Selection + 4 */
    char pad0[8];
    u8 index[4];            /* 0xC */
    u8 kind[4];             /* 0x10 */
    char pad10[0x20 - 0x10];
    u8 pair[4];             /* 0x24 */
};
struct Selection {
    u8 b0;
    u8 b1;
    u8 count;
    u8 b3;
    WheelSet ws;            /* 0x4 */
};

extern "C" float func_00350E28(Car *self) throw();
extern "C" int func_00350F48(Car *self) throw();
extern "C" float func_003554A0(Car *self, float x);
extern "C" float func_00355F80(Car *self);
extern "C" Selection *func_00359510(Eng *e);
extern "C" void func_0035A5F8(Car *self, int a, s8 b);
extern "C" int func_003F1F88(Gear *g);
extern "C" int func_003F1F98(Gear *g);

extern "C" int func_003519B8(Car *self) {
    Sub *s = &self->sub;
    Eng *e = self->eng;
    Gear *g = &e->gear;
    Engine *en = &e->engine;
    float dt = self->sub.dt;
    float v;

    int mode = s->mode;
    if (mode == 0) {
        v = (float)en->minRpm * 0x1.acee9cp-4f;
        float rate;
        if (g->type == 7) rate = func_00355F80(self);
        else rate = func_003554A0(self, s->f494);
        s->rpm += rate * g->fC8 * dt;
        if (s->rpm < v) s->rpm = v;
    } else {
        v = func_00350E28(self);
        if (s->mode == 1) {
            if (func_003F1F98(g)) s->rpm = s->f518 * v;
            else s->rpm = v;
        } else if (s->mode == 2 || s->mode == 3) {
            u8 m;
            if (s->b466 == 1 || s->u467 != 0) m = 0;
            else m = s->u442;
            if ((m == 3 || m == 6) && s->f514 == 1.0f) {
                float r = s->rpm;
                int n = s->gearNo;
                if (func_003F1F88(g)) {
                    if (n >= 2) n = 1;
                }
                r /= g->ratio[n];
                Selection *sel = func_00359510(e);
                for (int i = 0; i < sel->count; i++) {
                    int w = sel->ws.index[i];
                    s->wheelRpm[i] = r;
                    int k = 0;
                    if (i < sel->count) k = *(sel->ws.kind + i);
                    r *= g->scale[k];
                    Wheel *wh = self->sub.wheel + w;
                    wh->f20 = r;
                    w = sel->ws.pair[w];
                    if (w != 0x7F) {
                        wh = self->sub.wheel + w;
                        wh->f20 = r;
                    }
                }
                s->mode = 1;
            } else {
                float hi = s->f510;
                float lo = s->f50C;
                if ((lo <= hi && v <= s->rpm) || (hi <= lo && s->rpm <= v)) {
                    s->mode = 1;
                    s->u526 = 12;
                    s->rpm = v;
                }
            }
            if (s->mode == 3 && s->f510 <= (float)e->engine.minRpm * 0x1.acee9cp-4f)
                s->mode = 0;
            if (s->mode == 2 && s->f48C > 0.75f &&
                (s->rpm < (float)(e->engine.minRpm + 500) * 0x1.acee9cp-4f ||
                 (s->f53C < 0x1.638e36p+1f && s->f53C > -0x1.638e36p+1f)))
                s->mode = 0;
        }
        if (s->rpm < 0.0f) {
            s->rpm = 0.0f;
        } else {
            float limit = (float)(e->engine.maxRpm + 10) * 0x1.acee9cp-4f;
            if (limit <= s->rpm) s->rpm = limit;
        }
    }
    if (s->mode != 3) func_0035A5F8(self, 0, 0);
    return func_00350F48(self);
}
