/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef float f32; typedef unsigned char u8; typedef signed char s8;

struct Rec { char pad0[1]; u8 n; char pad2[0x12]; u8 a[0x18]; u8 c[0x10]; s8 d[0x10]; };
struct Tbl { char pad0[0x10]; f32 f10[71]; };
struct Car { f32 ang; char pad4[0x6C]; f32 f70, f74; char pad78[0xEC - 0x78]; };
struct Obj { char pad0[0x10]; Tbl *tbl; char pad14[0x164 - 0x14]; Car car[1]; };

extern "C" Rec *func_00359510(Tbl *);
extern "C" f32 func_0057D1F0(f32);

static inline int isPos(Rec *r, s32 i, int n) { int result = 0; if (i < n) result = r->d[i] > 0; return result; }
static inline int isNeg(Rec *r, s32 i, unsigned n) { int result = 0; if ((long)i < n) result = r->d[i] < 0; return result; }

extern "C" void func_0036AF30(Obj *self, f32 *outA, f32 *outB) {
    f32 sumB = 0.0f, sumA = 0.0f;
    s32 i;
    Tbl *t = self->tbl;
    Rec *r = func_00359510(t);
    for (i = 0; i < r->n; i++) {
        f32 *g4 = (f32 *)((char *)t + 4);
        f32 *gC = (f32 *)((char *)t + 0xC);
        u8 idx = 0;
        if (i < r->n) idx = r->a[i];
        u8 c = r->c[i];
        Car *car = &self->car[i];
        f32 v = func_0057D1F0(car->ang) * (car->f70 + car->f74) * g4[idx + 0xB0];
        sumA += v * gC[c + 0x48];
        unsigned n = r->n;
        if (isPos(r, i, n)) {
            sumB += v / t->f10[c];
        } else if (isNeg(r, i, n)) {
            sumB -= v / t->f10[c];
        }
    }
    *outA = sumA;
    *outB = sumB;
}
