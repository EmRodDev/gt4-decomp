/* compiler: ee-gcc2.9-991111 */
/* scePad2CreateSocket-style open of a pad socket (libpad2 shape, Sony SDK code built with ee-gcc 2.9).
   The work buffer `port` must be 64-byte aligned (two 0x80-byte halves are handed to the IOP side
   by func_0058FB38). The caller's parameters, or zeroes when none are given, go into the request
   with flag bit 0 set and a count of one; on success the socket's slot in D_0087FA80 is marked
   open, remembers the buffer, and func_0058F2D0 resets both halves of it. Returns the socket
   number, a negative error from the IOP side, or -1 for a misaligned buffer. */
typedef struct { unsigned char b[16]; } B16;
typedef struct { int a; int b; int c; int d; int e; B16 name; } Arg;
typedef struct { int a; int c; int d; int e; B16 name; } Param;
typedef struct Port {
    int state;
    int unk4;
    int unk8;
    int unkC;
    void *port;
    char pad[0x334 - 0x14];
} Port;

extern Port D_0087FA80[];
extern char D_006CF398[];
void func_005B0750(const char *fmt, ...);
int func_0058FB38(Arg *arg0, void *arg1, void *arg2);
void func_0058F2D0(int arg0);

int func_0058EDA8(Param *param, char *port) {
    Arg r;
    int one;
    int s;

    if ((int)port & 0x3F) {
        func_005B0750(D_006CF398);
        return -1;
    }
    if (param != 0) {
        r.a = param->a;
        r.c = param->c;
        r.d = param->d;
        r.e = param->e;
        r.name = param->name;
    } else {
        r.a = 0;
        r.c = 0;
        r.d = 0;
        r.e = 0;
        r.name.b[0] = 0;
    }
    one = 1;
    r.b = one;
    r.a |= 1;
    s = func_0058FB38(&r, port, port + 0x80);
    if (s < 0)
        return s;
    D_0087FA80[s].state = one;
    D_0087FA80[s].port = port;
    func_0058F2D0(s);
    return s;
}
