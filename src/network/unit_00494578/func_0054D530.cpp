/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_0086F608;
extern int D_0086F60C;
#define CTRL (*(volatile int *)0x10002010)
extern "C" void func_0054D530(int x, int y) {
    D_0086F608 = x;
    D_0086F60C = y;
    while (CTRL < 0) {}
    unsigned int low = D_0086F608 & 0x1FF;
    unsigned int high = (D_0086F60C << 16) & 0x01FF0000;
    unsigned int command = 0x90000000;
    command |= low;
    command |= high;
    *(volatile int *)0x10002000 = command;
    __asm__ volatile("sync" ::: "memory");
    while (CTRL < 0) {}
}
