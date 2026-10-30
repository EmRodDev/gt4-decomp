/* compiler: ee-gcc2.96-as2004g */
struct Token { double value; } __attribute__((packed));
struct Args { char name[12][256]; char value[12][256]; unsigned int count; };
struct Self;
struct Conn {
    void *session;
    int handle;
    int user;
    char padC[0x1024 - 0xC];
    int code;
    char pad1028[0x206C - 0x1028];
    void (*cb)(Self *, int, int);
};
struct Self {
    int first;
    Token id;
    char padC[8];
    int port;
    char pad18[0x3C - 0x18];
    int busy;
    int pad40;
    Conn *conn;
};
struct Ops {
    char pad0[0x18];
    void (*release)(void *);
    char pad1C[0x74 - 0x1C];
    int (*compare)(double, double);
    char pad78[8];
    void (*parse)(Token *, const char *);
};
extern "C" Ops *D_0064B4B0;
extern "C" char D_006C40D8[], D_006C41B8[], D_006C41D0[], D_006C4258[];
extern "C" int func_0053BD78(Self *, int *) throw();
extern "C" void func_00540EB0(int);
extern "C" int func_00540F10(int, const char *, int, int);
extern "C" int func_00540F98(int, Args **);
extern "C" int func_00594470(const char *, const char *, unsigned int);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" long func_005A7170(const char *, char **, int) throw();
static inline int compare(double a, double b) { return D_0064B4B0->compare(a, b); }

extern "C" int func_0053D450(Self *self)
{
    Token tmp;
    int status = 0;
    Args *args;
    int err = func_0053BD78(self, &status);

    if (err != 0 || status != 0) {
        if (self->conn->code == 200) {
            if (status != 0) {
                if (func_00540F10(self->conn->handle, D_006C40D8, 0, 1) == 0) {
                    args = 0;
                    if (func_00540F98(self->conn->handle, &args) == 0) {
                        int client = 0;
                        int port = 0;
                        int enabled = 0;
                        unsigned int i;
                        for (i = 0; i < args->count; i++) {
                            D_0064B4B0->parse(&tmp, args->value[i]);
                            if (func_00594470(args->name[i], D_006C41B8, 256) == 0 && compare(self->id.value, tmp.value))
                                client = 1;
                            else if (func_00594470(args->name[i], D_006C41D0, 256) == 0) {
                                if (self->port == (int)func_005A7170(args->value[i], 0, 10))
                                    port = 1;
                            } else if (func_00594470(args->name[i], D_006C4258, 256) == 0)
                                enabled = func_005A7170(args->value[i], 0, 10);
                        }
                        if (client && port && enabled)
                            err = 0;
                        else
                            err = 6;
                    }
                }
            } else
                err = 0xD6DC;
        } else
            err = 0xD6DC;
        func_00540EB0(self->conn->handle);
        self->conn->handle = 0;
        D_0064B4B0->release(self->conn->session);
        self->conn->session = 0;
        func_005A48D8(&self->conn->code, 0, 0x100C);
        self->conn->cb(self, err, self->conn->user);
        self->conn->cb = 0;
        self->busy = 0;
    }
    return err;
}
