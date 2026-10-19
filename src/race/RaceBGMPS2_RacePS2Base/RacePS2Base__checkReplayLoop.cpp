/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct VEntry { s16 delta; s16 index; void *fn; };
struct RacePS2BaseLayout {
    char pad[0x64];
    VEntry *vt;
    char gap[0xCC8 - 0x68];
    u32 unkCC8;
    s32 unkCCC;
    s32 unkCD0;
    s32 unkCD4;
};

extern "C" s32 RaceBase__getSignal(void *);
extern "C" void RaceBase__setVisual(void *, s32);

typedef void (*Fn0)(void *);
typedef void (*Fn1)(void *, s32);

extern "C" s32 RacePS2Base__checkReplayLoop(RacePS2BaseLayout *self) {
    s32 result = 0;
    if (RaceBase__getSignal(self) == 1) {
        VEntry *e = &self->vt[88];
        s32 saved = self->unkCD4;
        self->unkCD4 = 0;
        u32 cc8 = self->unkCC8;
        s32 cd0 = self->unkCD0;
        ((Fn0)e->fn)((char *)self + e->delta);
        VEntry *f = &self->vt[38];
        ((Fn1)f->fn)((char *)self + f->delta, cc8);
        RaceBase__setVisual(self, cd0);
        self->unkCD4 = saved;
        result = 1;
    }
    return result;
}
