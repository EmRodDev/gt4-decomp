/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Shared run flag: set by 0055EC60 and read by the worker 0055EB50. */
extern volatile int D_00654A38;
extern int D_00873EC0;
extern "C" void func_00578908(int);
extern "C" void func_0055ECC8(void) {
    volatile int *runFlag = &D_00654A38;
    *runFlag = 0;
    func_00578908(D_00873EC0);
}
