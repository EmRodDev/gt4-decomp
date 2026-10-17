/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Callback { void (*fn)(void); int arg; };
extern volatile int D_00654A38;
extern int D_00873EC0;
extern "C" void func_0055EB50(void);
extern "C" int func_00578B50(unsigned mode, int c);
extern "C" unsigned char *func_00578610(int);
extern "C" int func_00575098(Callback *, unsigned char *);
extern "C" void func_005788B8(int);
extern "C" void func_0055EC60(void) {
    D_00654A38 = 1;
    Callback cb;
    cb.fn = func_0055EB50;
    cb.arg = 0;
    int h = func_00575098(&cb, func_00578610(func_00578B50(5, 0)));
    D_00873EC0 = h;
    func_005788B8(h);
}
