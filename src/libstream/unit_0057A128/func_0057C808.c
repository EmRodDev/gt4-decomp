/* compiler: ee-gcc2.96-exceptions-as2004 */
typedef unsigned int u32;
typedef unsigned long long u64;
struct HashCtx {
    u64 bits;
    u32 state[4];
    unsigned char buffer[64];
};
struct Digest { u32 w[4]; } __attribute__((packed));
extern unsigned char D_006CC8E0[];
extern void func_0057C718(struct HashCtx *, const unsigned char *, u32);

void func_0057C808(struct HashCtx *ctx, struct Digest *digest) {
    u64 bits = ctx->bits;
    u32 index = (int)((bits >> 3) & 0x3F);
    u32 padLen = index < 56 ? 56 - index : 120 - index;
    func_0057C718(ctx, D_006CC8E0, padLen);
    func_0057C718(ctx, (unsigned char *)&bits, 8);
    digest->w[0] = ctx->state[0];
    digest->w[1] = ctx->state[1];
    digest->w[2] = ctx->state[2];
    digest->w[3] = ctx->state[3];
}
