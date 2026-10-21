/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-frame pass over the car's wheels (count taken from the record at func_00359510): each wheel keeps a
 * contact timer (set to 6 while f48 is non-zero, counted down otherwise); while it runs, three output values
 * (+0xB4, +0xB8, +0xBC) are computed from table lookups (func_00359830) on speed and on a rotated pair
 * (cos/sin of the wheel angle applied to f28/f2C), then combined with sqrt(x*x + y*y) and per-class slope terms.
 * The wheel kind (+0x89) selects one of three classes (switch) that indexes the curve tables.
 * The sum of the third output over class!=0 wheels (x4 when the course type is 0) is scaled and handed to
 * func_003438C8 at the end. Purpose unknown in game terms (looks like a per-wheel ground/tyre response; inferred
 * from the shape only). The sqrt is an inline sqrt.s asm helper and the offsets 0xEC/0x164 index the wheel array. */
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
    f32 classedTotal = 0.0f;
    Rec *wheelRecord = func_00359510(self->m10);

    for (i = 0; i < wheelRecord->n; i++) {
        Wheel *w = wheelAt(self, i);
        if (w->f48 != 0.0f) w->timer = 6;
        else if (w->timer) w->timer--;
        if (w->timer == 0) {
            w->outB4 = 0.0f;
            w->outB8 = 1.0f;
            w->outBC = 0.0f;
        } else {
            s32 kindClass = 0;
            s32 kind;
            f32 speedAbs, rotatedAbsA, valueF38, rotatedB, angle;
            switch (w->kind) {
            case 2:
            case 3:
            case 4:
            case 5:
            case 13:
            case 14:
                kindClass = 1;
                break;
            case 6:
            case 20:
            case 21:
            case 22:
                kindClass = 2;
                break;
            }
            speedAbs = wheelAt(self, i)->f34;
            if (speedAbs < 0.0f) speedAbs = -speedAbs;
            angle = w->angle;
            f32 scaleT = func_0057D1F0(angle) * w->f2C;
            rotatedAbsA = scaleT + func_0057D2B8(angle) * w->f28;
            if (rotatedAbsA < 0.0f) rotatedAbsA = -rotatedAbsA;
            f32 angle2 = w->angle;
            valueF38 = w->f38;
            f32 rotatedProduct = func_0057D1F0(angle2) * w->f28;
            rotatedB = rotatedProduct - func_0057D2B8(angle2) * w->f2C;
            f32 f20 = w->f20;
            f32 deviationAbs = rotatedB - f20;
            if (rotatedB < 0.0f) deviationAbs = -deviationAbs;
            kind = w->kind;
            u8 kindByte = kind;
            if (kindByte != 1 && kindByte != 10 && kindByte != 11 && kindByte != 21) {
                s32 firstContactFlag = 0;
                f32 curveX, curveY;
                curveX = !D_006224B0.a[kindClass].x ? speedAbs : rotatedAbsA;
                curveX = func_00359830(&D_00843A20[kindClass].x, curveX);
                curveY = !D_006224B0.a[kindClass].y ? valueF38 : deviationAbs;
                curveY = func_00359830(&D_00843A20[kindClass].y, curveY);
                f32 outB4Value = root(curveY * curveY + curveX * curveX);
                curveX = w->f40 - D_00843A20[kindClass].threshold;
                if (curveX > 0.0f) outB4Value += curveX * D_00843A20[kindClass].slope;
                if (outB4Value != 0.0f) outB4Value += D_00843A20[kindClass].base;
                if (w->outB4 == D_00843A20[kindClass].base) {
                    if (outB4Value != D_00843A20[kindClass].base) firstContactFlag = 1;
                }
                w->outB4 = outB4Value;
                curveX = !D_006224B0.b[kindClass].x ? speedAbs : rotatedAbsA;
                curveX = func_00359830(&D_00843C30[kindClass].x, curveX);
                curveY = !D_006224B0.b[kindClass].y ? valueF38 : deviationAbs;
                curveY = func_00359830(&D_00843C30[kindClass].y, curveY);
                f32 outB8Value = D_00843C30[kindClass].base + root(curveY * curveY + curveX * curveX);
                curveX = w->f40 - D_00843C30[kindClass].threshold;
                if (curveX > 0.0f) outB8Value += curveX * D_00843C30[kindClass].slope;
                if (firstContactFlag && (i & 1)) outB8Value *= 0.75f;
                w->outB8 = outB8Value;
                kind = w->kind;
            } else {
                Special *special = &D_00844050;
                f32 ratio = w->f48 / 0x1.323ffep+11f - 0.25f;
                if (ratio < 0.0f) ratio = 0.0f;
                else if (ratio > 1.0f) ratio = 1.0f;
                f32 scaleT = ratio;
                ratio = f20;
                if (ratio < 0.0f) ratio = -ratio;
                f32 slipScale = (ratio - 0x1.638e36p+0f) * 0x1.26e97ap-3f;
                if (slipScale < 0.0f) slipScale = 0.0f;
                else if (slipScale > 1.0f) slipScale = 1.0f;
                w->outB4 = slipScale * scaleT * special->scale;
                f32 interp;
                if (ratio <= special->lo) {
                    interp = special->loValue;
                } else if (ratio >= special->hi) {
                    interp = special->hiValue;
                } else {
                    interp = special->loValue + ((ratio - special->lo) * (special->hiValue - special->loValue)) / (special->hi - special->lo);
                }
                w->outB8 = interp;
            }
            if (kind == 12) kindClass = 1;
            f32 curveX = !D_006224B0.c[kindClass].x ? speedAbs : rotatedAbsA;
            curveX = func_00359830(&D_00843E40[kindClass].x, curveX);
            f32 curveY = !D_006224B0.c[kindClass].y ? valueF38 : deviationAbs;
            curveY = func_00359830(&D_00843E40[kindClass].y, curveY);
            f32 outBCValue = root(curveY * curveY + curveX * curveX);
            curveX = w->f40 - D_00843E40[kindClass].threshold;
            if (curveX > 0.0f) outBCValue += curveX * D_00843E40[kindClass].slope;
            if (w->kind == 8) outBCValue = 0.0f;
            if (outBCValue != 0.0f) outBCValue += D_00843E40[kindClass].base;
            if (outBCValue > 1.0f) outBCValue = 1.0f;
            w->outBC = outBCValue;
            if (kindClass) classedTotal += outBCValue;
        }
    }
    if (DynamicsConductor__getCourseType(self->m4) == 0) classedTotal *= 4.0f;
    return func_003438C8(self->sub6DC, classedTotal * 0x1.0624dcp-11f * self->f54C);
}
