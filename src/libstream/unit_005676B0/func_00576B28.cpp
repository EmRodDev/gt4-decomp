/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_005AE6D8(void *start, void *end);
extern "C" void func_005AE758(void *start, void *end);

/* Writes back the data cache over [p, p + size), with the interrupt-safe variant when interrupts are off. */
extern "C" void func_00576B28(char *p, int size) {
    unsigned int status;
    void (*sync)(void *, void *);

    __asm__ volatile("sync.p");
    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    sync = func_005AE6D8;
    if (!(status & 1))
        sync = func_005AE758;
    sync(p, p + size - 1);
}
