typedef unsigned int u32;
extern "C" void func_00544830(u32 *, int) throw();
extern "C" int func_00544870(u32 *) throw();
extern "C" int func_00544880(u32 *) throw();
extern "C" int func_00544950(u32 *, u32) throw();
extern "C" void func_00544978(u32 *, u32) throw();
extern "C" void func_005449C8(u32 *, u32) throw();
extern "C" void func_00544EC8(u32 *, u32 *, u32 *, u32 *) throw();
extern "C" void func_005454F0(u32 *, u32) throw();
extern "C" u32 func_00545A54(u32 *);
extern "C" int func_00545BF0(u32 *, u32 *);
extern "C" void func_00545C58(u32 *, u32);
extern "C" void func_00545D7C(u32 *, u32);
extern "C" void func_00545EB8(u32 *, u32 *);
extern "C" void func_00545F30(u32 *, u32 *, u32);
extern "C" void func_00545FC0(u32 *, u32 *);
extern "C" void func_00546038(u32 *, u32 *, u32);
extern "C" void func_005460C8(u32 *, u32 *);
extern "C" void func_005464B0(u32 *, u32 *, u32 *);
extern "C" void func_005A2E98(const char *, int, const char *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void func_00545558(u32 *dst, u32 *base, u32 *exponent, u32 *modulus) {
    u32 t[32], a[32], r[32], x[32];
    u32 nbits, mask, ebits, i, j, top;
    nbits = func_00545A54(modulus);
    ebits = func_00545A54(exponent);
    if (func_00544880(modulus)) {
        func_005A2E98("/usr/people/ikiuo/work/rtime/rtime-040920/rt_crypt/src/LargeInt.c", 0x3E4, "0");
        func_005A4724(dst, modulus, 0x80);
        return;
    }
    if (func_00544870(modulus)) {
        func_005A2E98("/usr/people/ikiuo/work/rtime/rtime-040920/rt_crypt/src/LargeInt.c", 0x3EE, "0");
        func_00544EC8(dst, base, exponent, modulus);
        return;
    }
    j = 0;
    func_00544830(r, 0);
    i = 0;
    func_00544830(x, 1);
    while (i + j < nbits) {
        if (func_00544950(x, j)) {
            if (j) {
                i += j;
                func_00545C58(x, j);
                j = 0;
            }
            func_00544978(r, i);
            func_00545F30(x, modulus, nbits - i);
        } else {
            j++;
        }
    }
    func_005A4724(a, base, 0x80);
    func_00545D7C(a, nbits);
    j = 0;
    mask = 1;
    func_005460C8(a, modulus);
    func_00544830(x, 1);
    func_00545D7C(x, nbits);
    func_005460C8(x, modulus);
    for (i = 0; i < ebits; i++) {
        if (i) {
            top = nbits - 1;
            func_005464B0(t, a, a);
            func_005A4724(a, t, 0x80);
            func_005454F0(a, nbits);
            func_005464B0(a, a, r);
            func_005454F0(a, nbits);
            func_005464B0(a, a, modulus);
            if (func_00544950(a, top) || func_00544950(t, top)) {
                func_00545C58(a, nbits);
                func_00545C58(t, nbits);
                func_00545F30(a, t, nbits);
                func_005449C8(a, 1);
            } else {
                func_00545C58(a, nbits);
                func_00545C58(t, nbits);
                func_00545F30(a, t, nbits);
            }
            if (func_00545BF0(a, modulus)) func_00546038(a, modulus, nbits);
            mask <<= 1;
            if (mask == 0) {
                j++;
                mask = 1;
            }
        }
        u32 *w = &exponent[j];
        if (mask & *w) {
            top = nbits - 1;
            func_005464B0(t, x, a);
            func_005A4724(x, t, 0x80);
            func_005454F0(x, nbits);
            func_005464B0(x, x, r);
            func_005454F0(x, nbits);
            func_005464B0(x, x, modulus);
            if (func_00544950(x, top) || func_00544950(t, top)) {
                func_00545C58(x, nbits);
                func_00545C58(t, nbits);
                func_00545F30(x, t, nbits);
                func_005449C8(x, 1);
            } else {
                func_00545C58(x, nbits);
                func_00545C58(t, nbits);
                func_00545F30(x, t, nbits);
            }
            if (func_00545BF0(x, modulus)) func_00546038(x, modulus, nbits);
        }
    }
    func_005A4724(t, x, 0x80);
    func_005454F0(x, nbits);
    func_005464B0(x, x, r);
    func_005454F0(x, nbits);
    func_005464B0(x, x, modulus);
    func_00545EB8(x, t);
    func_00545C58(x, nbits);
    if (func_00545BF0(x, modulus)) func_00545FC0(x, modulus);
    func_005A4724(dst, x, 0x80);
}
