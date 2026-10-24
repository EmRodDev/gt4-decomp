struct Id { int lo, hi; };
struct Ctx { char pad[8]; int handle; int state; };
int func_005224D0(struct Id);
int func_005220F8(struct Ctx *);
int func_00522CC8(int, struct Id, int, int, int *);
void func_005221B0(int, int, int);

int func_00521128(struct Ctx *ctx, struct Id id, int a2, int a3, int *out) {
    if (func_005224D0(id) != 0)
        return 2;
    *out = 0;
    if (a3 == 0)
        return 2;
    if (func_005220F8(ctx) == 0)
        return 2;
    if (ctx->state != 1)
        return 0xC355;
    {
        int r = func_00522CC8(ctx->handle, id, a2, a3, out);
        if (r != 0)
            return r;
    }
    func_005221B0(*out, 0, 0x1C);
    return 0;
}
