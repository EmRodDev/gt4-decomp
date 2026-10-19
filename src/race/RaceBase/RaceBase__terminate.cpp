/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct func_003C0F40_arg0;

struct RaceBaseLayout {
    char pad0[0x64];
    VEntry *vt64;
    char pad68[4];
    void *p6C;
    char pad70[0xCE0 - 0x70];
    s32 unkCE0;
};

extern "C" void func_003C0F40(struct func_003C0F40_arg0 *arg0, f32 fparg0, f32 fparg1);

extern "C" void RaceBase__terminate(RaceBaseLayout *self, s32 arg1, f32 fparg0, f32 fparg1) {
    self->unkCE0 = arg1;
    if (fparg0 == 0.0f && fparg1 == 0.0f) {
        VEntry *e = &self->vt64[80];
        e->fn((char *)self + e->delta);
        return;
    }
    func_003C0F40((struct func_003C0F40_arg0 *)self->p6C, fparg0, fparg1);
}
