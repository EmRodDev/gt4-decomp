/* compiler: ee-gcc2.96-stl */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef short s16;
typedef float f32;

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Vt {
    char pad[0x50];
};

struct Self {
    char pad0[1];
    u8 b1;
    u8 b2;
    char pad3;
    s16 x4;
    s16 x6;
    s16 w;
    s16 h;
    f32 fC;
    void *tex;
    Vt *vt;
    f32 f18;
    char pad1c[0x1C];
    f32 f38;
    char pad3c[0x18];
    char pad54;
    char c55;
    u8 b56;
    u8 b57;
};

extern char D_00623838[];
extern char D_006A1408[];
extern char D_006A1420[];

extern "C" s32 func_003AFD78(s32 x, s32 w, s32 fl);
extern "C" s32 func_003AFEC8(u32 c, f32 a);
extern "C" void func_0044D920(void *p, const char *name);
extern "C" void func_0044D988(void *p);
extern "C" void GT3OLDFONT__GT3OldFontManagerClass__position(void *p, s32 x, s32 y, s32 z);
extern "C" void func_0044DE80(void *p, s32 v);
extern "C" void func_0044E088(void *p, const char *fmt, ...);

extern "C" void RaceSuggestedGearDisplay__render_main(Self *a) {
    s32 s4, s2;
    s32 c;
    f32 f;

    if (a->tex == 0) {
        VEntry *e = (VEntry *)((char *)a->vt + 0x50);
        e->fn((char *)a + e->delta);
    }
    f = 1.0f;
    s4 = func_003AFD78(a->x4, a->w, a->b1);
    s2 = func_003AFD78(a->x6, a->h, a->b2) + a->h;
    if (a->b57 != 0) {
        f = a->f18;
    }
    f *= a->fC;
    f *= a->f38;
    func_0044D920(D_00623838, D_006A1420);
    *(s32 *)(D_00623838 + 4) = 0xF;
    GT3OLDFONT__GT3OldFontManagerClass__position(D_00623838, s4 + a->w / 2, s2 - 0x10, 0);
    func_0044DE80(D_00623838, func_003AFEC8(0x800000F0, f));
    if (a->b56 == 0) {
        c = 0x43;
        c = a->c55 + 0x30;
    } else {
        c = 0x43;
    }
    func_0044E088(D_00623838, D_006A1408, c);
    *(s32 *)(D_00623838 + 4) = 0;
    func_0044D988(D_00623838);
}
