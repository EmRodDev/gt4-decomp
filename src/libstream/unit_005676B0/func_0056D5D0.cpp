extern "C" void func_0056D5D0(short *p, int n, short gap) {
    short upper = 0x6488 - gap;
    int i;

    if (p[0] < gap) p[0] = gap;
    if (p[n - 1] > upper) p[n - 1] = upper;
    for (i = 1; i < n - 1; i++) {
        if (p[i] < p[i - 1] + gap) p[i] = p[i - 1] + gap;
        if (p[i + 1] - gap < p[i]) p[i] = (p[i] >> 1) + ((p[i + 1] - gap) >> 1);
    }
}
