/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char *D_0064C3E4;
extern "C" int func_005B72A8();
extern "C" int func_0054A370(int) throw();
struct State { char pad[0x68]; int value; };
extern "C" int func_0054A7F0(int n) {
    int value = 1;
    int intr = func_005B72A8();
    if (func_0054A370(n)) {
        int q = n / 4;
        int r = n % 4;
        State *p = (State *)((((r * 27 + q * 111) << 2) + (int)D_0064C3E4) + 0x78);
        value = p->value;
        p->value = 0;
    }
    if (intr) __asm__ volatile("ei");
    return value;
}
