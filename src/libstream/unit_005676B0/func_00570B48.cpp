extern "C" int func_00571480(void *a, int b, void *c, int *d, int *e);
extern "C" int func_00570B48(void *arg0, int unused, void *arg2, unsigned short arg3, void *t0) {
    int sp0 = 0;
    int sp4 = -0x1F5;
    if (arg0 == 0) {
        return -0x1F5;
    }
    if (func_00571480(arg2, arg3, t0, &sp0, &sp4) == 0) {
        return sp0;
    }
    return sp4 == 0 ? -0x1F5 : sp4;
}
