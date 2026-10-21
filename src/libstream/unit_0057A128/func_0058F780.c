/* compiler: ee-gcc2.9-991111 */
struct Cl { int x[9]; int server; };
struct Sema { int attr, option, init, max, pad; const char *name; };
extern int D_00657B50, D_00885280;
extern struct Cl D_00882DC0, D_00882E10, D_00882E38[2];
extern int D_00885240[16];
extern char D_008851C0[];
extern char D_006CF3F8[], D_006CF410[], D_006CF438[], D_006CF468[], D_006CF478[];
extern int func_0058F728(void);
extern int func_0058FAC8(void *);
extern void func_00590950(const char *, ...);
extern int func_005ADCA0(struct Sema *);
extern void func_005B0750(const char *, ...);
extern void func_005B1028(int);
extern int func_005B17D0(struct Cl *, int, int);
int func_0058F780(void) {
    int i, j, k, version;
    struct Sema sem;
    if (D_00657B50 == 1) return 1;
    D_00885280 = 0;
    func_005B1028(0);
    while (1) {
        if (func_005B17D0(&D_00882DC0, 0x80001300, 0) < 0) goto fail;
        j = 0x10000;
        if (D_00882DC0.server) break; do { j--; } while (j != -1);
    }
    version = func_0058F728();
    if ((version >> 4) != 0x31) {
        func_005B0750(D_006CF410);
        func_005B0750(D_006CF438, 3, 0x10, version >> 8, version & 255);
        return 0;
    }
    while (1) {
        if (func_005B17D0(&D_00882E10, 0x8000131C, 0) < 0) goto fail;
        if (D_00882E10.server) break;
        for (j = 0x10000; --j != -1;) {}
    }
    for (i = 0; i < 2; i++) {
        while (1) {
            if (func_005B17D0(&D_00882E38[i], 0x8000131E + i, 0) < 0) goto fail;
            j = 0x10000;
            if (D_00882E38[i].server) break; do { j--; } while (j != -1);
        }
    }
    sem.init = 1;
    sem.option = 0x7f;
    sem.name = D_006CF468;
    D_00885280 = func_005ADCA0(&sem);
    if (D_00885280 < 0) {
        return 0;
fail:
        func_00590950(D_006CF3F8);
        return 0;
    }
    for (k = 15; k >= 0; k--) D_00885240[k] = 0;
    func_00590950(D_006CF478, D_008851C0);
    func_0058FAC8(D_008851C0);
    D_00657B50 = 1;
    return 1;
}
