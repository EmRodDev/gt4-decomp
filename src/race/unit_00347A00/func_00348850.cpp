/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32; typedef int s32; typedef unsigned int u32; typedef short s16; typedef unsigned char u8; typedef signed char s8;

struct Info { u8 tag, count; char pad[0x3A]; s8 signs[16]; };
struct Wheel { char pad0[0x30]; f32 load; char pad34[0x89 - 0x34]; u8 surface; char pad8A[0xEC - 0x8A]; };
struct Config {
    char pad0[0x10]; f32 f10;
    char pad14[0x54 - 0x14]; f32 limit;
    char t58[0x3C];
    char t94[0x3C];
    char tD0[0x10D3 - 0xD0];
    u8 b10D3;
};
struct State {
    char pad0[0x44C]; f32 f44C;
    char pad450[0xC]; f32 f45C;
    char pad460[5]; u8 b465; char pad466[2]; f32 f468;
    char pad46C[0x498 - 0x46C]; f32 f498; f32 f49C; f32 f4A0; f32 f4A4;
    char pad4A8[9]; u8 b4B1;
    char pad4B2[0x4E5 - 0x4B2]; u8 b4E5;
    char pad4E6[0x53C - 0x4E6]; f32 f53C; f32 f540;
    char pad544[0x570 - 0x544]; f32 f570;
    char pad574[8]; f32 f57C;
    char pad580[0x62C - 0x580]; u8 b62C;
    char pad62D[0x63C - 0x62D]; f32 f63C;
};
struct Ident { char pad0[0x1C]; u8 key; u8 index; };
struct Obj {
    char pad0[4]; char *course; char pad8[8]; Config *cfg;
    Ident id;
    u8 b32;
    char pad33[0x54C - 0x33]; f32 rate;
};
struct Input { u8 flags; u8 mode; char pad2[2]; s16 value; };

extern "C" Info *func_00359510(Config *);
extern "C" void func_00348588(f32 *p, f32 target, f32 step) throw();
extern "C" void func_003485D0(Obj *, f32, int, f32, int) throw();
extern "C" s8 func_003487F8(Obj *) throw();
extern "C" f32 func_00348800(f32) throw();
extern "C" int DynamicsConductor__getCourseType(char *);
extern "C" f32 func_00359830(void *t, f32 x);
extern "C" f32 func_0035A9D0(void *self, f32 *derivative, f32 input);
extern "C" f32 func_0036CC40(f32 a, f32 b);
extern "C" f32 func_004649F0(void *obj, int key, int idx, f32 *ox, f32 *oy, f32 *oz, f32 t);
extern "C" f32 func_0057D118(f32 y, f32 x);

extern u8 D_00622110[];
extern u8 D_00620288[];
extern f32 D_00843538[];
extern f32 D_00620248, D_0062024C, D_00620250, D_00620254, D_00620258;
extern f32 D_0062025C, D_00620260, D_00620264;
extern f32 D_00843568, D_0084356C, D_00843570, D_00843574, D_00843578;
extern s32 D_0084357C, D_0084358C;
extern f32 D_00843580, D_00843584, D_00843588, D_00843590;

static inline int positive(Info *p, int n) { if (n >= p->count) return 0; return p->signs[n] > 0; }

static inline u8 *settings() { return D_00622110; }
static inline u8 isAnalog(Input *in) { return in->flags & 1; }
static inline int isFree(State *st) { return (st->b4B1 & 1) == 0; }

static inline f32 correction(State *st, Config *cfg, f32 avg) {
    f32 d = func_0057D118(-(st->f540 - (st->f57C + st->f63C * D_00843570) * cfg->f10), st->f53C) - avg;
    f32 k = 1.0f;
    if (st->f53C < D_00843578) k = st->f53C / (D_00843578 - D_00843574);
    d *= k;
    return d;
}

