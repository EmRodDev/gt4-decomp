/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_005763B0(void);
extern "C" void func_005AED18(int usec);

/* Waits 2000 microseconds with the thread delay when interrupts are on; does nothing with them off. */
extern "C" void func_00577F80(void) {
    unsigned int status;

    __asm__ volatile("sync.p");
    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    if (!(status & 1))
        func_005763B0();
    else
        func_005AED18(2000);
}
