/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef float f32;

struct SlowCarBoostParam {
    u8 x0;
    u8 frontAngle;
    u8 frontRate;
    u8 x3;
    u8 x4;
    u8 x5;
    u8 rearAngle;
    u8 rearRate;
    u8 x8;
    u8 x9;
    u8 xA;
    u8 low;
    u8 high;
    u8 xD;
    u8 xE;
    u8 offset2;
    u8 offset3;
};

struct SlowCarBoost {
    f32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    f32 x10;
    f32 x14;
    f32 x18;
    f32 x1C;
    f32 low;
    f32 high;
    f32 x28;
    f32 x2C;
    f32 slope;
};

struct DynamicsConductor;

extern SlowCarBoostParam D_006202B0;
extern SlowCarBoost D_006202C8;

extern "C" unsigned char DynamicsConductor__getCourseType(DynamicsConductor *self);

extern "C" void DynamicsConductor__SetupSlowCarBoost(DynamicsConductor *self) {
    int low;
    int high;

    D_006202C8.x0 = D_006202B0.frontAngle * 0x1.c9870ap-10f;
    D_006202C8.x4 = D_006202B0.frontRate * 0.1f;
    D_006202C8.x8 = D_006202B0.x3;
    D_006202C8.xC = D_006202B0.x4;
    D_006202C8.x10 = D_006202B0.rearAngle * 0x1.c9870ap-10f;
    D_006202C8.x14 = D_006202B0.rearRate * 0.1f;
    D_006202C8.x18 = D_006202B0.x8;
    D_006202C8.x1C = D_006202B0.x9;
    low = D_006202B0.low;
    high = D_006202B0.high;
    if (low == high)
        high = low + 1;
    switch (DynamicsConductor__getCourseType(self)) {
    case 2:
        low += D_006202B0.offset2;
        high += D_006202B0.offset2;
        break;
    case 3:
        low += D_006202B0.offset3;
        high += D_006202B0.offset3;
        break;
    }
    D_006202C8.low = low * 0x1.1c71c6p-2f;
    D_006202C8.high = high * 0x1.1c71c6p-2f;
    D_006202C8.x28 = D_006202B0.xD * 0x1.1c71c6p-2f;
    D_006202C8.x2C = D_006202B0.xE * 0x1.1c71c6p-2f;
    D_006202C8.slope = (D_006202C8.x2C - D_006202C8.x28) / (D_006202C8.high - D_006202C8.low);
}
