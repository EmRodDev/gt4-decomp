/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct VEntry { s16 delta; s16 index; void *fn; };
struct Obj { VEntry *vt; };
struct RacePS2BaseLayout {
    char pad[0x64];
    VEntry *vt;
    char gap[0xCC8 - 0x68];
    u32 unkCC8;
};

typedef Obj *(*Get)(void *, s32);
typedef s32 (*Flags)(void *);

extern "C" s32 RacePS2Base__isUseDefocusEffect(RacePS2BaseLayout *self) {
    s32 result = 0;
    if (self->unkCC8) {
        VEntry *e = &self->vt[26];
        Obj *o = ((Get)e->fn)((char *)self + e->delta, 0);
        VEntry *f = &o->vt[34];
        if (((Flags)f->fn)((char *)o + f->delta) & 0x4000) result = 1;
    }
    return result;
}
