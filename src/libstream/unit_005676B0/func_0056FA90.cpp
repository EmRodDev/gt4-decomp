extern "C" int func_00590E98(int,int);
extern "C" int func_0056FA90(int arg) {
    int r;
    for (;;) {
        r = func_00590E98(arg, 0);
        if (r < 0) return -0x21C;
        if (r == 1) break;
        for (unsigned n = 0x10000; n--; ) { }
    }
    return 0;
}
