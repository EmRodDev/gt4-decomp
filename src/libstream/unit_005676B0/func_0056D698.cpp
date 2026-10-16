extern "C" void func_0056D698(short *a, short *b, short *out, int n, int step, int length) {
    short t = ((step + 1) << 14) / (short)length;
    short s = 0x4000 - t;
    for (int i = 0; i < n; i++) {
        out[i] = ((s * a[i] + 0x2000) >> 14) + ((t * b[i] + 0x2000) >> 14);
    }
}
