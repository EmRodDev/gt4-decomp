/* compiler: ee-gcc2.9-as296 */
extern int func_00594470(const char *, const char *, unsigned);
extern void func_005A30D8(char *, int);
extern char *func_005A5EF4(const char *, int);
extern char D_006CC068[];
int func_00571BE0(const char *src, char *dst, int size) {
    int special = 0;
    int i = 0;
    const char *p;
    int cmp;
    func_005A30D8(dst,size);
    if (!src) return -101;
    if (!dst) return -101;
    cmp = func_00594470(src,D_006CC068,7);
    if (cmp==0) {
        size--;
        p = src;
        for (;;) {
            p = func_005A5EF4(p,'.');
            if (!p) break;
            p++;
            i++;
        }
        special = i==5;
    } else {
        size--;
    }
    if (special) {
        p = func_005A5EF4(src,'.');
        p++;
        p = func_005A5EF4(p,'.');
        p++;
        for (i=0; i<size && p[i] && p[i]!='.'; i++) dst[i]=p[i];
        dst[i]=0;
    } else {
        for (i=0; i<size && src[i]; i++) dst[i]=src[i];
        dst[i]=0;
    }
    return 0;
}
