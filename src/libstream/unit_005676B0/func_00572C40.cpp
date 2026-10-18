/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern "C" u32 D_008744CC;
static inline u32 log2floor(u32 n) {
    u32 z;
    __asm__("plzcw %0, %1" : "=r"(z) : "r"(n));
    return (z & 31) ^ 31;
}
extern "C" void func_00572C40(int arg0, int arg1) {
    if (arg1 == 0xFFFF && arg0 == 1) {
        D_008744CC = log2floor(0x1F);
    }
}
