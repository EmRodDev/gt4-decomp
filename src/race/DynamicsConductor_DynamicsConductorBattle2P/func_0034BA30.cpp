/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef signed char s8;
typedef unsigned char u8;
typedef float f32;

struct TireSpec {
    char pad0[8];
    u8 width[2];
    u8 rim[2];
    u8 aspect[2];
};

struct TireAdjust {
    char pad0[2];
    s8 rim[2];
    u8 scale[2];
};

struct CarParam {
    char pad0[0x1C0];
    TireSpec tire;
    char pad1CE[0x1E0 - 0x1CE];
    TireAdjust adjust;
};

struct TireOverride {
    f32 total0;
    f32 width0;
    f32 total1;
    f32 width1;
};

extern "C" TireOverride *func_00359F20(CarParam *);
extern "C" int func_0035A058(CarParam *);

static inline f32 rimRadius(int d) {
    if (d < 61) return (f32)d * 0x1.a02752p-6f * 0.5f;
    if (d % 10 == 0) return (f32)(d / 10) * 0x1.a02752p-6f * 0.5f;
    return (f32)d * 0x1.a02752p-6f * 0x1.999998p-5f;
}

extern "C" f32 func_0034BA30(CarParam *self, int index, f32 *total, f32 *width, f32 *side) {
    int w = self->tire.width[index] * 5;
    if (w == 0) w = 10;
    int d = self->tire.rim[index];
    int aspect = self->tire.aspect[index];
    *width = (f32)w * 0x1.0624dcp-10f;
    f32 rim = rimRadius(d);
    f32 h = *width * (f32)aspect * 0x1.999998p-5f;
    *side = h;
    *total = rim + h;
    int adj = self->adjust.rim[index];
    if (adj != 0) {
        f32 delta = (f32)adj * 0x1.a02752p-6f * 0.5f;
        if (rim + delta < 0x1.a02752p-6f) delta = 0x1.a02752p-6f - rim;
        f32 v = *side - delta;
        *side = v;
        if (v < 0x1.a02752p-7f) *side = 0x1.a02752p-7f;
    }
    adj = self->adjust.scale[index];
    if (adj != 0 && adj != 100) *width *= (f32)adj / 100.0f;
    if (func_0035A058(self)) {
        TireOverride *o = func_00359F20(self);
        if (index == 0) {
            *width = o->width0;
            *total = o->total0;
        } else {
            *width = o->width1;
            *total = o->total1;
        }
        *side = *width * 0.5f;
    }
    return *total;
}
