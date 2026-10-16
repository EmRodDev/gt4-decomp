/* compiler: ee-gcc2.9-991111 */
void func_005B72A8(void);
void func_005B72F8(void);
void func_005AE630(unsigned int, unsigned int);

void func_005AE6D8(unsigned int start, unsigned int end) {
    unsigned int enabled;
    __asm__ volatile ("mfc0 %0,$12" : "=r" (enabled));
    enabled &= 0x10000;
    if (enabled)
        func_005B72A8();
    func_005AE630(start & ~63U, end & ~63U);
    if (enabled)
        func_005B72F8();
}
