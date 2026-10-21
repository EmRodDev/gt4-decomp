/* compiler: ee-gcc2.9-991111 */
typedef struct { char pad[0x24]; int f24; } Dev;
extern volatile int D_00655EE8;
extern int D_00655ED0;
extern int D_00655EDC;
extern int D_00655EFC;
extern Dev D_00657090;
extern void func_005801D8(void);
extern int func_005809C0(int);
extern void func_005ADCC0(int);
extern int func_005ADCF0(int);
extern void func_005B0750(const char *, ...);
extern void func_005B1028(int);
extern int func_005B17D0(void *, int, int);
extern char D_006CE098[];
extern char D_006CE0C0[];

int func_005807D0(int a) {
    int i;
    func_005801D8();
    if (D_00655EE8 != func_005ADCF0(D_00655EE8)) {
        if (D_00655ED0 > 0) func_005B0750(D_006CE098, a, D_00655EDC);
        return 0;
    }
    D_00655EDC = a;
    if (func_005809C0(1)) {
        func_005ADCC0(D_00655EE8);
        return 0;
    }
    func_005B1028(0);
    if (D_00655EFC < 0) {
        for (;;) {
            if (func_005B17D0(&D_00657090, 0x80000595, 0) < 0) {
                if (D_00655ED0 > 0) func_005B0750(D_006CE0C0);
                for (i = 0x100000; i != -1; i--) ;
                continue;
            }
            if (D_00657090.f24 != 0) break;
            for (i = 0x100000; i != -1; i--) ;
        }
        D_00655EFC = 0;
    }
    return 1;
}
