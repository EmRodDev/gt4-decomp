/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Ctx {
    char pad0[0xFE0];
    union {
        u128 q;
        f32 f[4];
    } color;
};

extern "C" void func_0049A200(Ctx *, s32, s32, s32, s32, s32);
extern "C" void func_0049A360(Ctx *, s32, s32, s32, s32, s32);
extern "C" void func_0049A4F8(Ctx *, s32, s32, s32, s32);
extern "C" void func_0049A6A0(Ctx *, s32, s32, s32, s32, s32);

extern "C" void func_0049A150(Ctx *ctx, s32 a, s32 b, s32 c, s32 d, s32 e, f32 alpha) {
    if (e) {
        ctx->color.f[0] = 255.0f;
        ctx->color.f[1] = 255.0f;
        ctx->color.f[2] = 255.0f;
        ctx->color.f[3] = alpha * 128.0f;
        __asm__ volatile("vnop");
        __asm__ volatile("lqc2 $vf15, %0" : : "m"(ctx->color.q));
        if (d)
            return func_0049A6A0(ctx, a, b, c, d, e);
        return func_0049A4F8(ctx, a, b, c, e);
    }
    if (d)
        return func_0049A360(ctx, a, b, c, d, e);
    return func_0049A200(ctx, a, b, c, d, e);
}
