/* compiler: ee-gcc2.9-991111 */
extern int D_00657500;
extern int D_006570C0[];
extern int D_00657A68, D_00657A6C, D_00657A70;
extern int D_00655EEC;
extern char D_00657A40[];
int func_00580AD0(int);
void func_005ADCC0(int);
int func_005B0F78(void *, int);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);
int func_005813F8(int arg0) {
    int r;
    int *p = &D_00657500;
    if (func_00580AD0(0x22) == 0) return 0;
    *p = arg0;
    func_005B0F78(p, 4);
    if (func_005B19B0(D_00657A40, D_00657A68, 0, p, D_00657A6C, D_006570C0, D_00657A70, 0, 0) < 0) {
        func_005ADCC0(D_00655EEC);
        return 0;
    }
    r = *(int *)((unsigned int)D_006570C0 | 0x20000000);
    func_005ADCC0(D_00655EEC);
    return r;
}
