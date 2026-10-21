/* compiler: ee-gcc2.9-as296 */
int func_005AF4C8(int c) {
    while (*(volatile int *)0x1000F130 & 0x8000) {}
    *(volatile char *)0x1000F180 = c;
    return c;
}
