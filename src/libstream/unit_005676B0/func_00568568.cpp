typedef unsigned long u64;
extern "C" void func_0054D5C8(void);
extern "C" int func_00563198(int);
extern "C" void func_00563258(unsigned);
extern "C" int func_00568568(void) {
    int total = 0;
    int value;
    while ((value = func_00563198(11)) < 24) {
        if (value != 15) total += 33;
        func_00563258(11);
    }
    if (value >= 1024) {
        func_00563258(1);
        return total + 1;
    }
    func_0054D5C8();
    *(volatile unsigned *)0x10002000 = 0x30000000;
    __asm__ volatile("sync");
    func_0054D5C8();
    return total + (int)(*(volatile u64 *)0x10002000 & 0xffff);
}
