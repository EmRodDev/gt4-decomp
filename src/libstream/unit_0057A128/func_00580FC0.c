/* compiler: ee-gcc2.9-991111 */
typedef struct { char pad[0x24]; int f24; } Dev;
extern volatile int D_00655EEC;
extern int D_00655ED0, D_00655F00, D_00655F10;
extern int D_00875010, D_006570C0;
extern Dev D_00874FD0;
extern char D_006CE168[], D_006CE180[], D_006CE1A0[];
extern void func_005801D8(void);
extern int func_00580A60(int);
extern void func_005ADCC0(int);
extern int func_005ADCF0(int);
extern void func_005B0750(const char *, ...);
extern void func_005B0F78(void *, int);
extern void func_005B1028(int);
extern int func_005B17D0(void *, int, int);
extern int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_005B72A8(void);
extern int func_005B72F8(void);
int func_00580FC0(int a) {
    int i, intr, result;
    if (D_00655ED0 > 0) func_005B0750(D_006CE168);
    intr = func_005B72A8();
    D_00655F00 = 1;
    if (intr) func_005B72F8();
    func_005801D8();
    if (D_00655EEC != func_005ADCF0(D_00655EEC)) return 6;
    if (func_00580A60(1)) {
        func_005ADCC0(D_00655EEC);
        return a != 8 ? 6 : -1;
    }
    {
        func_005B1028(0);
        if (D_00655F10 < 0) {
            for (;;) {
                if (func_005B17D0(&D_00874FD0, 0x8000059A, 0) < 0) {
                    if (D_00655ED0 > 0) func_005B0750(D_006CE180);
                    for (i = 0x100000; i != -1; i--) ;
                    continue;
                }
                if (D_00874FD0.f24 != 0) { D_00655F10 = 0; break; }
                for (i = 0x100000; i != -1; i--) ;
            }
        }
        D_00875010 = a;
        func_005B0F78(&D_00875010, 4);
        if (func_005B19B0(&D_00874FD0, 0, 0, &D_00875010, 4, &D_006570C0, 4, 0, 0) < 0) {
            func_005ADCC0(D_00655EEC);
            return a != 8 ? 6 : -1;
        }
        {
            if (D_00655ED0 > 0) func_005B0750(D_006CE1A0);
            result = *(int *)((unsigned int)&D_006570C0 | 0x20000000);
            func_005ADCC0(D_00655EEC);
            return result;
        }
    }
}
