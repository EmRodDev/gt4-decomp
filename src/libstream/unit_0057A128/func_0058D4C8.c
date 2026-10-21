/* compiler: ee-gcc2.9-991111 */
struct Sema { int count, max, init, wait, attr; const char *option; };
struct Client { char pad[0x24]; int server; };
extern int D_00657AF4, D_00657AF8;
extern struct Client D_0087E480;
extern int D_0087FA40[3];
extern char D_0087E500[], D_006CF2E8[], D_006CF2F8[], D_006CF310[], D_006CF328[], D_006CF350[];
int func_0058DF18(int, int *, int *);
int func_005ADCA0(struct Sema *);
void func_005ADCB0(int);
void func_005ADCC0(int);
int func_005ADCE0(int);
void func_005B0750(const char *, ...);
void func_005B1028(int);
int func_005B17D0(struct Client *, int, int);
int func_005B19B0(struct Client *, int, int, void *, int, void *, int, void *, void *);
int func_0058D4C8(void) {
    struct Sema sem;
    int i = 0, j, r;
    if (D_00657AF4 < 0) {
        sem.init = 1;
        sem.option = D_006CF2E8;
        sem.max = 1;
        D_00657AF4 = func_005ADCA0(&sem);
        if (D_00657AF4 == -1) return -101;
        sem.max = 1;
        sem.init = 0;
        sem.option = D_006CF2F8;
        r = func_005ADCA0(&sem);
        D_00657AF8 = r;
        if (r == -1) {
            func_005ADCB0(D_00657AF4);
            D_00657AF4 = r;
            return -101;
        }
    }
    func_0058DF18(0,0,0);
    func_005ADCE0(D_00657AF4);
    func_005B1028(0);
    for (;;) {
        if (func_005B17D0(&D_0087E480, 0x80000400, 0) < 0) {
            func_005B0750(D_006CF310);
            for (;;) ;
        }
        if (D_0087E480.server) break;
        for (j=0x100000; j; j--) ;
        i++;
        if (i >= 512) {
            func_005B0750(D_006CF310);
            return -91;
        }
    }
            r = func_005B19B0(&D_0087E480, 254, 0, D_0087E500, 48, D_0087FA40, 12, 0, 0);
            func_005ADCC0(D_00657AF4);
            if (r < 0) {
                D_0087E480.server = 0;
                return -91;
            }
            if (D_0087FA40[1] < 522) {
                func_005B0750(D_006CF328);
                D_0087E480.server = 0;
                return -120;
            }
            if (D_0087FA40[2] < 526) {
                func_005B0750(D_006CF350);
                D_0087E480.server = 0;
                return -121;
            }
    return D_0087FA40[0];
}
