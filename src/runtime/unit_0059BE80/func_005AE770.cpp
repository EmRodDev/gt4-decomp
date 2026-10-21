extern "C" int func_005AE770(void) {
    int status;
    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    return (status ^ 1) & 1;
}
