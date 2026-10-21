/* compiler: ee-gcc2.9-991111 */
extern char D_006D2400[];
extern char D_006D2408[];
extern char D_006D2410[];
extern int func_0057F3C0(double);
extern int dpcmp(double, double);
extern double dpdiv(double, double);
extern double dpmul(double, double);
extern double dpsub(double, double);
extern int func_005AF5E8(int);
extern int func_005B0610(int (*out)(), void *ctx, int *remain, char *fmt, ...);

int func_005AF678(int (*out)(), void *ctx, int *remain, double x)
{
    int sign = 0;
    int exp = 0;
    int n;
    if (*remain == 0)
        return 0;
    if (dpcmp(x, 0.0) < 0) {
        sign = 1;
        x = dpsub(0.0, x);
        out(ctx, remain, 0x2D);
        *remain -= 1;
    }
    if (dpcmp(x, 0.1) < 0) {
        while (dpcmp(x, 0.1) < 0) {
            exp--;
            x = dpmul(x, 10.0);
        }
    } else if (dpcmp(x, 1.0) >= 0) {
        while (dpcmp(x, 1.0) >= 0) {
            exp++;
            x = dpdiv(x, 10.0);
        }
    }
    n = func_005AF5E8(func_0057F3C0(dpmul(x, 1000000.0)));
    sign += func_005B0610(out, ctx, remain, D_006D2400, n);
    if (exp >= 0)
        sign += func_005B0610(out, ctx, remain, D_006D2408, exp);
    else
        sign += func_005B0610(out, ctx, remain, D_006D2410, exp);
    return sign;
}
