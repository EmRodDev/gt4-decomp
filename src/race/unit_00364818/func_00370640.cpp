/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Same free-moving camera step as func_00370960 but without the turn input and with the simpler hit test
 * func_003FECB0 (inferred from the near-identical body): steps x/y by the input times a per-axis gain, clamps to the
 * owner's limits rectangle (+-500 when empty), keeps z38 at 0, and stores the hit result at +0x40. */
typedef float f32;

struct Limits {
    char pad0[0x28];
    f32 min_x;
    f32 min_y;
    f32 max_x;
    f32 max_y;
    char pad38[0x14];
    f32 lo_x;
    f32 lo_y;
    f32 hi_x;
    f32 hi_y;
};
struct Info { char pad0[0xCC]; Limits *limits; };
struct Owner { char pad0[4]; Info *info; };
struct Input { char pad0[0x30]; f32 move_x; f32 move_y; f32 turn; };
struct Cam {
    Owner *owner;
    char pad4[0x18];
    f32 unk1C;
    char pad20[0x8];
    f32 unk28[3];
    f32 x;
    f32 z38;
    f32 y;
    int unk40;
    char unk44[0x3C];
};

extern "C" f32 func_0036FD98(Cam *) throw();
extern "C" f32 func_003701B8(Input *, f32, f32) throw();
extern "C" f32 func_0036FF38(Cam *, f32) throw();
extern "C" f32 func_0036FF78(Cam *, f32) throw();
extern "C" f32 func_0036F6A0(void *, int, f32) throw();
extern "C" void func_003704D0(Cam *, f32, f32) throw();
extern "C" void func_005F5040(void *, void *);
extern "C" int func_003FECB0(f32 *, Owner *, f32);

extern "C" void func_00370640(Cam *self, Input *in)
{
    f32 speed = 6.0f;
    Limits *lim = self->owner->info->limits;
    f32 my;
    f32 mx;
    f32 gainX;
    f32 gainY;
    f32 min_x;
    f32 max_x;
    f32 min_y;
    f32 max_y;
    f32 inputScale;
    f32 tmp[4];
    int hitIndex;

    self->unk1C = func_003701B8(in, self->unk1C, func_0036FD98(self));
    my = in->move_y;
    mx = in->move_x;
    gainX = func_0036FF38(self, speed);
    gainY = func_0036FF78(self, speed);
    min_x = lim->min_x;
    max_x = lim->max_x;
    min_y = lim->min_y;
    max_y = lim->max_y;
    if (max_x <= min_x || max_y <= min_y) {
        min_x = -500.0f;
        max_x = 500.0f;
        min_y = min_x;
        max_y = max_x;
    }
    if (min_x < lim->lo_x)
        min_x = lim->lo_x;
    if (lim->hi_x < max_x)
        max_x = lim->hi_x;
    if (min_y < lim->lo_y)
        min_y = lim->lo_y;
    if (lim->hi_y < max_y)
        max_y = lim->hi_y;
    {
        int moving = 0;
        if (my != 0.0f || mx != 0.0f)
            moving = 1;
        inputScale = func_0036F6A0(self->unk44, moving, 1.0f);
    }
    {
        f32 *px = &self->x;
        f32 *py;
        mx *= inputScale;
        my *= inputScale;
        *px += mx * gainX;
        self->z38 = 0;
        py = &self->y;
        *py += my * gainY;
        if (*px <= min_x)
            *px = min_x;
        if (max_x <= *px)
            *px = max_x;
        if (*py <= min_y)
            *py = min_y;
        if (max_y <= *py)
            *py = max_y;
        func_003704D0(self, *px, *py);
        func_005F5040(px, self->unk28);
        func_005F5040(px, tmp);
    }
    hitIndex = func_003FECB0(tmp, self->owner, func_0036FF78(self, 24.0f));
    if (hitIndex >= 0)
        func_005F5040(tmp, self->unk28);
    self->unk40 = hitIndex;
}
