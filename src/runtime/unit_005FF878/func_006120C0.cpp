/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int words[0x3B8 / 4]; };
struct Ctx { int handle; char pad[0x3C]; Block block; int state; };
extern "C" char D_00873DC0[];
extern "C" void func_00578500(int);
extern "C" int func_005B72A8();
extern "C" int func_00578168(Ctx *, int, int, void *, int);
extern "C" void func_006120C0(Ctx *ctx, Block *src) {
    func_00578500(ctx->handle);
    int enabled = func_005B72A8();
    ctx->block = *src;
    if (enabled) __asm__ volatile("ei");
    ctx->state = 1;
    func_00578168(ctx, 4, 1, D_00873DC0, 0x80);
}