extern "C" void func_00348850(Obj *self, Input *in) {
    State *st = (State *)((char *)self + 0x104);
    f32 avg = 0.0f;
    Config *cfg = self->cfg;
    Info *info = func_00359510(cfg);
    f32 rate = self->rate;
    int n = 0;
    for (int i = 0; i < info->count; i++) {
        if (positive(info, i)) {
            avg += ((Wheel *)((char *)self + 0x164))[i].load;
            n++;
        }
    }
    avg /= (f32)n;
    int surf = 2;
    f32 maxSteer = st->f53C;
    int type = 0;
    for (int i = 0; i < info->count; i++) {
        if (positive(info, i)) {
            int s = D_00620288[((Wheel *)((char *)self + 0x164))[i].surface];
            if (s < surf) surf = s;
        }
    }
    if ((u32)surf >= 2) surf = 0;
    switch (DynamicsConductor__getCourseType(self->course)) {
    case 0: type = 0; break;
    case 1: type = 0; break;
    case 2: type = 1; break;
    case 3: type = 1; break;
    }
    if (maxSteer < 0.0f) maxSteer = 0.0f;
    if (in->mode == 6) {
        maxSteer = cfg->limit;
    } else if (in->mode != 4) {
        type = surf;
        if (type != 1) maxSteer = func_00359830(cfg->t58, maxSteer);
        else maxSteer = func_00359830(cfg->tD0, maxSteer);
    } else {
        if (type != 1) maxSteer = func_00359830(cfg->t94, maxSteer);
        else maxSteer = func_00359830(cfg->tD0, maxSteer);
    }
    int assist = 1;
    if (in->mode == 4) {
        f32 m;
        switch (func_003487F8(self)) {
        case 3:
            assist = 0;
        case 1:
            if (type != 1) m = D_0062024C;
            else m = D_00620250;
            if (maxSteer < m) maxSteer = m;
            break;
        case 2:
            if (type != 1) m = D_00620254;
            else m = D_00620258;
            if (maxSteer < m) maxSteer = m;
            break;
        case 4:
            assist = 0;
            break;
        }
    } else {
        assist = in->mode != 6;
    }
    f32 hi = maxSteer;
    f32 lo = -hi;
    if (assist) {
        f32 yaw = st->f63C;
        f32 hi2 = hi;
        f32 lo2 = lo;
        if (settings()[0x26] != 0) {
            if (st->f53C > 0x1.638e36p+1f) {
                if (yaw * st->f57C > 0.0f) {
                    f32 d = func_0057D118(-(st->f540 - (st->f57C + yaw * D_00843568) * cfg->f10), st->f53C) - avg;
                    if (st->f57C > 0.0f) {
                        hi2 = hi - d;
                        if (settings()[0x26] < 2) {
                            if (hi2 < 0.0f) hi2 = 0.0f;
                        }
                    } else if (st->f57C < 0.0f) {
                        lo2 = lo - d;
                        if (settings()[0x26] < 2) {
                            if (lo2 > 0.0f) lo2 = 0.0f;
                        }
                    }
                }
            }
        }
        f32 c = avg;
        if (settings()[0x22] != 0) {
            c = avg - (func_0057D118(-(st->f540 - (st->f57C + yaw * D_0084356C) * cfg->f10), st->f53C) - avg);
        }
        if (lo <= avg && avg <= maxSteer) {
            if (settings()[0x26] != 0) {
                hi = hi2;
                lo = lo2;
            }
        } else if (avg > 0.0f) {
            hi = avg;
            if (settings()[0x22] != 0 && yaw > 0.0f && st->f57C < 0.0f) {
                if (settings()[0x22] == 2) {
                    if (c < 0.0f) c = 0.0f;
                    hi = c;
                } else if (maxSteer < c) {
                    hi = c;
                }
            }
            if (settings()[0x26] != 0) lo = lo2;
        } else if (avg < 0.0f) {
            if (settings()[0x26] != 0) hi = hi2;
            lo = avg;
            if (settings()[0x22] != 0 && yaw < 0.0f && st->f57C > 0.0f) {
                if (settings()[0x22] == 2) {
                    if (c > 0.0f) c = 0.0f;
                    lo = c;
                } else if (c < -maxSteer) {
                    lo = c;
                }
            }
        }
    }
    if (hi > cfg->limit) hi = cfg->limit;
    if (lo < -cfg->limit) lo = -cfg->limit;
    int digital = 0;
    if (!isAnalog(in) || in->mode == 3 || in->mode == 2) digital = 1;
    int hold = 0;
    if (digital && isFree(st)) {
        if (0x1.0aaaa8p+3f <= st->f53C && st->b62C == 0) {
            if (D_0084358C != 1 || in->value == 0) {
                if (D_0084357C == 2 || (D_0084357C == 1 && self->b32 == 0)) hold = 1;
            }
        }
    }
    f32 steer;
    if (in->mode == 4) {
        st->b465 = 0;
        f32 input = (f32)in->value * 0x1p-12f;
        st->f45C = input * 0x1.1c71c6p+0f;
        f32 out;
        switch (func_003487F8(self)) {
        case 0 ... 3:
            func_00348588(&st->f49C, hi, D_00620248 * rate);
            func_00348588(&st->f498, lo, D_00620248 * rate);
            if (input >= 0.0f) out = st->f49C * input;
            else out = -st->f498 * input;
            break;
        case 4:
            out = cfg->limit * input;
            break;
        default:
            out = 0.0f;
            break;
        }
        st->f468 = out;
    } else if (in->mode == 6) {
        st->b465 = 3;
        int curve = 0;
        steer = (f32)in->value;
        st->f45C = steer * 5.0f * 0x1p-12f;
        f32 k;
        int t = DynamicsConductor__getCourseType(self->course);
        if (t != 2 && t != 3) {
            curve = 1;
            if (cfg->b10D3) k = D_00620260;
            else k = D_0062025C;
        } else {
            k = D_00620264;
        }
        steer *= k;
        if (steer > 1.0f) steer = 1.0f;
        else if (steer < -1.0f) steer = -1.0f;
        if (cfg->b10D3 && curve) steer = func_0035A9D0(D_00843538, 0, steer);
        st->f468 = cfg->limit * steer;
        st->f49C = hi;
        st->f498 = lo;
    } else if (digital) {
        st->f49C = hi;
        st->f498 = lo;
        s16 v = in->value;
        if (!isAnalog(in)) {
            if (v > 0) steer = hi;
            else if (v < 0) steer = lo;
            else steer = 0.0f;
        } else {
            f32 x = (f32)v * 0x1p-12f;
            if (x >= 0.0f) steer = hi * x;
            else steer = -lo * x;
        }
        if (v != 0) {
            if (in->mode == 2) st->b465 = 2;
            else st->b465 = 1;
        }
        if (st->b4E5 & 0x10) {
            if (D_00843574 < st->f53C) steer -= correction(st, cfg, avg);
        }
        if (hold) {
            f32 tmp;
            Ident *id = &self->id;
            f32 a = func_004649F0(self->course + 0xDA50, id->key, id->index, &tmp, &tmp, &tmp, st->f4A4);
            a = func_0036CC40(st->f570, a);
            f32 m = D_00843590;
            if (!(a < -m) && !(m < a)
                && !(D_0084358C == 2 && ((a > 0.0f && in->value > 0) || (a < 0.0f && in->value < 0)))) {
                f32 da = a - st->f4A0;
                st->f4A0 = a;
                f32 x = -a * D_00843580 - da * st->f44C * D_00843584;
                if (x > D_00843588) x = D_00843588;
                else if (x < -D_00843588) x = -D_00843588;
                steer += x;
            }
        }
        if (st->b465 == 1) func_003485D0(self, steer, type, avg, 0);
        else func_003485D0(self, steer, type, avg, 1);
    }
    if (in->mode == 4 || in->mode == 6) {
        if (st->b4E5 & 8) {
            if (D_00843574 < st->f53C) {
                st->f468 -= correction(st, cfg, avg);
                if (st->f468 > cfg->limit) st->f468 = cfg->limit;
                else if (st->f468 < -cfg->limit) st->f468 = -cfg->limit;
            }
        }
    }
    if (!hold) st->f4A0 = 0.0f;
    switch (st->b465) {
    case 1:
    case 2:
        st->f45C = func_00348800(st->f468);
        break;
    }
}
