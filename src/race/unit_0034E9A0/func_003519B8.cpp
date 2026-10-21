/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-step engine speed update (rpm at +0x4FC of the car's dynamics block). The constant 0x1.acee9cp-4 is 2*pi/60,
 * so the engine limits (minRpm/maxRpm) are converted from rpm to rad/s before comparing (inferred from the value).
 * mode 0: free-running, rpm integrates a rate (func_003554A0, or func_00355F80 for gear type 7) and is floored at the
 * idle speed; mode 1: rpm follows func_00350E28 (wheel-driven, scaled by f518 for some gearboxes); modes 2/3: a gear
 * change in progress, rpm is steered toward the target and handed back to mode 1 (or 0) when it is reached; in the
 * branch with m==3/6 the wheel speeds are written back through the gear ratio table. The meaning of each mode number
 * is inferred from this behaviour only. The result is clamped to [0, maxRpm+10]. */
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
    Sub *dyn = &self->sub;
    Eng *eng = self->eng;
    Gear *gear = &eng->gear;
    Engine *engine = &eng->engine;
    float dt = self->sub.dt;
    float targetRpm;

    int mode = dyn->mode;
    if (mode == 0) {
        targetRpm = (float)engine->minRpm * 0x1.acee9cp-4f;
        float rpmRate;
        if (gear->type == 7) rpmRate = func_00355F80(self);
        else rpmRate = func_003554A0(self, dyn->f494);
        dyn->rpm += rpmRate * gear->fC8 * dt;
        if (dyn->rpm < targetRpm) dyn->rpm = targetRpm;
    } else {
        targetRpm = func_00350E28(self);
        if (dyn->mode == 1) {
            if (func_003F1F98(gear)) dyn->rpm = dyn->f518 * targetRpm;
            else dyn->rpm = targetRpm;
        } else if (dyn->mode == 2 || dyn->mode == 3) {
            u8 driveState;
            if (dyn->b466 == 1 || dyn->u467 != 0) driveState = 0;
            else driveState = dyn->u442;
            if ((driveState == 3 || driveState == 6) && dyn->f514 == 1.0f) {
                float wheelRpmValue = dyn->rpm;
                int gearIndex = dyn->gearNo;
                if (func_003F1F88(gear)) {
                    if (gearIndex >= 2) gearIndex = 1;
                }
                wheelRpmValue /= gear->ratio[gearIndex];
                Selection *selection = func_00359510(eng);
                for (int i = 0; i < selection->count; i++) {
                    int wheelIndex = selection->ws.index[i];
                    dyn->wheelRpm[i] = wheelRpmValue;
                    int kindIndex = 0;
                    if (i < selection->count) kindIndex = *(selection->ws.kind + i);
                    wheelRpmValue *= gear->scale[kindIndex];
                    Wheel *wheelRef = self->sub.wheel + wheelIndex;
                    wheelRef->f20 = wheelRpmValue;
                    wheelIndex = selection->ws.pair[wheelIndex];
                    if (wheelIndex != 0x7F) {
                        wheelRef = self->sub.wheel + wheelIndex;
                        wheelRef->f20 = wheelRpmValue;
                    }
                }
                dyn->mode = 1;
            } else {
                float rangeHigh = dyn->f510;
                float rangeLow = dyn->f50C;
                if ((rangeLow <= rangeHigh && targetRpm <= dyn->rpm) || (rangeHigh <= rangeLow && dyn->rpm <= targetRpm)) {
                    dyn->mode = 1;
                    dyn->u526 = 12;
                    dyn->rpm = targetRpm;
                }
            }
            if (dyn->mode == 3 && dyn->f510 <= (float)eng->engine.minRpm * 0x1.acee9cp-4f)
                dyn->mode = 0;
            if (dyn->mode == 2 && dyn->f48C > 0.75f &&
                (dyn->rpm < (float)(eng->engine.minRpm + 500) * 0x1.acee9cp-4f ||
                 (dyn->f53C < 0x1.638e36p+1f && dyn->f53C > -0x1.638e36p+1f)))
                dyn->mode = 0;
        }
        if (dyn->rpm < 0.0f) {
            dyn->rpm = 0.0f;
        } else {
            float maxLimit = (float)(eng->engine.maxRpm + 10) * 0x1.acee9cp-4f;
            if (maxLimit <= dyn->rpm) dyn->rpm = maxLimit;
        }
    }
    if (dyn->mode != 3) func_0035A5F8(self, 0, 0);
    return func_00350F48(self);
}
