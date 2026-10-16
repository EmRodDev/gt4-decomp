/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x2180]; int event; int pad2184; int count; };
extern "C" int func_005B72A8(void);
extern "C" void func_00578480(int);
extern "C" void func_00503630(Obj *p) {
    int enabled = func_005B72A8();
    int count = p->count;
    int first = count < 1;
    if (first) p->count = count + 1;
    if (enabled) __asm__ volatile("ei");
    if (first) func_00578480(p->event);
}
