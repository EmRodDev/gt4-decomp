/* compiler: ee-gcc2.9-991111 */
int func_00586AE0(void *);
/* Preserve full registers, as in the neighbouring SDK dispatcher. */
int func_005867F0(char *, unsigned int)
    __attribute__((register_precision(s0, 128),
                   register_precision(s1, 128),
                   register_precision(s0, 128)));
int func_005867F0(char *p, unsigned int size) {
    unsigned int n = size >> 2;
    while ((int)n > 0) {
        if (func_00586AE0(p) < 0) return 0x81059039;
        n -= 8;
        if (!(*(unsigned short *)(p+0x16) & 2)) return 0x81059037;
        p += 0x20;
    }
    return 0;
}
