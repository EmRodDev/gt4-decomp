/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0057F260(const char *);
extern "C" char *func_005A5DC8(char *, const char *);
extern "C" void func_00576E10(char *, int, int, int, int, int);
extern "C" void func_00576FE8(const char *dir, const char *name, const char *ext, int a, int b, int c, int d, int e) {
    int len = func_0057F260(name) + 1;
    if (dir != 0) len += func_0057F260(dir);
    if (ext != 0) len += func_0057F260(ext);
    char *buf = (char *)__builtin_alloca((len + 15) & ~15);
    buf[0] = 0;
    if (dir != 0) func_005A5DC8(buf, dir);
    func_005A5DC8(buf, name);
    if (ext != 0) func_005A5DC8(buf, ext);
    func_00576E10(buf, a, b, c, d, e);
}
