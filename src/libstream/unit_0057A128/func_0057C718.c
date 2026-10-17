typedef unsigned int u32;
typedef unsigned long long u64;
struct HashCtx {
    u64 bits;
    char state[16];
    unsigned char buffer[64];
};
extern void func_0057B888(struct HashCtx *, const unsigned char *);
extern void *func_005A4724(void *, const void *, unsigned);

void func_0057C718(struct HashCtx *ctx, const unsigned char *data, u32 len) {
    int index;
    u32 partLen;
    if (len == 0) return;
    index = (int)((ctx->bits >> 3) & 0x3F);
    ctx->bits += (u32)(len << 3);
    partLen = 64 - index;
    if (index != 0) {
        if (len >= partLen) {
            func_005A4724(&ctx->buffer[index], data, partLen);
            index = 0;
            func_0057B888(ctx, ctx->buffer);
            len -= partLen;
            data += partLen;
        }
    }
    while (len >= 64) {
        func_0057B888(ctx, data);
        data += 64;
        len -= 64;
    }
    if (len != 0) func_005A4724(&ctx->buffer[index], data, len);
}
