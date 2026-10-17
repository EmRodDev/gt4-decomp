typedef unsigned int u32;
struct Ring {
    u32 wr;
    u32 rd;
    u32 count;
    char *buf;
    u32 elem;
    u32 size;
};
extern void *func_005A4724(void *, const void *, unsigned);

u32 func_0057B440(struct Ring *r, char *dst, u32 n) {
    u32 cnt = r->count;
    u32 take = n < cnt ? n : cnt;
    if (take != 0) {
        u32 rd = r->rd;
        u32 elem = r->elem;
        u32 size = r->size;
        u32 end = rd + take;
        char *src = r->buf + rd * elem;
        u32 chunk = take;
        char *d;
        if (size < end) {
            end -= size;
            chunk = size - rd;
            d = dst;
            dst += elem * chunk;
            func_005A4724(d, src, elem * chunk);
            src = r->buf;
            elem = r->elem;
            chunk = end;
        }
        func_005A4724(dst, src, elem * chunk);
        r->rd = end;
        r->count = r->count - take;
    }
    return take;
}
