/* compiler: ee-gcc2.96-as2004g */
struct Id { int lo, hi; };
struct Api { char pad[0x80]; int (*make)(struct Id *, const unsigned char *); };
struct Hooks { char pad[0x18]; int (*withExtra)(int, int, void *); char pad1c[0x34]; void (*plain)(int, int); };
struct Conn {
    int handle; char pad4[0x80]; int ctx; char pad88[8];
    void (*onDone)(int, int, struct Id, int);
};
extern struct Api *D_0064B4B0;
extern struct Hooks *D_0064B710;
void func_00538F98(const unsigned char *, unsigned short *);
void *func_005A4724(void *, const void *, int);
int func_0051DCF8(int);

int func_0051EC08(struct Conn *self, int type, const unsigned char *p, unsigned int len) {
    struct Id id;
    char extra[0x40];
    unsigned short port;
    int pt;
    unsigned int consumed;
    int big = 0;
    if (type == 8)
        big = 1;
    else if (type != 9)
        return 2;
    consumed = 1;
    if (consumed >= len)
        return 0xCB20;
    func_00538F98(p, &port);
    p += 2;
    pt = port;
    if (big) {
        if ((int)(len - 2) != 0x50)
            return 0xCB20;
    } else {
        if ((int)(len - 2) != 0x10)
            return 0xCB20;
    }
    D_0064B4B0->make(&id, p);
    p += 0x10;
    if (big) {
        func_005A4724(extra, p, 0x40);
        if (D_0064B710)
            D_0064B710->withExtra(self->handle & 0x7FFFFFFF, pt, extra);
    } else {
        if (D_0064B710)
            D_0064B710->plain(self->handle & 0x7FFFFFFF, pt);
    }
    if (self->onDone) {
        int h = self->handle;
        self->onDone(self->ctx, pt, id, big);
        if (func_0051DCF8(h) == 0)
            return 0xCB23;
    }
    return 0;
}
