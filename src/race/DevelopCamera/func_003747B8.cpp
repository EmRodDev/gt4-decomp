/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned long long u64;

struct Camera { char *vt; char pad[0xE4]; s32 fE8; char pad2[0x168 - 0xEC]; u64 f168; };

union Flags { unsigned char b[4]; s32 w; };

struct Window {
    char target[0xD0];      /* 0x000 */
    char control[0x58];     /* 0x0D0 */
    s32 f128;
    Camera *current;        /* 0x12C */
    s32 f130;
    s32 f134;
    s32 mode;               /* 0x138 */
    char f13C[0xC];
    Camera *cams[14];       /* 0x148 */
    void *f180;
    s32 mount;              /* 0x184 */
    Flags flags;            /* 0x188 */
    s32 index;              /* 0x18C */
    s32 f190;
    s32 f194;
    s32 f198;
};

struct Pos { s32 a; s32 b; s32 c; };

struct Car { char pad[0x80]; void *f80; char pad2[0xBC - 0x84]; s32 fBC; };

struct Sub { char pad[0x28]; s32 arr[6]; };

struct Body {
    s32 random;             /* 0x004 */
    s32 displayEnable;      /* 0x008 */
    s32 replayMode;         /* 0x00C */
    Window win[6];          /* 0x010 */
};

struct CameraManager {
    void *vptr;
    Body body;              /* 0x004 */
    char pad[0xB80 - 0x9B8];
    Sub fB80;               /* 0xB80 */
    char fBC0[0x40];
};

extern "C" void func_004009F0(void *, Car *);
extern "C" void func_00400758(void *, s32 *);
extern "C" void func_003FD980(Car *, Window *, Pos *);
extern "C" int func_003FDAB8(Car *, s32, Pos *, s32);
extern "C" f32 func_00578598(s32 *);
extern "C" void func_00375C08(CameraManager *, Car *, s32);
extern "C" void func_00376638(CameraManager *, s32, Car *, Window *, s32);


/* vtable entries: { this delta, index, function } */
struct EntryA { short delta; short index; void (*fn)(void *, Window *, void *, s32, s32); };
struct EntryB { short delta; short index; void (*fn)(void *, Window *, void *, s32, s32, s32, f32); };
struct EntryC { short delta; short index; void (*fn)(void *, Window *); };
struct EntryD { short delta; short index; void (*fn)(void *, Window *, s32); };
struct EntryE { short delta; short index; void (*fn)(void *, Window *, s32, Flags *); };

static inline Window *window(CameraManager *self, s32 idx) { return &self->body.win[idx]; }

static inline void use_default(CameraManager *self, Window *w, s32 idx)
{
    Camera *cam = w->cams[0];
    EntryD *e = (EntryD *)(cam->vt + 0x140);
    e->fn((char *)cam + e->delta, w, self->body.win[idx].mount);
    window(self, idx)->current = cam;
}

extern "C" void func_003747B8(CameraManager *self, Car *car, s32 arg2, s32 mode, s32 idx)
{
    Window *w = &self->body.win[idx];
    void *info = car->f80;
    Pos pos;

    func_004009F0(&self->fB80, car);
    func_00400758(self->fBC0, &self->body.random);
    switch (mode) {
    case 0:
        use_default(self, w, idx);
        break;
    case 3: {
        Camera *cam = w->cams[3];
        EntryA *e = (EntryA *)(cam->vt + 0x138);
        e->fn((char *)cam + e->delta, w, info, car->fBC, 0);
        window(self, idx)->current = cam;
        break;
    }
    case 1: {
        Camera *cam = w->cams[1];
        s32 n;
        func_003FD980(car, w, &pos);
        n = pos.c;
        if (n != 0) {
            f32 f = func_00578598(&self->body.random);
            EntryB *e = (EntryB *)(cam->vt + 0x138);
            e->fn((char *)cam + e->delta, w, info, pos.b, n, 0, f);
            window(self, idx)->current = cam;
        } else {
            Camera *def = w->cams[0];
            EntryD *e = (EntryD *)(def->vt + 0x140);
            e->fn((char *)def + e->delta, w, self->body.win[idx].mount);
            def->fE8 = 3;
            window(self, idx)->current = def;
        }
        break;
    }
    case 2: {
        Camera *cam = w->cams[9];
        EntryE *e = (EntryE *)(cam->vt + 0x178);
        e->fn((char *)cam + e->delta, w, 1, &self->body.win[idx].flags);
        window(self, idx)->current = cam;
        break;
    }
    case 4: {
        Camera *cam = w->cams[3];
        EntryA *e = (EntryA *)(cam->vt + 0x138);
        e->fn((char *)cam + e->delta, w, info, car->fBC, 1);
        window(self, idx)->current = cam;
        break;
    }
    case 5: {
        Camera *cam = w->cams[1];
        func_003FDAB8(car, 0, &pos, 0);
        if (pos.c != 0) {
            EntryB *e = (EntryB *)(cam->vt + 0x138);
            e->fn((char *)cam + e->delta, w, info, pos.b, pos.c, 1, 1.0f);
            cam->f168 = (cam->f168 & 0xFFFF00FFFFFFFFFFull) | 0x10000000000ull;
            window(self, idx)->current = cam;
            w->f130 = 0;
        } else {
            use_default(self, w, idx);
            w->f130 = -2;
        }
        break;
    }
    case 6: {
        Camera *cam = w->cams[2];
        EntryC *e = (EntryC *)(cam->vt + 0x138);
        e->fn((char *)cam + e->delta, w);
        window(self, idx)->current = cam;
        break;
    }
    case 7:
        func_00375C08(self, car, idx);
        break;
    case 8:
        self->fB80.arr[idx] = -1;
        func_00376638(self, idx, car, w, arg2);
        break;
    }
}
