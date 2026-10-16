/* compiler: ee-gcc2.96-no-strict-aliasing */
extern unsigned short D_006B9970[];
extern "C" int func_004C4F38(unsigned c) {
    c &= 0xFFFF;
    const unsigned short *p;
    unsigned short v;
    if ((unsigned short)(c + 0x5C50) < 10) goto digit;
    if ((unsigned short)(c + 0xFFD0) < 10) goto digit;
    p = D_006B9970;
    goto search;
digit:
    return 1;
    do {
search:
        v = *p++;
    } while (c < v);
    return c == v ? 2 : 0;
}
