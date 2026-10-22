/* compiler: ee-gcc2.9-991111 */
struct Result { char bytes[36]; };
struct Request { struct Result result; char name[256]; void *self; int mode; };
typedef struct { char pad[0x24]; int f24; } Dev;
extern struct Request D_00874E00;
extern Dev D_00874F80;
extern int D_00874F40;
extern volatile int D_00655EE8;
extern int D_00655EDC, D_00655F0C, D_00655ED0;
extern char D_006CE028[], D_006CE048[], D_006CE060[], D_006CE070[], D_006CE080[];
extern void func_005801D8(void);
extern int func_005ADCF0(int);
extern int func_005809C0(int);
extern void func_005B1028(int);
extern int func_005B17D0(void *, int, int);
extern void func_005B0750(const char *, ...);
extern void func_005B0F78(void *, int);
extern int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);
extern void func_005ADCC0(int);
int func_005804B0(struct Result *out, char *name, int mode) {
    int i, d, result;
    func_005801D8();
    if (D_00655EE8 != func_005ADCF0(D_00655EE8)) return 0;
    D_00655EDC = 1;
    if (func_005809C0(1)) {
        func_005ADCC0(D_00655EE8);
        return 0;
    }
    {
        func_005B1028(0);
        if (D_00655F0C < 0) {
            for (;;) {
                if (func_005B17D0(&D_00874F80, 0x80000597, 0) < 0) {
                    if (D_00655ED0 > 0) func_005B0750(D_006CE028);
                    for (d = 0x100000; d != -1; d--) ;
                    continue;
                }
                if (D_00874F80.f24 != 0) { D_00655F0C = 0; break; }
                for (d = 0x100000; d != -1; d--) ;
            }
        }
        for (i = 0; i < 256; i++) {
            if (!(D_00874E00.name[i] = name[i])) break;
        }
        if (i == 256) D_00874E00.name[255] = 0;
        if (D_00655ED0 > 0) func_005B0750(D_006CE048, D_00874E00.name);
        D_00874E00.mode = mode;
        D_00874E00.self = &D_00874E00;
        func_005B0F78(&D_00874E00, 300);
        if (func_005B19B0(&D_00874F80, 0, 0, &D_00874E00, 300, &D_00874F40, 4, 0, 0) < 0) {
            func_005ADCC0(D_00655EE8);
            return 0;
        }
        {
            *out = *(struct Result *)((unsigned int)&D_00874E00 | 0x20000000);
            if (D_00655ED0 > 0) func_005B0750(D_006CE060, out->bytes + 8);
            if (D_00655ED0 > 0) func_005B0750(D_006CE070, *(int *)(out->bytes + 4));
            if (D_00655ED0 > 0) func_005B0750(D_006CE080, *(int *)out->bytes);
            result = *(int *)((unsigned int)&D_00874F40 | 0x20000000);
            func_005ADCC0(D_00655EE8);
            return result;
        }
    }
}
