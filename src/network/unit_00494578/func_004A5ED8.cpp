/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64;
extern "C" void func_004A7438(void);

extern "C" float func_004A5ED8(void) {
    u64 v;
    float r;
    func_004A7438();
    __asm__ volatile("qmfc2.i %0, $vf1" : "=r"(v));
    __asm__ volatile("mtc1 %1, %0" : "=f"(r) : "r"(v >> 32));
    return r;
}
