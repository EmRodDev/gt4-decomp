/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Computes the tire dimensions of one axle (index 0 or 1, probably front and rear) from the car parameter block: tire width (stored in
 * units of 5 mm, then converted to metres), rim radius from the rim code (inches, or tenths of an inch from code 61 up; 0.0254 m per inch is
 * visible in the hex float 0x1.a02752p-6) and sidewall height from the aspect byte (steps of 5 percent of the width). The outer radius is rim
 * radius plus sidewall height and is also the return value. Tuning adjustments then change the rim by whole inches (keeping a minimum) and
 * scale the width, and when 0035A058 says the car uses override tires the values come from the table behind 00359F20 instead. The unit
 * readings are inferred from the constants; the stored sidewallHeight is the third output next to the width. */
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

static inline f32 rimRadius(int rimCode) {
    if (rimCode < 61) return (f32)rimCode * 0x1.a02752p-6f * 0.5f;
    if (rimCode % 10 == 0) return (f32)(rimCode / 10) * 0x1.a02752p-6f * 0.5f;
    return (f32)rimCode * 0x1.a02752p-6f * 0x1.999998p-5f;
}

extern "C" f32 func_0034BA30(CarParam *carParams, int axle, f32 *outerRadius, f32 *width, f32 *sidewallHeight) {
    int widthMm = carParams->tire.width[axle] * 5;
    if (widthMm == 0) widthMm = 10;
    int rimCode = carParams->tire.rim[axle];
    int aspect = carParams->tire.aspect[axle];
    *width = (f32)widthMm * 0x1.0624dcp-10f;
    f32 rim = rimRadius(rimCode);
    f32 sidewall = *width * (f32)aspect * 0x1.999998p-5f;
    *sidewallHeight = sidewall;
    *outerRadius = rim + sidewall;
    int adjustment = carParams->adjust.rim[axle];
    if (adjustment != 0) {
        f32 delta = (f32)adjustment * 0x1.a02752p-6f * 0.5f;
        if (rim + delta < 0x1.a02752p-6f) delta = 0x1.a02752p-6f - rim;
        f32 reducedSide = *sidewallHeight - delta;
        *sidewallHeight = reducedSide;
        if (reducedSide < 0x1.a02752p-7f) *sidewallHeight = 0x1.a02752p-7f;
    }
    adjustment = carParams->adjust.scale[axle];
    if (adjustment != 0 && adjustment != 100) *width *= (f32)adjustment / 100.0f;
    if (func_0035A058(carParams)) {
        TireOverride *override = func_00359F20(carParams);
        if (axle == 0) {
            *width = override->width0;
            *outerRadius = override->total0;
        } else {
            *width = override->width1;
            *outerRadius = override->total1;
        }
        *sidewallHeight = *width * 0.5f;
    }
    return *outerRadius;
}
