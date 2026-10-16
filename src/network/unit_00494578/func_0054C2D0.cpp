/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_0064C3E4;
extern "C" int func_0054A370(int) throw();
extern "C" int func_005B72A8(void);
extern "C" int func_0054C2D0(int n) {
    int result = 0;
    int enabled = func_005B72A8();
    int valid = func_0054A370(n);
    int q = n / 4;
    if (valid) {
        int base = D_0064C3E4;
        int r = n % 4;
        result = *(int *)(((r * 0x1b + q * 0x6f) << 2) + base + 0xbc);
    }
    if (enabled) __asm__ volatile("ei");
    return result;
}
