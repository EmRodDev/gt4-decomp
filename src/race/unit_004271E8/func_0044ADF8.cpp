/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned char u8;
struct Ctx { char pad[0x14]; u8 buf[8]; u32 n; };
extern "C" void func_0044ACD8(Ctx *, u8 *) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned) throw();

static inline void process_blocks(Ctx *c, u8 *data, u32 blocks) {
    if (blocks != 0) {
        u32 i = 0;
        do {
            func_0044ACD8(c, data);
            ++i;
        } while (i < blocks);
    }
}

extern "C" void func_0044ADF8(Ctx *c, u8 *data, u32 len) {
    if (c->n != 0) {
        u32 room = 8 - c->n;
        if (len < room) {
            func_005A4724(c->buf + c->n - 0, data, len);
            c->n += len;
            return;
        }
        func_005A4724(c->buf + c->n, data, room);
        data += room;
        len -= room;
        func_0044ACD8(c, c->buf);
        c->n = 0;
    }
    u32 blocks = len >> 3;
    process_blocks(c, data, blocks);
    data += blocks * 8;
    len -= blocks * 8;
    if (len != 0) {
        func_005A4724(c->buf, data, len);
        c->n = len;
    }
}
