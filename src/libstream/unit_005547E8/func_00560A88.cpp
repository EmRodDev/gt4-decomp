/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int *D_00654A84;
extern "C" int func_00560A88(int *out) {
    if (out == 0) return 0x80000004;
    *out = *D_00654A84;
    *D_00654A84 = 0;
    return 0;
}
