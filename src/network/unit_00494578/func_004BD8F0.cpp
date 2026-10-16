/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
extern "C" int func_004BD8F0(const u8 *p, const u8 *q, unsigned lp, unsigned lq) {
    if (lp == 0 || lq == 0) {
        if (lp == lq) return 0;
        return lp < lq ? -1 : 1;
    }
    const u8 *pe = p + lp - 1;
    const u8 *qe = q + lq - 1;
    while (p < pe && q < qe) {
        if (*pe != *qe) return *pe - *qe;
        --pe;
        --qe;
    }
    if (*pe != *qe) return *pe - *qe;
    if (lp == lq) return 0;
    return lp > lq ? 1 : -1;
}
