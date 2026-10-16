/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x26c]; int a,b; };
extern "C" int func_005B72A8(void);
extern "C" void func_001C4CD0(Obj *p, int a, int b) {
    int enabled = func_005B72A8();
    p->a = a;
    p->b = b;
    if (enabled) __asm__ volatile("ei");
}
