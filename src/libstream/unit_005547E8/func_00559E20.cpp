/* compiler: ee-gcc2.96-no-strict-aliasing */
extern volatile int D_006504F8;
extern "C" void func_0055ECC8(void);
extern "C" void func_00559E20(void) {
    volatile int *flag = &D_006504F8;
    if (*flag != 0) {
        *flag = 0;
        func_0055ECC8();
    }
}
