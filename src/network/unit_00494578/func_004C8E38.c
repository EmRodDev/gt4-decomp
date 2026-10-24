unsigned short *func_004C8E38(unsigned short *dst, unsigned short *src, int n) {
    if (dst < src) {
        while (n-- > 0)
            *dst++ = *src++;
    } else if (src < dst) {
        dst += n - 1;
        src += n - 1;
        while (n-- > 0)
            *dst-- = *src--;
    }
    return dst;
}
