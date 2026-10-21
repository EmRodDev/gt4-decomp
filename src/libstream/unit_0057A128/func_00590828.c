/* compiler: ee-gcc2.9-991111 */
typedef struct { int a; int b; int c; unsigned char buf[0x80]; int res; } Req;
extern int D_00885280;
extern Req D_00882EC0;
extern char D_00882DC0[];
void func_00590950(int, ...);
void func_005ADCC0(int);
int func_005ADCE0(int);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);

int func_00590828(int arg0, int arg1, int *arg2, unsigned char *arg3) {
    Req *r;
    int i;
    int res;
    func_005ADCE0(D_00885280);
    r = &D_00882EC0;
    D_00882EC0.a = arg0;
    r->b = arg1;
    r->c = *arg2;
    if (func_005B19B0(D_00882DC0, 0x8000131A, 0, r, 0x90, r, 0x90, 0, 0) < 0) {
        func_00590950((int)"sceDbcReceiveData: rpc error\n");
        func_005ADCC0(D_00885280);
        return 0;
    }
    res = r->res;
    if (res >= 0) {
        *arg2 = r->c;
        for (i = 0; i < r->c; i++) arg3[i] = r->buf[i];
        res = r->res;
    }
    func_005ADCC0(D_00885280);
    return res;
}
