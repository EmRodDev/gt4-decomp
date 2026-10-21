/* compiler: ee-gcc2.96-nogcse */
/* Per-step limiter for the value at q+0x494, which func_003519B8 passes on to func_003554A0 as the 0..1 input of the
 * engine (probably the throttle command; inferred from that use and from the 0.75/0.9 thresholds there). A limit in km/h
 * is taken from a byte table in the owner's data (+0xF818: entries 0x42/0x43 by mode, 0x4B and 0x4C when func_0035FC68 /
 * func_00354E68 say so, 10 when f5C3 is set, or the value func_003F7880 supplies), converted with 0x1.1c71c6p-2 = 1/3.6
 * to m/s (inferred from the constant) and mapped by func_003F76E8 to the largest allowed value, which then lowers
 * +0x494. The last block, only with bit 2 of f4E5 set, uses a quadratic fade of f58C to blend toward a second cap.
 * The modes in f466 and the meaning of the table entries are purpose unknown. Compiled with the nogcse variant. */
typedef int s32;
typedef float f32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

struct Q {
    char p0[0x466];
    s8 f466;
    u8 f467;
    char p468[0x488 - 0x468];
    f32 f488;
    char p48C[0x494 - 0x48C];
    f32 f494;
    char p498[0x4BA - 0x498];
    u16 f4BA;
    char p4BC[0x4E5 - 0x4BC];
    u8 f4E5;
    char p4E6[0x53C - 0x4E6];
    f32 f53C;
    char p540[0x58C - 0x540];
    f32 f58C;
    char p590[0x5C3 - 0x590];
    s8 f5C3;
    char p5C4[0x5F8 - 0x5C4];
    s8 f5F8;
    s8 f5F9;
};

struct Obj {
    char p0[4];
    char *f4;
    char p8[8];
    char *f10;
    char p14[0xF0];
    Q q;
};

extern "C" s32 func_00354E68(Obj *);
extern "C" u16 func_0035FC68(Q *);
extern "C" void func_003F71E8(Obj *) throw();
extern "C" f32 func_003F76E8(Obj *, f32) throw();
extern "C" int func_003F77B8(Obj *) throw();
extern "C" void func_003F7828(Obj *) throw();
extern "C" s32 func_003F7880(Obj *, s32 *) throw();
extern "C" s32 func_003F9470(char *);
extern "C" s32 func_003F9CD0(char *);

static inline float curve(float x, float scale, float bias) {
    return x*x*scale-bias;
}
extern "C" void func_003F79A0(Obj *self)
{
    Q *q = &self->q;
    func_003F71E8(self);
    q->f5F9 = 0;
    q->f5F8 = 0;
    int mode = q->f466;
    if (mode < 3) {
        if (mode <= 0) {
            if (mode == 0) {
                if (q->f467 == 0) {
                    func_003F77B8(self);
                } else if (q->f4BA != 0) {
                    func_003F77B8(self);
                } else {
                    func_003F7828(self);
                    char *gameData = self->f10 + 0x1098;
                    q->f5F9 = func_003F9CD0(gameData);
                    q->f5F8 = func_003F9470(gameData);
                }
            }
        } else {
            func_003F7828(self);
            q->f5F9 = 0;
            q->f5F8 = 0;
        }
    }
    char *settings = self->f4 + 0xF818;
    s32 limitKmh;
    int mode2 = q->f466;
    if (mode2 != 2) {
        limitKmh = (u8)settings[0x42];
    } else {
        limitKmh = (u8)settings[0x43];
    }
    if (func_0035FC68(q) != 0) {
        s32 tableLimit = (u8)settings[0x4B];
        if (limitKmh == 0 || tableLimit < limitKmh) limitKmh = tableLimit;
    }
    if (func_00354E68(self) != 0) {
        s32 tableLimit = (u8)settings[0x4C];
        if (limitKmh == 0 || tableLimit < limitKmh) limitKmh = tableLimit;
    }
    if (q->f5C3 != 0) limitKmh = 10;
    s32 sp[4];
    sp[0] = 0;
    if ((func_003F7880(self, sp) ^ 1) == 0) limitKmh = sp[0];
    if (limitKmh != 0) {
        f32 throttleCap = func_003F76E8(self, (f32)limitKmh * 0x1.1c71c6p-2f);
        if (throttleCap < q->f494) q->f494 = throttleCap;
    }
    if (q->f4E5 & 2) {
        if (q->f466 == 0 || q->f466 == 3) {
            if (q->f467 == 0) {
                f32 blendedCap = func_003F76E8(self, q->f53C);
                f32 fade = curve(q->f58C, 1.5f, 0x1.333332p-3f);
                if (fade > 1.0f) fade = 1.0f;
                else if (fade < 0.0f) fade = 0.0f;
                blendedCap = blendedCap * fade;
                if (q->f488 < blendedCap) q->f494 = blendedCap;
            }
        }
    }
}
