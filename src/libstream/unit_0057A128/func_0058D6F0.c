/* compiler: ee-gcc2.9-991111 */
/* Drain the library's pending operation before deleting its semaphores. */
extern int D_00657AF4, D_00657AF8;
extern int func_0058DF18(int, int *, int *);
extern int func_005ADCB0(int);
int func_0058D6F0(void) {
    if (D_00657AF4 >= 0) {
        func_0058DF18(0, 0, 0);
        func_005ADCB0(D_00657AF4);
        D_00657AF4 = -1;
        func_005ADCB0(D_00657AF8);
    }
    return 1;
}
