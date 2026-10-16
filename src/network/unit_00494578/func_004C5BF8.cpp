/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
extern "C" int func_004C5958(u16 *, int, void *) throw();
extern "C" void func_004C5BF8(u16 *src, int n, u8 *out) {
    char buf[32];
    int j = n - 1;
    int i;
    *out = 0;
    i = 0;
    while (i < n) {
        u16 *p = &src[i++];
        if ((u16)(*p - 0x30) < 10) {
            out[j--] = (u8)*p;
        } else if ((u16)(*p - 0xA3B0) < 10) {
            out[j--] = ((u8)*p & 15) + 0x30;
        } else break;
    }
    if (*out != 0) {
        out[n] = 0;
        return;
    }
    func_004C5958(src, n, out);
    int last = 0;
    for (i = 16; i >= 0; i--) {
        buf[i] = out[i];
        if (out[i] && !last) last = i;
    }
    if (last >= 0) {
        u8 *dst = out;
        do {
            char c = buf[last];
            if (c == 0 || c == ' ') *dst = '0';
            else if (c == '!') *dst = '1';
            else *dst = buf[last];
            dst++;
        } while (--last >= 0);
    }
}
