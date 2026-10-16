/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { long ticks; int a, b, c, d; };
extern State D_0086CB40;
extern "C" int func_005B72A8(void);
extern "C" float __floatdisf(long);
extern "C" float func_00548228(int *a, int *b, int *c) {
    int enabled = func_005B72A8();
    if (a) *a = D_0086CB40.a;
    if (b) *b = D_0086CB40.c;
    if (c) *c = D_0086CB40.d;
    float result = __floatdisf(D_0086CB40.ticks) / 1000000.0f;
    if (enabled) __asm__ volatile("ei");
    return result;
}
