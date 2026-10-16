extern "C" void func_0056DD70(short scale, short *in, short *out, int n) {
    int power = scale;
    n++;
    out[0] = in[0];
    int i = 1;
    int base = power;
    for (; i < n; i++) {
        int val = (power * in[i] + 0x4000) >> 15;
        power = (short)((power * base + 0x4000) >> 15);
        out[i] = val;
    }
}
