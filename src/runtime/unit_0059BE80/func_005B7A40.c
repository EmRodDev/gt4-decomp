/* compiler: ee-gcc2.9-991111 */
struct Pair { int a; int b; };
extern struct Pair D_006592B0[8];
extern char D_00658B48[], D_00659288[];
extern void func_005B79D8(int, int);
extern void func_005B79E8(unsigned int, void *, unsigned int);
extern void func_005ADF20(int);
extern int func_005B7A30(int);
void func_005B7A40(void) {
    unsigned int i;
    struct Pair *p;
    struct Pair *base;
    if (!(*(volatile unsigned int *)0x10001810 & 0x100)) {
        i = 2;
        base = D_006592B0;
        p = base + 2;
        func_005B79D8(base[0].a, base[0].b);
        func_005B79E8(0x80076000, D_00658B48, 0x740);
        func_005B79E8(0x82000, D_00659288, 0x28);
        func_005ADF20(0);
        func_005ADF20(2);
        { int a = *(volatile int *)&base[1].a; func_005B79D8(a, base[1].b); }
        do {
            int value = func_005B7A30(p->a);
            i++;
            func_005B79D8(p->a, value);
            p++;
        } while (i < 8);
    }
}
