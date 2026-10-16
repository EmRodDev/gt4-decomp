/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0xc]; int refs;
    char pad10[0x264];
    int a274, a278, a27c, a280, a284, a288, a28c, a290, a294;
};
extern "C" int func_005B72A8(void);
extern "C" void func_001C58F8(void);
extern "C" void func_001C50A8(Obj *);
extern "C" void func_001C5958(Obj *);
extern "C" void func_001C4BE0(Obj *p) {
    int enabled = func_005B72A8();
    int n = p->refs + 1;
    p->refs = n;
    int first = n == 1;
    if (enabled) __asm__ volatile("ei");
    if (first) {
        func_001C58F8();
        func_001C50A8(p);
        p->a274 = 0;
        p->a278 = 0;
        p->a27c = 0;
        p->a280 = 0;
        p->a284 = -1;
        p->a288 = 0;
        p->a28c = 0;
        p->a290 = 0;
        p->a294 = 0;
        func_001C5958(p);
    }
}
