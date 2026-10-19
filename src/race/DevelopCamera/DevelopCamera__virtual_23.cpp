/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { long w[8]; } __attribute__((aligned(8)));
struct CamObj {
    char pad0[0x9C0];
    Blk blk;
};
extern "C" void DevelopCamera__virtual_23(CamObj *self, const Blk *src, float f) {
    Blk *dst = &self->blk;
    *dst = *src;
    ((float *)(dst + 1))[0] = f;
}
