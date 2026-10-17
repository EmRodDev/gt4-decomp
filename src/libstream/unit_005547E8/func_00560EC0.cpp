/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Result { int w[6]; };
struct Request {
    int status;
    int pad4;
    int a[20];
    int pad58;
    int count;
    int b[4];
    Result results[4];
};
extern Request D_00873F40;
extern char D_00873F00[];
extern "C" int func_005616E8(int, int);
extern "C" int func_005B19B0(void *, int, int, void *, int, void *, int, int, int);
extern "C" int func_00560EC0(int n, int *src_a, int *src_b, Result *out) {
    int i;
    if ((unsigned)(n - 1) >= 4) return 0x80000004;
    if (src_a == 0) return 0x80000004;
    if (src_b == 0) return 0x80000004;
    if (out == 0) return 0x80000004;
    func_005616E8(0, 0);
    for (i = 0; i < n; i++) {
        D_00873F40.a[i] = src_a[i];
        D_00873F40.b[i] = src_b[i];
    }
    D_00873F40.count = n;
    if (func_005B19B0(D_00873F00, 0xE, 0, &D_00873F40, 0x240, &D_00873F40, 0x240, 0, 0) != 0) {
        return 0x80000000;
    }
    if (n > 0) {
        Result *src = D_00873F40.results;
        int off = 0;
        i = n;
        do {
            *(Result *)(off + (int)out) = *src;
            off += 0x18;
            src++;
        } while (--i != 0);
    }
    return D_00873F40.status;
}
