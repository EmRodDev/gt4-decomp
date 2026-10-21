/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" unsigned char *func_0057A090(void *unused, unsigned char *p, unsigned int *out) {
    int extended = p[0] & 0x80;
    if (!extended) {
        *out = p[0];
        return p + 1;
    }
    if (!(p[0] & 0x40)) {
        *out = ((p[0] << 8) | p[1]) & 0x7fff;
        return p + 2;
    }
    unsigned int high = (p[0] << 24) | p[3];
    unsigned int low = (p[2] << 8) | (p[1] << 16);
    *out = (high | low) & 0x3fffffff;
    return p + 4;
}
