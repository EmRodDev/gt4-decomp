/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-object (re)initialisation step: if the global D_006201A8 is set, copies D_006201AC into the two fields at +0xC and +0x10; runs
 * 00333C40 when useVariantB is nonzero, otherwise 003336B8 and then stores 1/60 divided by the field at +0x118 into the owning block (+0xCF5C),
 * which reads as a per-sub-step time step with +0x118 the sub-steps per frame (inferred from the 1/60 literal; hence the field name).
 * It then writes 0x200 into +0xE330 of the block (purpose unknown), calls 00397438 on a value reached through the block when +0x124 is
 * 0, and finishes with 003323B0 on the embedded part at +0x44 and 00334B28. Everything is skipped when the object has no block. */
typedef int s32;
typedef float f32;

struct P6C { char pad[0x80]; struct P80 *u80; };
struct P80 { s32 u0; s32 u4; };
struct G {
    char pad0[0x6C];
    P6C *u6C;
    char pad70[0xCF5C - 0x70];
    f32 fCF5C;
    char padCF60[0xE330 - 0xCF60];
    s32 uE330;
};
struct Obj {
    G *g;
    char pad4[8];
    s32 uC, u10;
    char pad14[0x118 - 0x14];
    s32 subStepCount;
    char pad11C[0x124 - 0x11C];
    s32 u124;
};

extern s32 D_006201A8;
extern s32 D_006201AC;

extern "C" void func_003323B0(void *, s32);
extern "C" void func_003336B8(Obj *);
extern "C" void func_00333C40(Obj *);
extern "C" void func_00334B28(Obj *);
extern "C" void func_00397438(s32);

extern "C" void func_00333808(Obj *self, s32 useVariantB) {
    if (self->g != 0) {
        if (D_006201A8 != 0) {
            self->uC = D_006201AC;
            self->u10 = D_006201AC;
        }
        if (useVariantB != 0) {
            func_00333C40(self);
        } else {
            func_003336B8(self);
        }
        if (useVariantB == 0) {
            self->g->fCF5C = 0x1.111110p-6f / (f32)self->subStepCount;
        }
        self->g->uE330 = 0x200;
        if (self->u124 == 0) {
            P80 *p = self->g->u6C->u80;
            func_00397438(p->u4);
        }
        func_003323B0((char *)self + 0x44, self->subStepCount);
        func_00334B28(self);
    }
}
