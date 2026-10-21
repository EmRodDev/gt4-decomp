/* compiler: ee-gcc2.9-991111 */
typedef struct { int a; int b; int c; int d; unsigned char sbuf[0x80]; unsigned char rbuf[0x80]; int res; } Req;
extern int D_00885280;
extern Req D_00882EC0;
extern char D_00882DC0[];
void func_00590950(int, ...);
void func_005ADCC0(int);
int func_005ADCE0(int);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);

/* sceDbcSRData */
int func_00590260(int arg0, int arg1, int *slen, unsigned char *sdata, int *rlen, unsigned char *rdata) {
    Req *r;
    int i;
    int res;
    func_005ADCE0(D_00885280);
    r = &D_00882EC0;
    D_00882EC0.a = arg0;
    r->b = arg1;
    r->c = *slen;
    r->d = *rlen;
    for (i = 0; i < *slen; i++) r->sbuf[i] = sdata[i];
    if (func_005B19B0(D_00882DC0, 0x80001318, 0, &D_00882EC0, 0x90, &D_00882EC0, 0x90, 0, 0) < 0) {
        func_00590950((int)"sceDbcSRData: rpc error\n");
        func_005ADCC0(D_00885280);
        return 0;
    }
    res = r->res;
    if (res >= 0) {
        *slen = r->c;
        *rlen = r->d;
        for (i = 0; i < r->d; i++) rdata[i] = r->rbuf[i];
        res = r->res;
    }
    func_005ADCC0(D_00885280);
    return res;
}
