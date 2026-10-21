/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0057A2B8(signed char *arg0, signed char *arg1) {
    signed char c;
    int d;
    while ((c = *arg0++) != 0) {
        d = *arg1++;
        if (!d) return 1;
        d ^= -0x56;
        if (c < d) return -1;
        if (c > d) return 1;
    }
    return *arg1 == 0 ? 0 : -1;
}
