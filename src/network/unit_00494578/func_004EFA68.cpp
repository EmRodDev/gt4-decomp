/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_006454DC;
extern "C" int func_005B72A8(void);
extern "C" int func_004EFA68(void) {
    int enabled = func_005B72A8();
    int previous = D_006454DC;
    D_006454DC = 1;
    if (enabled) __asm__ volatile("ei");
    return previous ^ 1;
}
