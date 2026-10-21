/* compiler: ee-gcc2.9-991111 */
extern int func_005B7620(void);
extern void func_005B75B8(int, int);
extern void func_005B75C8(unsigned int, void *, int);
extern void func_005ADF20(int);
extern int func_005B7610(int);
extern int D_00658B28[];
extern char D_00658380[];
void func_005B7688(void) {
    if (func_005B7620()) {
        int first;
        unsigned int i = 2;
        int *base = D_00658B28;
        int *p = base + 4;
        func_005B75B8(base[0], base[1]);
        func_005B75C8(0x80074000, D_00658380, 0x7A8);
        func_005ADF20(0);
        func_005ADF20(2);
        first = *(volatile int *)&base[2];
        func_005B75B8(first, base[3]);
        do {
            int value = func_005B7610(*p);
            i++;
            func_005B75B8(*p, value);
            p += 2;
        } while (i < 3);
    }
}
