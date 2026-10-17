/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef float f32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct S00659988 { const char *name; };

struct PadEntry { short delta; short index; f32 (*fn)(void *, s32, s32); };
struct Pad { char pad0[4]; char *vtbl; };
struct Arg { char pad0[0x10]; Pad *f10; };

struct ViewEntry1 { short delta; short index; void (*fn)(void *, f32); };
struct ViewEntry2 { short delta; short index; void (*fn)(void *, f32, f32); };
struct View { char pad0[4]; char *vtbl; };

struct Rec { char pad[0x1D0]; s32 f1D0; };


struct Obj {
    char pad0[0xC];
    void *wid[0x28];
    char padAC[0x290 - 0xAC];
    s64 f290[2];
    char pad2A0[8];
    s32 f2A8;
    char pad2AC[8];
    void *f2B4;
    char pad2B8[0x2C4 - 0x2B8];
    s32 f2C4;
    s32 f2C8;
    f32 f2CC;
    f32 f2D0;
    char pad2D4[0x2E4 - 0x2D4];
    f32 f2E4;
    f32 f2E8;
    f32 f2EC;
    f32 f2F0;
    f32 f2F4;
    f32 f2F8;
    f32 f2FC;
    f32 f300;
};

extern StringRep D_00659FA8;
extern s32 PDISTD__UNIT_MANAGER[];

extern "C" f32 func_0011DBE8(void *, int, f32);
extern "C" f32 func_00120518(Obj *);
extern "C" f32 func_00120528(Obj *);
extern "C" f32 func_001233E0(Obj *);
extern "C" Rec *func_00123500(s32);
struct String;
extern "C" void func_00245270(void *, const String &);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void GranTurismo4__GetTimeString(u32, char *, u32);
extern "C" char *func_00472680(s32 *);
extern "C" f32 func_00472940(s32 *, f32);
extern "C" f32 func_0057D5A8(f32);
extern "C" f32 func_0057D6C0(f32, f32);
extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" u32 func_0057F260(const char *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(StringRep *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

struct String {
    char *dat;
    char pad[0xC];
    String(const char *s) {
        dat = grab(&D_00659FA8);
        func_005C2630(this, 0, (u32)-1, s, func_0057F260(s));
    }
    ~String() {
        StringRep *q = (StringRep *)(dat - 0x10);
        if (--q->ref == 0) {
            s32 size = q->res + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
};

static inline f32 absf(f32 v) {
    f32 r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

static inline f32 max_s(f32 a, f32 b) {
    f32 r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

static inline f32 min_s(f32 a, f32 b) {
    f32 r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

#define AXIS(p, n) ({ PadEntry *e = (PadEntry *)((p)->vtbl + 0x1E0); e->fn((char *)(p) + e->delta, 0, (n)); })

extern "C" void func_001206A0(Obj *self, Arg *arg1) {
    Pad *pad = arg1->f10;
    f32 zoomX = AXIS(pad, 2);
    f32 zoomY = AXIS(pad, 3);
    f32 moveX = AXIS(pad, 0);
    f32 moveY = AXIS(pad, 1);
    f32 px = func_0057D6C0(absf(moveX), 1.5f);
    f32 py = func_0057D6C0(absf(moveY), 1.5f);
    f32 dx = moveX >= 0.0f ? px : -px;
    f32 dy = moveY >= 0.0f ? py : -py;
    f32 sx = self->f2E4;
    sx += zoomX * 0.03125f * (func_0057D5A8(sx) / 0x1.26BB44p+1f + 0x1.333332p+0f);
    if (sx < 0x1.999998p-2f) {
        sx = 0x1.999998p-2f;
    } else if (sx > 10.0f) {
        sx = 10.0f;
    }
    self->f2E4 = sx;
    f32 sy = self->f2E8;
    sy += zoomY * 0.03125f * (func_0057D5A8(sy) / 0x1.26BB44p+1f + 0x1.333332p+0f);
    if (sy < 0.5f) {
        sy = 0.5f;
    } else if (sy > 4.0f) {
        sy = 4.0f;
    }
    self->f2E8 = sy;
    f32 x = self->f2CC + (dx + dx) / sx;
    if (x < 0.0f) {
        switch (self->f2C4) {
        case 0:
        case 1:
            x = 0.0f;
            self->f2C4 = 1;
            break;
        case 2:
            self->f2C4 = 0;
            x = self->f300;
            break;
        }
    } else if (self->f300 < x) {
        switch (self->f2C8) {
        case 0:
        case 1:
            x = self->f300;
            self->f2C8 = 1;
            break;
        case 2:
            self->f2C4 = 0;
            x = 0.0f;
            break;
        }
    } else if (dx != 0.0f) {
        self->f2C4 = 0;
        self->f2C8 = 0;
    } else {
        if (self->f2C4 == 1) {
            self->f2C4 = 2;
        }
        if (self->f2C8 == 1) {
            self->f2C8 = 2;
        }
    }
    self->f2CC = x;
    f32 y = self->f2D0;
    f32 ymax = max_s(func_001233E0(self) - self->f2F0, 0.0f);
    y = min_s(max_s(y - (dy + dy), 0.0f), ymax);
    void *curve = self->f2B4;
    self->f2D0 = y;
    for (s32 i = 0; i < 2; i++) {
        if (func_00123500(i)->f1D0 != 0) {
            continue;
        }
        if (self->wid[i + 0x20] != 0) {
            char buf[0x20];
            s64 t = 0;
            if (self->f2A8 != 0) {
                t = self->f290[i];
            }
            GranTurismo4__GetTimeString(t, buf, 0x20);
            func_00245270(self->wid[i + 0x20], String(buf));
        }
        if (self->wid[i + 0x24] != 0) {
            char buf[0x20];
            char *unit = func_00472680(PDISTD__UNIT_MANAGER);
            s32 v;
            if (self->f2A8 != 0) {
                v = (s32)func_00472940(PDISTD__UNIT_MANAGER, func_0011DBE8(curve, i, self->f2CC));
            } else {
                v = 0;
            }
            func_0057DA20(buf, "%3d%s", v, unit);
            func_00245270(self->wid[i + 0x24], String(buf));
        }
    }
    if (self->wid[0x1D] != 0) {
        {
            View *o = (View *)self->wid[0x1D];
            ViewEntry1 *e = (ViewEntry1 *)(o->vtbl + 0x308);
            e->fn((char *)o + e->delta, self->f2CC + self->f2F8);
        }
        f32 a = func_00120518(self) + self->f2F8;
        f32 b = func_00120528(self) + self->f2F8;
        {
            View *o = (View *)self->wid[0x1D];
            ViewEntry2 *e = (ViewEntry2 *)(o->vtbl + 0x310);
            e->fn((char *)o + e->delta, a, b);
        }
    }
}
