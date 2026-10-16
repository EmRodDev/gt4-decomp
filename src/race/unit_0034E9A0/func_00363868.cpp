/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

struct GearData {
    char pad0[0x60];
    float ratio[12];        /* Eng + 0x29C */
    float tbl[2];           /* Eng + 0x2CC */
};
struct Gear {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    int pad4;
    GearData d;             /* Eng + 0x23C */
};
struct Eng {
    char pad0[0x134];
    char a134[0xCC];
    u16 u200;
    u16 u202;
    char pad204[0x21C - 0x204];
    float f21C;
    char pad220[0x230 - 0x220];
    float f230;
    Gear gear;              /* 0x234 */
    char pad2D4[0xFD8 - 0x2D4];
    float fFD8;
};
struct Wheel {
    char pad0[0x20];
    float f20;
    char pad24[4];
    float f28;
    char pad2C[0xEC - 0x2C];
};
struct Sub {                /* at Car + 0x104 */
    char pad0[0xC];
    float src[3];           /* 0xC */
    char pad18[0x60 - 0x18];
    Wheel wheel[4];         /* 0x60 */
    char pad410[0x488 - 0x410];
    float f488;
    char pad48C[0x494 - 0x48C];
    float f494;
    char pad498[0x4F0 - 0x498];
    float f4F0;
    s16 s4F4;
    s16 s4F6;
    u16 u4F8;
    s16 rpm;
    float f4FC;
    float f500;
    float f504;
    float f508;
    char pad50C[0x514 - 0x50C];
    float f514;
    float f518;
    char pad51C[0x520 - 0x51C];
    u8 u520;
    char pad521;
    u8 u522;
    char pad523[0x52C - 0x523];
    float out[2];           /* 0x52C */
    char pad534[0x53C - 0x534];
    float f53C;
    s32 s540;
    float dst[3];           /* 0x544 */
    char pad550[0x57C - 0x550];
    s32 s57C;
    char pad580[0x607 - 0x580];
    u8 u607;
};
struct Car {
    char pad0[0x10];
    Eng *eng;               /* 0x10 */
    char m14[0x104 - 0x14]; /* 0x14 */
    Sub sub;                /* 0x104 */
};
struct Info {
    u8 b0;
    u8 count;
};

extern "C" void func_00363538(Car *self, float v) throw();
extern "C" s32 func_0036BF68(Car *self, float limit);
extern "C" void func_0036BEB8(Car *self, s32 gear);
extern "C" s32 func_003F1FB0(Gear *gear, float *a, float *b);
extern "C" float func_0034ECF0(void *p, s16 a, s16 b, float *out);
extern "C" s32 func_00463B98(void *p);
extern "C" Info *func_00359510(Eng *e) throw();

extern "C" void func_00363868(Car *self, float lim) {
    Eng *e = self->eng;
    Sub *s = &self->sub;
    float buf[4];
    int i;

    if (e->fFD8 < lim) lim = e->fFD8;
    s->s57C = 0;
    for (i = 0; i < 3; i++) s->dst[i] = s->src[i] * lim;
    func_00363538(self, lim);
    func_0036BEB8(self, func_0036BF68(self, lim));
    s->f4FC = lim * e->gear.d.ratio[s->u520];
    s->f518 = 1.0f;
    func_003F1FB0(&e->gear, &s->f4FC, &s->f518);
    float lo = (float)e->u202 * 0x1.acee9cp-4f;
    if (s->f4FC < lo) {
        s->f4FC = lo;
    } else {
        float hi = (float)e->u200 * 0x1.acee9cp-4f;
        if (hi < s->f4FC) s->f4FC = hi;
    }
    int rpm = (int)(s->f4FC * 60.0f / 0x1.921fb4p+2f);
    s->rpm = rpm;
    if (e->f230 != 0.0f) {
        s->s4F4 = rpm;
        if (0.0f < e->f21C) s->s4F6 = rpm;
        s->f508 = func_0034ECF0(e->a134, s->rpm, s->rpm, buf);
        s->f500 = 1.0f;
        s->f4F0 = 1.0f;
        s->u4F8 = s->rpm;
        s->f504 = 0.0f;
        s->u607 = 0;
    }
    if (func_00463B98(self->m14) != 0) {
        s->f488 = 1.0f;
        s->f494 = 1.0f;
    }
    s->u522 = 1;
    s->f514 = 1.0f;
    s->s540 = 0;
    s->f53C = lim;
    Info *info = func_00359510(e);
    for (i = 0; i < info->count; i++) {
        Wheel *w = &self->sub.wheel[i];
        w->f20 = lim;
        w->f28 = lim;
    }
    for (i = 0; i < 2; i++) {
        Gear *g = &e->gear;
        float v = g->d.tbl[i];
        if (g->b1) v = g->d.tbl[g->b3];
        s->out[i] = v * lim;
    }
}
