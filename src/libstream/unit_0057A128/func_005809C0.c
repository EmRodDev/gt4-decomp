/* compiler: ee-gcc2.9-991111 */
extern int D_00655ED0;
extern int D_00655EF4;
extern char D_00657090[];
extern char D_006CE0D8[];
void func_005AED18(int);
void func_005B0750(const char *, ...);
int func_005B1BB0(void *);

int func_005809C0(int mode)
{
    if (mode == 0) {
        if (D_00655ED0 > 0)
            func_005B0750(D_006CE0D8);
        while (D_00655EF4 != 0 || func_005B1BB0(D_00657090) != 0)
            func_005AED18(0xFA0);
        return 0;
    }
    if (D_00655EF4 != 0 || func_005B1BB0(D_00657090) != 0)
        return 1;
    return 0;
}
