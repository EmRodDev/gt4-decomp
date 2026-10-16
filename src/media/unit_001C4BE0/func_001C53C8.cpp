/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { int enabled, type, value, extra; };
extern "C" int func_005B72A8(void);
static inline void init(Entry *p, int a, int b, int c, int d) {
    p->enabled = a;
    p->type = b;
    p->value = c;
    p->extra = d;
}
extern "C" void func_001C53C8(Entry *p) {
    int irq = func_005B72A8();
    init(p+0, 1, 8, 0, 0);
    init(p+1, 1, 5, 1, 0);
    init(p+2, 1, 6, 1, 0);
    init(p+3, 1, 10, 5, 0);
    init(p+4, 1, 7, 1, 0);
    init(p+5, 0, 15, 0, 0);
    init(p+6, 0, 4, 96, 0);
    init(p+7, 0, 3, 0, 0);
    init(p+8, 0, 0, 1, 0);
    init(p+9, 1, 14, 0, 0);
    init(p+10, 1, 9, 0, 0);
    init(p+11, 0, 17, 0, 0);
    init(p+12, 1, 16, 1, 0);
    init(p+13, 1, 12, 40, 40);
    init(p+14, 1, 11, 0, 0);
    init(p+15, 0, 1, 0, 0);
    init(p+16, 1, 2, 164, 0);
    init(p+17, 1, 13, 0, 0);
    if (irq) __asm__ volatile("ei");
}
