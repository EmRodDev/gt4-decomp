/* compiler: ee-gcc2.9-991111 */
typedef struct { int a; int b; int c; unsigned char buf[0x2084]; } Req3;
extern int D_00885280;
extern Req3 D_00882F80;
extern char D_00882E10[];
void func_00590950(int, ...);
void func_005ADCC0(int);
int func_005ADCE0(int);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);
int func_005B1BB0(void *);

/* sceDbcSendData3 */
int func_005906D0(int arg0, int arg1, int *len, unsigned char *data, void *cb) {
    Req3 *r;
    int i;
    if (*len > 0x2080) {
        func_00590950((int)"libdbc: SendData3 data length too long [%d]\n", *len);
        return 0;
    }
    func_005ADCE0(D_00885280);
    if (func_005B1BB0(D_00882E10) == 1) {
        func_00590950((int)"dbcman : SendData3 BUSY\n");
        func_005ADCC0(D_00885280);
        return 0;
    }
    r = &D_00882F80;
    D_00882F80.a = arg0;
    r->b = arg1;
    r->c = *len;
    for (i = 0; i < *len; i++) r->buf[i] = data[i];
    if (func_005B19B0(D_00882E10, 0x8000131C, 1, &D_00882F80, 0x2090, &D_00882F80, 0x2090, cb, 0) < 0) {
        func_005ADCC0(D_00885280);
        return 0;
    }
    func_005ADCC0(D_00885280);
    return 1;
}
