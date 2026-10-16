extern "C" int func_00571180(void *a, void *b, int *c, int *d, int *e);
extern "C" int func_00570688(void *arg0, void *arg1, void *arg2, void *arg3, int *t0) {
    int sp0 = 0;
    int sp4 = -0x1F5;
    if (arg0 == 0) {
        return -0x1F5;
    }
    if (func_00571180(arg2, arg3, t0, &sp0, &sp4) == 0) {
        return sp0;
    }
    return sp4 == 0 ? -0x1F5 : sp4;
}
