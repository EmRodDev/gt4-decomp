/* compiler: ee-gcc2.96-no-strict-aliasing */
/* DevelopCamera::virtual_20 (CameraSys::CameraManager): reset the manager and its six windows. */
typedef int s32;
typedef float f32;
typedef unsigned long long u64;

struct VEntry { short delta; short index; void (*fn)(void *); };
struct VObj { VEntry *vt; };

union Flags { unsigned char b[4]; s32 w; };
union Flags64 { u64 w; unsigned char b[8]; };

struct Window {
    char target[0xD0];      /* 0x000 */
    char control[0x58];     /* 0x0D0: CameraSys::CameraControl */
    s32 f128;
    s32 f12C;
    s32 f130;
    s32 f134;
    s32 mode;               /* 0x138 */
    char f13C[0xC];
    VObj *objs[14];         /* 0x148 */
    void *f180;
    s32 f184;
    Flags flags;            /* 0x188 */
    s32 index;              /* 0x18C */
    s32 f190;
    s32 mount;              /* 0x194 */
    s32 f198;
};

struct History {
    s32 count;
    s32 last;
    s32 a[6];
    s32 b[6];
};

struct Car84 { char pad[0xD2C]; s32 fD2C; };
struct InfoB0 { char pad[0x34]; s32 count; };
struct Info4 { char pad[0xB0]; InfoB0 *pB0; };
struct Info80 { char pad[4]; Info4 *p4; };
struct Car { char pad[0x80]; Info80 *p80; Car84 *p84; };

struct CameraManager {
    void *vptr;
    s32 random;             /* 0x004 */
    s32 displayEnable;      /* 0x008 */
    s32 replayMode;         /* 0x00C */
    Window win[6];          /* 0x010 */
    s32 windowMax;          /* 0x9B8 */
    s32 current;            /* 0x9BC */
    char f9C0[0x80];
    f32 m0[4][4];           /* 0xA40 */
    f32 m1[4][4];           /* 0xA80 */
    s32 fAC0;
    s32 fAC4;
    s32 fAC8;
    History hist;           /* 0xACC */
    char pad[0xB80 - 0xB04];
    char fB80[0x40];
    char fBC0[0x5C];
    s32 start;              /* 0xC1C */
    Flags64 fC20;
    s32 fC28;
    s32 fC2C;
    s32 fC30;
};

extern "C" void func_003FB430(void *);
extern "C" void func_004009F0(void *, Car *);
extern "C" void func_00400758(void *, s32 *);
extern "C" void func_003FBAB0(void *, Car *, s32 *, s32);
extern "C" void CameraSys__CameraControl__init(void *, s32, s32);
extern "C" void func_00385290(void *);
extern "C" void func_003FF750(void *, s32 *, s32);
extern "C" f32 func_00578598(s32 *);

static inline void vreset(VObj *o) { VEntry *e = o->vt + 11; e->fn((char *)o + e->delta); }

static inline void clear_flags(Flags *f)
{
    f->b[0] = 0;
    f->b[1] = 0;
    f->w &= 0xFF00FFFF;
    f->b[3] = 0;
}

static inline void init_window(Window *w, Car *car, s32 *rnd, s32 index, s32 mode)
{
    func_003FBAB0(w->target, car, rnd, 0);
    CameraSys__CameraControl__init(w->control, 0, 1);
    w->f128 = 9;
    w->f12C = 0;
    w->f130 = -1;
    w->f134 = 9;
    w->mode = mode;
    func_00385290(w->f13C);
    w->index = index;
    w->f190 = -1;
    w->mount = -1;
    w->f198 = 0;
    vreset(w->objs[0]);
    vreset(w->objs[1]);
    vreset(w->objs[2]);
    vreset(w->objs[3]);
    vreset(w->objs[4]);
    vreset(w->objs[5]);
    vreset(w->objs[6]);
    vreset(w->objs[7]);
    vreset(w->objs[8]);
    vreset(w->objs[9]);
    vreset(w->objs[10]);
    vreset(w->objs[11]);
    vreset(w->objs[12]);
    vreset(w->objs[13]);
    func_003FF750(w->f180, rnd, 0);
    w->f184 = 0;
    clear_flags(&w->flags);
}

static inline void pick_start(CameraManager *self, s32 n)
{
    if (n > 0) {
        self->start = (s32)(func_00578598(&self->random) * 256.0f) % n;
        self->fC20.w &= ~0xFFull;
    }
}

extern "C" void DevelopCamera__virtual_20(CameraManager *self, Car *car)
{
    s32 i;
    s32 mode;
    History *h;

    func_003FB430(self->f9C0);
    self->m0[0][0] = 1.0f; self->m0[1][0] = 0.0f; self->m0[2][0] = 0.0f; self->m0[3][0] = 0.0f;
    self->m0[0][1] = 0.0f; self->m0[1][1] = 1.0f; self->m0[2][1] = 0.0f; self->m0[3][1] = 0.0f;
    self->m0[0][2] = 0.0f; self->m0[1][2] = 0.0f; self->m0[2][2] = 1.0f; self->m0[3][2] = 0.0f;
    self->m0[0][3] = 0.0f; self->m0[1][3] = 0.0f; self->m0[2][3] = 0.0f; self->m0[3][3] = 1.0f;
    self->m1[0][0] = 1.0f; self->m1[1][0] = 0.0f; self->m1[2][0] = 0.0f; self->m1[3][0] = 0.0f;
    self->m1[0][1] = 0.0f; self->m1[1][1] = 1.0f; self->m1[2][1] = 0.0f; self->m1[3][1] = 0.0f;
    self->m1[0][2] = 0.0f; self->m1[1][2] = 0.0f; self->m1[2][2] = 1.0f; self->m1[3][2] = 0.0f;
    self->m1[0][3] = 0.0f; self->m1[1][3] = 0.0f; self->m1[2][3] = 0.0f; self->m1[3][3] = 1.0f;
    self->windowMax = 1;
    self->current = 0;
    self->fAC0 = 0;
    self->fAC4 = 0;
    *(u64 *)&self->fAC8 &= ~0xFFull;
    *(u64 *)&self->fAC8 &= ~0xFF00ull;
    h = &self->hist;
    h->count = 0;
    h->last = -1;
    for (i = 0; i < 6; i++) {
        h->a[i] = 5;
        h->b[i] = 0;
    }
    func_004009F0(self->fB80, car);
    func_00400758(self->fBC0, &self->random);
    mode = self->displayEnable == 0;
    if (self->replayMode == 1) mode = 2;
    self->fC28 = 0;
    self->fC2C = 0;
    self->fC30 = 1;
    if (car != 0) self->fC30 = car->p84->fD2C;
    if (self->fC20.b[4]) mode = self->fC20.b[5] ? 2 : 1;
    for (i = 0; i < 6; i++)
        init_window(&self->win[i], car, &self->random, i, mode);
    self->start = 0;
    self->fC20.w &= ~0xFF00ull;
    self->fC20.w = (self->fC20.w & ~0xFFull) | 1;
    if (car != 0) {
        s32 n = car->p80->p4->pB0->count;
        pick_start(self, n);
    }
}
