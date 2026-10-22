/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Elem { char data[0x3c]; Elem() asm("func_00105250"); ~Elem() asm("func_00105280"); };
struct Pair { Elem e[2]; int n; Pair() : n(0) {} ~Pair() {} };
struct Big { char pad[0x3c]; Pair a, b; Elem c; };
extern Big D_006184D0;
extern int D_0081EB00;
extern "C" int func_001060A0(int, int, int);
inline void *operator new(unsigned int, void *p) { return p; }
static inline void construct(Pair *const self) {
    Elem *p = self->e;
    int i = 1;
    do { new (p) Elem; p++; } while (--i != -1);
    self->n = 0;
}
extern "C" void func_001075C0(int init, int prio) {
    if (prio == 0xffff && init == 1) {
        construct(&D_006184D0.a);
        construct(&D_006184D0.b);
        new (&D_006184D0.c) Elem;
    }
    if (prio == 0xffff && init == 1) D_0081EB00 = func_001060A0(1, 2, 1);
    if (prio == 0xffff && init == 0) D_006184D0.~Big();
}
