/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" void func_001C1CA8(char *dst, u128 *src, int width, int height) {
    width = (((((width + 15) & ~15) * height) + 127) & ~127);
    char *p = dst;
    dst += width;
    while (p != dst) {
        __asm__ volatile("pref 0x0, 0x40(%0)" : : "r"(src));
        u128 v = *src++;
        __asm__("psubb %0, $0, %1" : "=r"(v) : "r"(v));
        *(u128 *)p = v;
        p += 16;
    }
}
