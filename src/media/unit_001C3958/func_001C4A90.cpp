/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { int dirty, pad, a, b; };
extern "C" int func_005B72A8(void);
extern "C" void func_001C4A90(Entry *p, int a, int b) {
    int enabled = func_005B72A8();
    if (p->a != a) {
        p->a = a;
        p->dirty = 1;
    }
    if (p->b != b) {
        p->b = b;
        p->dirty = 1;
    }
    if (enabled) __asm__ volatile("ei");
}
