/* compiler: ee-gcc2.9-991111 */
void func_005AE010(volatile int *,long *);
int func_005B72A8(void);
int func_005B72F8(void);
long func_005AE1C0(void) {
    struct { volatile int flag; int pad; volatile long value; } local;
    int intr;
    local.flag=0;
    func_005AE010(&local.flag,(long *)((unsigned int)&local | 8));
    intr=func_005B72A8();
    *(volatile int *)0x1000F000=4;
    __asm__ volatile("sync");
    if(intr) func_005B72F8();
    while(!(*(volatile int *)0x1000F000&4) && local.flag==0) {}
    intr=func_005B72A8();
    *(volatile int *)0x1000F000=4;
    __asm__ volatile("sync");
    if(intr) func_005B72F8();
    return local.value;
}
