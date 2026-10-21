/* compiler: ee-gcc2.9-991111 */
extern int func_005B72A8(void);
extern int func_005B72F8(void);
void func_005AE130(void) {
    int intr;
    intr=func_005B72A8();
    *(volatile int *)0x1000F000=4;
    __asm__ volatile("sync");
    if(intr) func_005B72F8();
    while(!(*(volatile int *)0x1000F000&4)) {}
    intr=func_005B72A8();
    *(volatile int *)0x1000F000=4;
    __asm__ volatile("sync");
    if(intr) func_005B72F8();
}
