typedef unsigned int u32;

struct Header {
    int state;          /* 0x00 */
    int zero;           /* 0x04 */
    u32 len;            /* 0x08 */
    u32 size;           /* 0x0C */
    char pad10[0x1C];
    char *self;         /* 0x2C */
    char pad30[0xC];
    int flag;           /* 0x3C */
};

struct Context {
    char pad0[0x18];
    int end;            /* 0x18 */
    char *buffer;       /* 0x1C */
    char pad20[0xC];
    char *dest;         /* 0x2C */
    char pad30[0xC];
    int cursor;         /* 0x3C */
};

extern "C" int func_00570EC0(void *dst, void *src, int n) throw();
extern "C" int func_00571890(void *p, u32 n, int *avail) throw();

extern "C" int func_005718F8(Context *ctx, int size, u32 *out, char *ok) {
    int avail = 0;
    u32 need;
    u32 rem;
    u32 left;
    int r;
    Header *h;

    if (ctx == 0) return 2;
    if (out == 0) return 2;
    if (ok == 0) return 2;
    need = size + 0x40;
    rem = need & 0x3F;
    if (rem) need = need - rem + 0x40;
    *out = need;
    if (ctx->cursor >= ctx->end) return 1;
    h = (Header *)(ctx->buffer + ctx->cursor);
    if (!h->state && !h->flag) {
        left = ctx->end - ctx->cursor;
        r = func_00571890(h, left, &avail);
        if (r) return r;
        if (avail < need && left - avail < 0x40 && (char *)h != ctx->buffer) {
            h->state = 1;
            h->zero = 1;
            h->len = left - 0x40;
            h->size = left - 0x40;
            h->self = (char *)h;
            h->flag = 1;
            r = func_00570EC0(h, ctx->dest + ctx->cursor, 0x40);
            if (r) return r;
            ctx->cursor = 0;
            return func_005718F8(ctx, size, out, ok);
        }
        if (avail >= need) {
            if (need < avail) {
                Header *n = (Header *)(ctx->buffer + ctx->cursor + need);
                *(int *)n = 0;
                *((int *)n + 1) = 0;
                u32 rest = avail - need - 0x40;
                n->flag = 0;
                n->len = rest;
                n->size = rest;
                r = func_00570EC0(ctx->buffer + ctx->cursor + need, ctx->dest + ctx->cursor + need, 0x40);
                if (r) return r;
            }
            h = (Header *)(ctx->buffer + ctx->cursor);
            h->flag = 0;
            h->state = 0;
            h->zero = 0;
            h->len = need - 0x40;
            h->size = need - 0x40;
            r = func_00570EC0(ctx->buffer + ctx->cursor, ctx->dest + ctx->cursor, 0x40);
            if (r) return r;
            *ok = 1;
        } else {
            *ok = 0;
        }
    } else {
        *ok = 0;
    }
    return 0;
}
