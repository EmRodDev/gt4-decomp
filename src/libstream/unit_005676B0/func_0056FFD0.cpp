extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" int func_005A2F88(const char *);
extern "C" char *func_005A6DC8(const char *, const char *);
extern "C" void func_005A6AB0(char *, char *, int);

extern "C" int func_0056FFD0(char *out, int n) {
    char months[] = "JanFebMarAprMayJunJulAugSepOctNovDec\0";
    char b1[16];
    char b2[32];
    if (out == 0) return -0x200;
    const char *date = "Sep 22 2004";
    const char *time = "01:44:37";
    func_0057DA20(b1, "%.3s", date);
    int m = (func_005A6DC8(months, b1) - months) / 3 + 1;
    func_0057DA20(b2, "%.2d.%.2d.%.4s.%.2s.%.2s.%.2s", m, func_005A2F88(date + 4), date + 7, time, time + 3, time + 6);
    func_005A6AB0(out, b2, n);
    return 0;
}
