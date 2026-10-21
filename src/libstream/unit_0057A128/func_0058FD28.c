/* compiler: ee-gcc2.9-991111 */
struct P64 { char a[64]; };
struct Rq { int v0; int v4; };
extern struct P64 D_008851C0;
extern struct P64 D_00885240;
extern int D_00885280;
extern struct Rq D_00882EC0;
extern char D_00882DC0[];
extern void func_00590950(const char *, ...);
extern void func_005ADCC0(int);
extern int func_005ADCE0(int);
extern void func_005AE598(void *, void *);
extern int func_005B19B0(void *, int, int, void *, int, void *, int, void *, int);
extern int func_005B72A8(void);
extern int func_005B72F8(void);

int func_0058FD28(int idx) {
    int r;
    func_005AE598(&D_008851C0, &D_008851C0 + 2);
    func_005B72A8();
    D_00885240 = D_008851C0;
    func_005B72F8();
    if (((int *)&D_00885240)[idx] != 1) return -12;
    func_005ADCE0(D_00885280);
    D_00882EC0.v0 = idx;
    if (func_005B19B0(D_00882DC0, 0x80001303, 0, &D_00882EC0, 0x90, &D_00882EC0, 0x90, 0, 0) < 0) {
        func_00590950("sceDbcGetDepNumber: rpc error\n");
        func_005ADCC0(D_00885280);
        return 0;
    }
    r = D_00882EC0.v4;
    func_005ADCC0(D_00885280);
    return r;
}
