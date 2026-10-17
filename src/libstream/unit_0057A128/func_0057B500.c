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

u32 func_0057B500(struct Ring *r, char *src, u32 n) {
    u32 size = r->size;
    u32 room = size - r->count;
    u32 take = n < room ? n : room;
    if (take != 0) {
        u32 wr = r->wr;
        u32 elem = r->elem;
        u32 end = wr + take;
        char *dst = r->buf + wr * elem;
        u32 chunk = take;
        if (size < end) {
            chunk = size - wr;
            end -= size;
            func_005A4724(dst, src, elem * chunk);
            src += elem * chunk;
            dst = r->buf;
            elem = r->elem;
            chunk = end;
        }
        func_005A4724(dst, src, elem * chunk);
        r->wr = end;
        r->count = r->count + take;
    }
    return take;
}
