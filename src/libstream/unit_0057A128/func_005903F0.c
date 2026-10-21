/* compiler: ee-gcc2.9-991111 */
typedef struct { int a; int b; int c; unsigned char buf[0x80]; int res; } Req;
extern int D_00885280;
extern Req D_00882EC0;
extern char D_00882DC0[];
void func_00590950(int, ...);
void func_005ADCC0(int);
int func_005ADCE0(int);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);

/* sceDbcSendData */
int func_005903F0(int arg0, int arg1, int *len, unsigned char *data) {
    Req *r;
    int i;
    int res;
    func_005ADCE0(D_00885280);
    r = &D_00882EC0;
    D_00882EC0.a = arg0;
    r->b = arg1;
    r->c = *len;
    for (i = 0; i < *len; i++) r->buf[i] = data[i];
    if (func_005B19B0(D_00882DC0, 0x80001319, 0, &D_00882EC0, 0x90, &D_00882EC0, 0x90, 0, 0) < 0) {
        func_00590950((int)"sceDbcSendData: rpc error\n");
        func_005ADCC0(D_00885280);
        return 0;
    }
    res = r->res;
    if (res >= 0) {
        *len = r->c;
        res = r->res;
    }
    func_005ADCC0(D_00885280);
    return res;
}
