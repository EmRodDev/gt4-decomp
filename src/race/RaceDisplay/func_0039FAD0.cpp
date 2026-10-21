/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-frame pass of a RaceDisplay: the flag word at +0x58 decides which sub-steps run (bit 0x02: 0039FC88; 0x40: 0039FCB0; 0x20: 0039FD30; 0x10:
 * the virtual at vtable +0xC8; 0x80 or the byte at +0x3D: 003A0178), 0039FFF8 and 0039FF78 always run, and four embedded components are
 * driven through their own virtuals only when their first byte (an "enabled" flag, inferred) is set: +0x2D78 and +0x2DA0 get updateArg through
 * slot +0x30, +0x11B0 and +0x252C are called without arguments through slot +0x28. The two RaceMessageDisplay blocks at +0x267C and +0x27CC
 * are rendered and 0039D390 closes the pass. What each bit stands for is purpose unknown. */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned int u32;

struct VEnt1 { s16 delta; s16 idx; void (*fn)(void *); };
struct VEnt2 { s16 delta; s16 idx; void (*fn)(void *, s32); };
struct Comp {
    u8 flag;
    char pad1[0x13];
    char *vtbl;
};
struct Self {
    char *vtbl;
    char pad4[0x39];
    u8 b3D;
    char pad3e[0x58 - 0x3E];
    u32 w58;
    char pad5c[0x11B0 - 0x5C];
    Comp c11B0;
    char pad11b0[0x252C - 0x11B0 - sizeof(Comp)];
    Comp c252C;
    char pad2540[0x267C - 0x252C - sizeof(Comp)];
    char msg267C[0x27CC - 0x267C];
    char msg27CC[0x2D78 - 0x27CC];
    Comp c2D78;
    char pad2d8c[0x2DA0 - 0x2D78 - sizeof(Comp)];
    Comp c2DA0;
};

extern "C" void func_0039D390(Self *) throw();
extern "C" void func_0039FC88(Self *);
extern "C" void func_0039FCB0(Self *, s32);
extern "C" void func_0039FD30(Self *, s32);
extern "C" void func_0039FF78(Self *);
extern "C" void func_003A0178(Self *);
extern "C" void func_0039FFF8(Self *, s32);
extern "C" void RaceMessageDisplay__render_main(void *);

static inline void vc0(Comp *o, s32 off) {
    VEnt1 *e = (VEnt1 *)(o->vtbl + off);
    e->fn((char *)o + e->delta);
}
static inline void vc1(Comp *o, s32 off, s32 comp2D78) {
    VEnt2 *e = (VEnt2 *)(o->vtbl + off);
    e->fn((char *)o + e->delta, comp2D78);
}

extern "C" void func_0039FAD0(Self *self, s32 updateArg) {
    u32 flagsWord = self->w58;
    if (flagsWord & 2) func_0039FC88(self);
    if (flagsWord & 0x40) func_0039FCB0(self, updateArg);
    if (flagsWord & 0x20) func_0039FD30(self, updateArg);
    func_0039FFF8(self, updateArg);
    if (flagsWord & 0x10) {
        VEnt1 *e = (VEnt1 *)(self->vtbl + 0xC8);
        e->fn((char *)self + e->delta);
    }
    func_0039FF78(self);
    if ((flagsWord & 0x80) || self->b3D != 0) func_003A0178(self);
    Comp *comp2D78 = &self->c2D78;
    if (comp2D78->flag != 0) vc1(comp2D78, 0x30, updateArg);
    Comp *comp2DA0 = &self->c2DA0;
    if (comp2DA0->flag != 0) vc1(comp2DA0, 0x30, updateArg);
    Comp *comp11B0 = &self->c11B0;
    if (comp11B0->flag != 0) vc0(comp11B0, 0x28);
    Comp *comp252C = &self->c252C;
    if (comp252C->flag != 0) vc0(comp252C, 0x28);
    RaceMessageDisplay__render_main(self->msg267C);
    RaceMessageDisplay__render_main(self->msg27CC);
    func_0039D390(self);
}
