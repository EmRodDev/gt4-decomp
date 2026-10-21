/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0057F260(const char *) throw();
extern "C" void func_00577BD0(char *, const char *);
extern "C" void func_00577F80(void);
extern "C" int func_0058B320(const char *, int, int, int, int, void *);
extern "C" int func_00576E10(const char *path, int a, int b, int c, int d, void *out) {
    char scratch[16];
    unsigned int n = func_0057F260(path);
    if (!out) out = scratch;
    char *buf = (char *)__builtin_alloca(n + 1);
    func_00577BD0(buf, path);
    int r;
    while ((r = func_0058B320(buf, a, b, c, d, out)) < 0) func_00577F80();
    return r;
}
