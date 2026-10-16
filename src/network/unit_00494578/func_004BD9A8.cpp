/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
extern "C" int func_004BD9A8(u8 *p, u8 *q, unsigned lp, unsigned lq, unsigned n) {
    u8 *pe;
    u8 *qe;
    if (n == 0) return 0;
    if (lp == 0 || lq == 0) {
        if (lp == lq) return 0;
        return lp < lq ? -1 : 1;
    }
    pe = p + lp - 1;
    qe = q + lq - 1;
    if (p < pe && q < qe) {
        do {
            if (*pe != *qe) return *pe - *qe;
            pe--;
            qe--;
            n--;
        } while (p < pe && q < qe && n != 0);
    }
    if (n != 0) {
        if (*pe != *qe) return *pe - *qe;
    }
    return 0;
}
