/* compiler: ee-gcc2.9-991111 */
struct Buf { int a; int b; int len; unsigned char data[0xB4]; };
struct Cli { char pad[0x28]; };
extern struct Buf D_00885040[2];
extern struct Cli D_00882E38[2];
extern int D_00885280;
extern int D_00657B54;
extern void func_00590950(const char *, ...);
extern void func_005ADCC0(int);
extern int func_005ADCE0(int);
extern int func_005B19B0(void *, int, int, void *, int, void *, int, void *, int);
extern int func_005B1BB0(void *);

int func_00590520(int a, int b, int *len, unsigned char *data, long unusedw0) {
    struct Buf *p;
    int i;
    if (*len > 0x80) {
        func_00590950("libdbc: SendData2 data length too long [%d]\n", *len);
        return 0;
    }
    func_005ADCE0(D_00885280);
    D_00657B54++;
    if (D_00657B54 >= 2) D_00657B54 = 0;
    p = &D_00885040[D_00657B54];
    p->a = a;
    p->b = b;
    p->len = *len;
    for (i = 0; i < *len; i++) p->data[i] = data[i];
    if (func_005B1BB0(&D_00882E38[D_00657B54]) == 1) {
        func_00590950("dbcman : SendData2 BUSY\n");
        func_005ADCC0(D_00885280);
        return 0;
    }
    if (func_005B19B0(&D_00882E38[D_00657B54], D_00657B54, 1, &D_00885040[D_00657B54], 0x90, &D_00885040[D_00657B54], 0x90, 0, 0) < 0) {
        func_00590950("sceDbcSendData2: rpc error\n");
        func_005ADCC0(D_00885280);
        return 0;
    }
    func_005ADCC0(D_00885280);
    return 1;
}
