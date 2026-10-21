/* compiler: ee-gcc2.9-991111 */
struct Req { int a, result, cmd, d, x, y; };
struct Arg { int a,b,x,y; };
extern int D_00885280;
extern struct Req D_00882EC0;
extern char D_00882DC0[];
extern void func_00590950(const char *, ...);
extern void func_005ADCC0(int);
extern int func_005ADCE0(int);
extern int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);
int func_005901A0(struct Arg *arg) {
    struct Req *r;
    int result;
    func_005ADCE0(D_00885280);
    r = &D_00882EC0;
    r->cmd = 2;
    r->x = arg->x;
    r->y = arg->y;
    if (func_005B19B0(D_00882DC0, 0x8000131D, 0, r, 0x90, r, 0x90, 0, 0) < 0) {
        func_00590950("sceDbcGetDeviceStatus: rpc error\n");
        func_005ADCC0(D_00885280);
        return -1;
    }
    result = r->result;
    func_005ADCC0(D_00885280);
    return result;
}
