/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { char pad[0x2180]; int semaphore, other, count; };
extern "C" void func_00578B10(int);
extern "C" void func_00578500(int);
extern "C" int func_005B72A8();
extern "C" void func_005035E0(State *p) {
    func_00578B10(1000);
    func_00578500(p->semaphore);
    int enabled = func_005B72A8();
    --p->count;
    if (enabled) __asm__ volatile("ei");
}
