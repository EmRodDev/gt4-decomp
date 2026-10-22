typedef unsigned int u128 __attribute__((mode(TI)));
extern int D_00654D84;

/* Copies four quadwords (64 bytes) from s[i..i+3] to d[i..i+3] through a, b, c, e. */
#define COPY64(d, s, i) do { a = ((volatile u128 *)(s))[(i) + 0]; b = ((volatile u128 *)(s))[(i) + 1]; c = ((volatile u128 *)(s))[(i) + 2]; e = ((volatile u128 *)(s))[(i) + 3]; ((volatile u128 *)(d))[(i) + 0] = a; ((volatile u128 *)(d))[(i) + 1] = b; ((volatile u128 *)(d))[(i) + 2] = c; ((volatile u128 *)(d))[(i) + 3] = e; } while (0)

extern "C" void func_00569EB8(char *src, char *dst, int row, int col) {
    u128 a, b, c, e;
    dst += (((row >> 4) * D_00654D84) + (col >> 4)) * 0x180;
    COPY64(dst, src, 0);
    COPY64(dst, src, 4);
    COPY64(dst, src, 8);
    COPY64(dst, src, 12);
    COPY64(dst, src, 16);
    COPY64(dst, src, 20);
}
