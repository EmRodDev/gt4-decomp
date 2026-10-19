typedef float f32;

/* which: slot selector, passed through from the caller in a0. */
extern "C" void func_0049B4C0(unsigned int which, f32 x, f32 y, f32 z, f32 w);

extern "C" void func_0049B478(unsigned int which, f32 fparg0) {
    return func_0049B4C0(which, fparg0, fparg0, fparg0, 1.0f);
}
