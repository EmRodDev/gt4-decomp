/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef float f32;

static inline f32 min_s(f32 a, f32 b) {
    f32 r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

static inline f32 max_s(f32 a, f32 b) {
    f32 r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

struct VEntry { s16 delta; s16 index; void (*fn)(void *self, f32, f32, f32, f32); };

struct Info { char pad[0xB8]; s32 val; };

struct Msg {
    u32 w0;
    char pad4[0x14];
    f32 f18;
    f32 f1C;
};

struct Self {
    char *vtbl;
    Info *info;
    char pad8[0xBC - 8];
    char bc[1];
    char padBD[0x11B0 - 0xBD];
    Msg m11B0;
    char pad11D0[0x17BC - 0x11B0 - sizeof(Msg)];
    char m17BC[1];
    char pad17BD[0x252C - 0x17BD];
    Msg m252C;
};

extern char D_006A0508[];

extern "C" void RaceMessageDisplay__show(void *, f32, f32);
extern "C" int RaceEventDisplay__addEvent(void *, const char *, f32, f32, f32, f32);
extern "C" void AutomaticFader__oneshot(void *, f32, f32, f32, f32);
extern "C" void AutomaticFader__reset(void *);

static inline float to_float(int x) { return (float)x; }
static inline void call_virtual(Self *self, float a, float b, float c, float d) {
    VEntry *e = (VEntry *)(self->vtbl + 0x158);
    e->fn((char *)self + e->delta,a,b,c,d);
}

extern "C" void RaceDisplay__init_starting_style_long_format(Self *self) {
    Msg *message = &self->m11B0;
    Msg *start = &self->m252C;
    float value = to_float(self->info->val);
    start->f18 = 0x1.999998p-4f;
    start->f1C = 0x1.333332p-2f;
    float zero = 0.0f;
    float duration = min_s(max_s(value, zero), 2.0f);
    RaceMessageDisplay__show(start, max_s(duration, 3.0f), 0.25f);
    float end = min_s(max_s(value - 0.5f, 2.0f), 3.5f);
    call_virtual(self, 0x1.999998p-3f, end, 0x1.999998p-4f, 0x1.333332p-2f);
    message->f18 = 0x1.999998p-4f;
    message->f1C = 0x1.333332p-2f;
    RaceMessageDisplay__show(message, duration, 0x1.999998p-3f);
    int enabled = 1;
    if (!(zero < duration)) enabled = 0;
    message->w0 = (message->w0 & ~0xFF) | enabled;
    RaceEventDisplay__addEvent(self->m17BC, D_006A0508, duration + 1.0f, zero, zero, zero);
    AutomaticFader__reset(self->bc);
    AutomaticFader__oneshot(self->bc, duration, -1.0f, 0.5f, zero);
}
