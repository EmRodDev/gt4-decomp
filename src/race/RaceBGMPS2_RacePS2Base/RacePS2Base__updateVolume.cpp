/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct VEntry { s16 delta; s16 index; void *fn; };
struct Obj { VEntry *vt; };
struct RacePS2BaseLayout {
    char pad0[0x64];
    VEntry *vt;
    char pad1[0xCF84 - 0x68];
    f32 vol;
    char bgm_ps2[0x38];
};

extern f32 RaceCarSound__external_volume_;
extern "C" void RaceBGMPS2__setVolumeRate(void *, f32) throw();

static inline f32 getv(RacePS2BaseLayout *self) {
    VEntry *e = &self->vt[143];
    return ((f32 (*)(void *))e->fn)((char *)self + e->delta);
}

static inline Obj *getobj(RacePS2BaseLayout *self) {
    VEntry *e = &self->vt[26];
    return ((Obj *(*)(void *, s32))e->fn)((char *)self + e->delta, 0);
}

extern "C" void RacePS2Base__updateVolume(RacePS2BaseLayout *self) {
    f32 v = getv(self);
    self->vol = self->vol * 0.5f;
    Obj *o = getobj(self);
    VEntry *e2 = &o->vt[39];
    if (((s32 (*)(void *, s32))e2->fn)((char *)o + e2->delta, 0) != 0)
        self->vol = 1.0f;
    RaceCarSound__external_volume_ = v * (1.0f - self->vol);
    RaceBGMPS2__setVolumeRate(self->bgm_ps2, v);
}
