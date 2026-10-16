/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" void func_001C1C50(u128 *dst, u128 *a, u128 *b, int width, int height) {
    width = (((((width + 15) & ~15) * height) + 127) & ~127);
    u128 *p = dst;
    dst = (u128 *)((char *)dst + width);
    while (p != dst) {
        u128 x = *a++;
        u128 y = *b++;
        __asm__("pxor %0, %1, %2" : "=r"(x) : "r"(x), "r"(y));
        *p++ = x;
    }
}
