/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_0086F604[];
extern "C" int func_005AEB68(int);
extern "C" void func_0054D0B8(int unused0, int unused1, int arg2) {
    *(volatile int *)D_0086F604 = -1;
    func_005AEB68(arg2);
    __asm__ volatile("sync");
    __asm__ volatile("ei");
}
