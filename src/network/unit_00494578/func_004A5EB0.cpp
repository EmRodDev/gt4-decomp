/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004A7438(void);

extern "C" float func_004A5EB0(void) {
    float r;
    func_004A7438();
    __asm__ volatile("qmfc2.i %0, $vf1" : "=r"(r));
    return r;
}
