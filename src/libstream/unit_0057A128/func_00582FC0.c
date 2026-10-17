/* compiler: ee-gcc2.9-991111 */
extern int D_00655ED0;
extern int D_00657A74;
extern char D_00875850[];
extern void func_005B0750(const char *fmt, ...);
extern int func_005830B0(unsigned int, unsigned int, void *, int, void *);

int func_00582FC0(void)
{
    D_00657A74 = 0;
    if (D_00655ED0 > 0)
        func_005B0750("sceCdStPause call\n");
    return func_005830B0(0, 0, 0, 7, D_00875850);
}
