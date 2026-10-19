/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry { s16 delta; s16 index; void *fn; };
struct RacePS2BaseLayout {
    char pad[0x70];
    s32 m70;
    char pad74[0x3628 - 0x74];
    char pitmen[0x3C];
};

struct O2 {
    char pad0[8];
    VEntry *vt;
};

extern "C" s32 Pitmen__doRenderExchangeTire(void *, s32, s32, s32, s32);
extern "C" void Pitmen__applyExchangeTireMatrix(void *, s32, s32, s32, s32);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);

extern "C" void RacePS2Base__render_exchange_tire(RacePS2BaseLayout *self, s32 a1, O2 *o2) {
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 2; j++) {
            if (Pitmen__doRenderExchangeTire(self->pitmen, a1, self->m70, i, j)) {
                func_004A53F8();
                Pitmen__applyExchangeTireMatrix(self->pitmen, a1, self->m70, i, j);
                VEntry *e = &o2->vt[27];
                ((void (*)(void *, s32))e->fn)((char *)o2 + e->delta, i);
                func_004A5400();
            }
        }
    }
}
