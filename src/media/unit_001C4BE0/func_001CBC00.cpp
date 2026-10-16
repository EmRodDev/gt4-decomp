/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001CBC00(signed char *p) {
    for (;;) {
        int c = p[0];
        int shifted = c << 8;
        if (!c) return;
        if ((unsigned int)((c ^ -0x60) - 0x21) < 0x3c) {
        int d = p[1];
        if (!d) return;
        int w = shifted | (d & 255);
        c = w & 255;
        int hi = (w & 0x3f00) * 2;
        int offset = hi + 0x1f82;
        if (c < 0x9f) offset = hi + 0x1ee0 + (c < 0x7f);
        c = (offset + c) | 0x8080;
        p[1] = c;
        p[0] = c >> 8;
        p += 2;
        } else {
            p++;
        }
    }
}
