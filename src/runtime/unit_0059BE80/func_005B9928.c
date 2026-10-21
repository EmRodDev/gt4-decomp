/* compiler: ee-gcc2.9-991111 */
struct Pair { int reg; int value; };
extern struct Pair D_00659698[8];
extern char D_00659318[];
extern int D_00659690;
extern void func_005B9918(int, int);
extern void func_005B98C0(unsigned int, void *, int);
extern void func_005ADF20(int);
extern int func_005B9908(int);
void func_005B9928(void) {
    unsigned int i = 3;
    struct Pair *base = D_00659698;
    struct Pair *p;
    func_005B9918(base[0].reg, base[0].value);
    func_005B98C0(0x80075000U, D_00659318, 0x330);
    func_005ADF20(0);
    func_005ADF20(2);
    func_005B9918(base[1].reg, base[1].value);
    func_005B9918(base[2].reg, base[2].value);
    p = base + 3;
    do {
        int v = func_005B9908(p->reg);
        i++;
        func_005B9918(p->reg, v);
        p++;
    } while (i < 8);
    D_00659690 = func_005B9908(3);
}
