/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char data[108]; };
struct State { void *p; int count, index; Obj entries[4]; };
extern "C" void func_00549808(Obj *) throw();
extern "C" void func_005499E0(Obj *) throw();
extern "C" int func_00562150(void *);
extern "C" int func_005B72A8();
static inline const int &minimum(const int &a, const int &b) { return b < a ? b : a; }
extern "C" int func_00549B48(State *p) {
    int n = 4;
    int old = p->count;
    int size = func_00562150(p->p);
    int count = minimum(n, size);
    if (old != count) {
        int enabled = func_005B72A8();
        p->index = 0;
        p->count = count;
        for (int i = 0; i < 4; ++i) func_00549808(&p->entries[i]);
        if (enabled) __asm__ volatile("ei");
    }
    func_005499E0(&p->entries[p->index]);
    if (++p->index >= p->count) { p->index = 0; return 1; }
    return 0;
}
