/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" char *func_005316F8(unsigned) throw();
extern char *D_008686C8[64];
static inline char *get(char **p) {
    char *r = *p;
    if (!r) {
        char *v = func_005316F8(0x1a0);
        *p = v;
        r = v;
    }
    return r;
}
extern "C" char *func_00535970(unsigned n) {
    if (n < 64) return get(&D_008686C8[n]);
    return 0;
}
