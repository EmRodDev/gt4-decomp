typedef float f32;

extern "C" void *func_0044F4C0(void);
extern "C" f32 func_0044F9B0(void *arg0);

extern "C" f32 func_0038CB48(void) {
    void *p = func_0044F4C0();
    if (p) {
        return func_0044F9B0(p) + 0x1.14E0D0p+0f;
    }
    return 0x1.14E0D0p+0f;
}
