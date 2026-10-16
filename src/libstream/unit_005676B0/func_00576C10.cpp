typedef int s32;
typedef unsigned int u32;
extern "C" s32 func_0057F260(const char *s);
extern "C" void func_005A5DC8(char *dst, const char *src);
extern "C" int func_00576B78(char *buf, s32 arg1, s32 arg2);

extern "C" void func_00576C10(const char *arg0, const char *arg1, const char *arg2, s32 arg3, s32 arg4) {
    u32 n = func_0057F260(arg1) + 1;
    if (arg0 != 0) {
        n += func_0057F260(arg0);
    }
    if (arg2 != 0) {
        n += func_0057F260(arg2);
    }
    char *buf = (char *)__builtin_alloca(n);
    buf[0] = 0;
    if (arg0 != 0) {
        func_005A5DC8(buf, arg0);
    }
    func_005A5DC8(buf, arg1);
    if (arg2 != 0) {
        func_005A5DC8(buf, arg2);
    }
    func_00576B78(buf, arg3, arg4);
}
