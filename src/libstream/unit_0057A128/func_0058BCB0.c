/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u128 __attribute__((mode(TI)));
u128 *func_0058BCB0(unsigned addr, const u128 *src, int n) {
    u128 *dst = (u128 *)(addr | 0x30000000);
    if (n > 0) {
        do {
            u128 q = *src;
            --n;
            ++src;
            *dst = q;
            ++dst;
        } while (n != 0);
    }
    return dst;
}
