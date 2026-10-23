/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Slow-car boost spring for the other axis: twin of func_0034A788 with the first parameter flag,
   func_00344858/func_00344978 as the two inputs, the spring at +0x14 of the 0x30-byte record and
   the first four boost coefficients (cap, gain, stiffness, damping), stepped at 1/60 s. */
typedef unsigned char u8;
typedef float f32;

struct SlowCarBoostParam {
    u8 x0;
    u8 frontAngle;
    u8 frontRate;
    u8 x3;
    u8 x4;
    u8 x5;
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
};

struct Spring {
    char pad[0x14];
    f32 vel;
    f32 pos;
};

struct Obj {
    char pad0[4];
    char *unk4;
    char pad1[0x544 - 8];
    u8 unk544;
};

extern SlowCarBoostParam D_006202B0;
extern SlowCarBoost D_006202C8;
extern "C" f32 func_00344858(Obj *, f32) throw();
extern "C" f32 func_00344978(Obj *, f32) throw();

static inline SlowCarBoost *boost() { return &D_006202C8; }

extern "C" void func_0034A668(Obj *o) {
    if (D_006202B0.x0 != 0) {
        Spring *s = (Spring *)(o->unk4 + o->unk544 * 0x30 + 0xCAB8);
        f32 a = func_00344858(o, 0.0f);
        f32 diff = a - func_00344978(o, 0.0f);
        f32 cap = boost()->x0;
        if (cap < diff || (cap = -cap, diff < cap)) diff = cap;
        diff *= boost()->x4;
        s->vel += (boost()->x8 * (diff - s->pos) - boost()->xC * s->vel) * 0x1.111110p-6f;
        s->pos += s->vel * 0x1.111110p-6f;
    }
}
