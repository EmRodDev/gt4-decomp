/* compiler: ee-gcc2.9-991111 */
struct SemaParam { int current, max, init, wait; unsigned int attr; const char *option; };
extern volatile int D_00655EE8, D_00655EEC, D_00655EF0, D_00655EE0, D_00655EF4;
extern char D_006CDFE0[], D_006CDFF0[], D_006CE000[], D_006CE010[];
extern int func_005ADCA0(void *);
void func_005801D8(void) {
    struct SemaParam p;
    if (D_00655EE8 == -1 || D_00655EEC == -1 || D_00655EF0 == -1) {
        p.init = 1;
        p.max = 1;
        p.option = D_006CDFE0;
        D_00655EE8 = func_005ADCA0(&p);
        p.option = D_006CDFF0;
        D_00655EEC = func_005ADCA0(&p);
        p.option = D_006CE000;
        D_00655EF0 = func_005ADCA0(&p);
        p.option = D_006CE010;
        p.init = 0;
        D_00655EE0 = func_005ADCA0(&p);
        D_00655EF4 = 0;
    }
}
