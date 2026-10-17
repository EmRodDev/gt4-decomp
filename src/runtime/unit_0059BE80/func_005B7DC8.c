/* compiler: ee-gcc2.9-991111 */
extern int D_006592F8;

unsigned int func_005B7DC8(void) {
    if (D_006592F8 < 0)
        return 0x80008001;
    return *(volatile unsigned int *)0x10001010 & 3;
}
