/* compiler: ee-gcc2.9-991111 */
typedef struct { int a; int b; int c; int d; int e; unsigned char buf[16]; int res; void *f28; void *f2c; } Req;
typedef struct { int a; int b; int c; int d; int e; unsigned char buf[16]; } Arg;
extern int D_00657B50;
extern int D_00885280;
extern Req D_00882EC0;
extern char D_00882DC0[];
void func_00590950(int, ...);
void func_005ADCC0(int);
int func_005ADCE0(int);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);

int func_0058FB38(Arg *arg0, void *arg1, void *arg2) {
    Req *r;
    int i;
    int res;
    if (D_00657B50 == 0) return 0;
    func_005ADCE0(D_00885280);
    { int a = arg0->a;
    r = &D_00882EC0;
    D_00882EC0.a = a; }
    r->f28 = arg1;
    r->f2c = arg2;
    r->b = arg0->b;
    r->c = arg0->c;
    r->d = arg0->d;
    r->e = arg0->e;
    for (i = 0; i < 16; i++) r->buf[i] = arg0->buf[i];
    if (func_005B19B0(D_00882DC0, 0x80001301, 0, &D_00882EC0, 0x90, &D_00882EC0, 0x90, 0, 0) < 0) {
        func_00590950((int)"sceDbcCreateSocket: rpc error\n");
        func_005ADCC0(D_00885280);
        return 0;
    }
    res = r->res;
    func_005ADCC0(D_00885280);
    return res;
}
