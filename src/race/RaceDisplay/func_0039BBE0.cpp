/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;
typedef unsigned int u32;

struct VEnt { s16 delta; s16 idx; void *fn; };
struct Sub { char pad[0x18]; u32 w18; };
struct Self {
    VEnt *vtbl;
    char pad4[0x20 - 4];
    s32 unk20;
    char pad24[0x2F - 0x24];
    signed char id2F;
    char pad30[0xC];
    u32 w3C;
    char pad40[4];
    u32 w44;
    char pad48[0xD58 - 0x48];
    Sub subD58;
};

extern "C" void func_0039BCA8(Self *);
extern "C" void func_0039D218(Self *, s32);
extern "C" s32 func_003A1638(Self *, s32);
extern "C" void func_003A2270(Self *, f32);

extern "C" void func_0039BBE0(Self *self) {
    VEnt *e = &self->vtbl[11];
    self->w3C = self->w3C & 0xFFFFFF;
    ((void (*)(void *, s32))e->fn)((char *)self + e->delta, self->id2F);
    func_0039D218(self, self->id2F);
    func_003A1638(self, 0);
    func_0039BCA8(self);
    s32 flag = self->unk20 == 1;
    func_003A2270(self, flag ? 42.0f : 0.0f);
    Sub *s = &self->subD58;
    s->w18 = (s->w18 & -0x100) | flag;
    self->w44 = (self->w44 & -0x100) | 1;
}
