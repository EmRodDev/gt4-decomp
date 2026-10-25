struct Table;
extern Table D_006B0F20, D_006B48B8;
extern "C" unsigned short func_004B9528(Table *t, int code) throw();

extern "C" char *func_004B9A80(char *dst, int n, unsigned short *src) {
    int c = *src++;
    char *p = dst;
    int i = 0;
    while (c != 0) {
        if (i >= n) return dst;
        if (c < 0x20) {
            *p = c; p++; i++;
        } else if (c < 0x80) {
            c = func_004B9528(&D_006B0F20, c);
            c = c ? c : '?';
            *p = c; p++; i++;
        } else {
            int code = func_004B9528(&D_006B48B8, c);
            if (code == 0) {
                *p = '?'; p++; i++;
            } else {
                int hi = ((code >> 8) & 0xFF) | 0x80;
                code = (code & 0xFF) | 0x80;
                if (i + 1 >= n) {
                    *p = '?';
                    return dst;
                }
                *p++ = hi; *p++ = code; i += 2;
            }
        }
        c = *src++;
    }
    if (i >= n) return dst;
    *p = 0;
    return dst;
}
