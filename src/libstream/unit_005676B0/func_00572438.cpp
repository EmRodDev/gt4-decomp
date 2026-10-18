/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern "C" u32 D_008744CC;
static inline u32 ceilLog2(u32 n) {
    u32 z;
    __asm__("plzcw %0, %1" : "=r"(z) : "r"(n - 1));
    return (z & 31) ^ 31;
}
extern "C" u32 func_00572438(int arg0, u32 arg1) {
    u32 v = ceilLog2(arg1);
    u32 base = D_008744CC;
    u32 d = v < base ? 0 : v - base;
    return d >= 0x10 ? 0xF : d;
}
