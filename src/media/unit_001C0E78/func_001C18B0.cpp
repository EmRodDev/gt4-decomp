/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" void func_001C18B0(u128 *dst, u128 *src, int width, int height, int value) {
    char *end = (char *)src + ((width + 15) & ~15) * height;
    u128 threshold, ones;
    __asm__ volatile("pextlb %0, %1, %1" : "=r"(threshold) : "r"(value));
    __asm__ volatile("pcpyh %0, %1" : "=r"(threshold) : "r"(threshold));
    __asm__ volatile("pcpyld %0, %1, %1" : "=r"(threshold) : "r"(threshold));
    __asm__ volatile("pceqb %0, $0, $0" : "=r"(ones));
    __asm__ volatile("psubb %0, $0, %1" : "=r"(ones) : "r"(ones));
    while ((char *)src != end) {
        __asm__ volatile("pref 0x0, 0x40(%0)" : : "r"(src));
        u128 v = *src++;
        __asm__ volatile("psubub %0, %1, %2" : "=r"(v) : "r"(v), "r"(threshold));
        __asm__ volatile("pceqb %0, %1, $0" : "=r"(v) : "r"(v));
        __asm__ volatile("paddb %0, %1, %2" : "=r"(v) : "r"(v), "r"(ones));
        *dst++ = v;
    }
}
