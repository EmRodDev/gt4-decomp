/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Ctx {
    int handle;
    int sock;
    char pad8[8];
    char hdr[0x1024 - 0x10];
    int status;
    char pad1028[4];
    int total;
    char pad1030[0x2034 - 0x1030];
    int headerDone;
    char pad2038[0x2044 - 0x2038];
    int received;
    char pad2048[0x207C - 0x2048];
    char buf[0x2C7C - 0x207C];
    char head[0x200];
};
struct Conn { char pad[0x44]; Ctx *ctx; };
struct Net { char pad[0x30]; int (*recv)(int, char *, int, int *); };
extern Net *D_0064B4B0;
extern "C" void func_0053A890(void *, unsigned *) throw();
extern "C" void func_0053B858(char *, void *) throw();
extern "C" int func_00540F10(int, char *, int, int) throw();
extern "C" int func_00540F38(int, int *) throw();
extern "C" void *func_005A6AB0(void *, void *, int) throw();
extern "C" char *func_005A6DC8(const char *, const char *) throw();
extern "C" int func_0053BD78(Conn *self, int *done) {
    int len;
    unsigned parsed;
    int r = D_0064B4B0->recv(self->ctx->handle, self->ctx->buf, 0x800, &len);
    int finished = 1;
    if (r != 0) {
        /* Any receive error ends the transfer; 0xC356 (closed by the peer) is not an error.
           Both arms store the same inished value (one register in retail). */
        if (r == 0xC356) {
            *done = finished;
            return 0;
        }
        *done = finished;
        return r;
    } else if (len != 0) {
        self->ctx->buf[len] = 0;
        Ctx *c = self->ctx;
        char *p;
        if (c->headerDone == 0) {
            p = func_005A6DC8(c->buf, "\r\n\r\n");
            if (p == 0) {
                p = func_005A6DC8(self->ctx->buf, "\n\n");
                if (p == 0) return 0xD6DC;
            }
            *p = 0;
            p += 4;
            len -= (u16)(p - self->ctx->buf);
            func_005A6AB0(self->ctx->head, self->ctx->buf, 0x200);
            func_0053B858(self->ctx->head, &self->ctx->status);
            c = self->ctx;
            if (c->status != 0xC8) return 0xD6DC;
            c->headerDone = 1;
        } else {
            p = c->buf;
        }
        r = func_00540F10(c->sock, p, len, 0);
        if (r != 0) return r;
        c = self->ctx;
        int n = c->received + len;
        c->received = n;
        if (n == c->total && n > 0) {
            *done = 1;
            return r;
        }
        r = func_00540F38(c->sock, done);
        if (r != 0) return r;
    } else {
        func_0053A890(self->ctx->hdr, &parsed);
        if (parsed >= 0x7531) return 0xD6D9;
    }
    return 0;
}
