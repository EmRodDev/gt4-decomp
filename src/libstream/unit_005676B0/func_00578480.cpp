/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00578290(int arg) throw();
extern "C" void func_00577F80(void) throw();
extern "C" int func_005ADCC0(int sema);
extern "C" int func_005ADCD0(int sema);

extern "C" void func_00578480(int arg) {
    int sema;
    unsigned int status;

    sema = func_00578290(arg);
    if (sema == -1)
        return;
    __asm__ volatile("sync.p");
    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    if (!(status & 1)) {
        func_005ADCD0(sema);
    } else {
        while (func_005ADCC0(sema) == -1)
            func_00577F80();
    }
}
