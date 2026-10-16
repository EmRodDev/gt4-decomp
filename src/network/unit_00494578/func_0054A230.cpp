/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0054A168() throw();
extern "C" int func_005782E8(int,int);
extern "C" void func_005783A0(int);
extern "C" void func_00578500(int);
extern "C" int func_005AD980(int,void *,int);
extern "C" int func_005AD9A0(int,int);
extern "C" int func_005B72A8();
extern int D_0064C3F4;
extern char D_0064C3F8[];
struct Flag { int v; };
extern volatile Flag D_0064C3EC;
extern char D_0054A1D8[];
static inline int active(volatile Flag *const p) { return p->v; }
extern "C" void func_0054A230() {
    int *count = &D_0064C3F4;
    *count = 0;
    { int *q = (int *)D_0064C3F8; *q = func_005782E8(0,255); }
    int saved = func_005AD980(2,D_0054A1D8,0);
    while (active(&D_0064C3EC)) {
        func_00578500(*(int *)D_0064C3F8);
        int enabled = func_005B72A8();
        --*count;
        if (enabled) __asm__ volatile("ei");
        func_0054A168();
    }
    int *q = (int *)D_0064C3F8;
    func_00578500(*q);
    int enabled = func_005B72A8();
    --D_0064C3F4;
    if (enabled) __asm__ volatile("ei");
    func_005AD9A0(2,saved);
    func_005783A0(*q);
}
