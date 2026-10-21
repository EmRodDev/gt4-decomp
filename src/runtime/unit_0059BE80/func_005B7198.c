/* compiler: ee-gcc2.9-991111 */
extern void func_005B0750(const char *, ...);
extern void func_005B1028(int);
extern void func_005B11C8(void);
extern int func_005B6FC8(const char *, int);
extern char D_006D28C0[];
extern char D_006D28D0[];
int func_005B7198(const char *img) {
    char buf[80];
    const char *prefix = D_006D28C0;
    char *out;
    const char *p = img;
    const char *base;
    if (*p) {
        base = img - 11;
        do { p++; } while (*p);
    } else {
        base = img - 11;
    }
    if ((unsigned int)(p - base) > 80) {
        func_005B0750(D_006D28D0, img);
        return 0;
    }
    func_005B1028(0);
    func_005B11C8();
    out = buf;
    while (*prefix) *out++ = *prefix++;
    while (*img) *out++ = *img++;
    *out = 0;
    return func_005B6FC8(buf, 0);
}
